# Include cxx-log
find_dependencies(cxx-log)

# Create targets
add_library(swarm-commons
    Sources/swarm/exception/SwarmException.cxx Sources/swarm/exception/SwarmException.hxx
    Sources/swarm/network/IPAddress.cxx Sources/swarm/network/IPAddress.hxx
    Sources/swarm/http/MediaType.cxx Sources/swarm/http/MediaType.hxx
)

# Properties of targets

# Add definitions for targets
# Values:
#   * Debug: -DSWAM_COMMON_DEBUG=1
#   * Release: -DSWAM_COMMON_DEBUG=0
#   * other: -DSWAM_COMMON_DEBUG=0
target_compile_definitions(swarm-commons  PUBLIC "SWAM_COMMON_DEBUG=$<CONFIG:Debug>")

# Generate headers:
include(GenerateExportHeader)
generate_export_header(swarm-commons)

# Global includes. Used by all targets
target_include_directories(
    swarm-commons 
    
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Sources>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
        
    PRIVATE
        ${cxx-log_INCLUDE_DIR}
)

# Installation (https://github.com/forexample/package-example)
set(config_install_dir "lib/cmake/${PROJECT_NAME}")
set(include_install_dir "include")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

# Configuration
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

# Include module with fuction 'write_basic_package_version_file'
include(CMakePackageConfigHelpers)

# Configure '<PROJECT-NAME>ConfigVersion.cmake'
# Note: PROJECT_VERSION is used as a VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Configure '<PROJECT-NAME>Config.cmake'
# Use variables:
#   * targets_export_name
#   * PROJECT_NAME
configure_package_config_file(
    "cmake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

# Targets:
#   * <prefix>/lib/${target}.a
#   * header location after install: <prefix>/include/*.hxx
#   * headers can be included by C++ code `#include <project/*.hxx>`
install(
    TARGETS swarm-commons
    EXPORT "${targets_export_name}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "${include_install_dir}"
)

# Headers:
#   * Sources/${target}/*.hxx -> <prefix>/include/${target}/*.hxx
install(
    DIRECTORY "Sources/swarm"
    DESTINATION "${include_install_dir}"
    FILES_MATCHING PATTERN "*.hxx"
)

# Export headers:
#   * ${CMAKE_CURRENT_BINARY_DIR}/${target}_export.h -> <prefix>/include/${target}_export.h
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/swarm-commons_export.h"
    DESTINATION "${include_install_dir}"
)

# Config
#   * <prefix>/lib/cmake/${project}/${Target}Config.cmake
install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

# Config
#   * <prefix>/lib/cmake/${project}/${Target}Targets.cmake
install(
    EXPORT "${targets_export_name}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)