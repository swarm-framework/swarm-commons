
# Enable ExternalProject CMake module
include(ExternalProject)

if(NOT DEFINED swarm-commons)

    # Include cxx-log
    add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/cxx-log)

    # Include sources
    include_directories(${PROJECT_SOURCE_DIR}/Dependencies/cxx-log/Sources)

endif()
