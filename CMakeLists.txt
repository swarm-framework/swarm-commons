# Set minimum version of CMake.
cmake_minimum_required(VERSION 3.0)

# Set variables:
#   * PROJECT_NAME
#   * PROJECT_VERSION
project(swarm-commons VERSION 0.1.0)

# include config
include(Config/config.cmake)

# Include cxx-log
find_dependencies(cxx-log)

# Create targets
add_library(${PROJECT_NAME}
    Sources/swarm/exception/SwarmException.cxx Sources/swarm/exception/SwarmException.hxx
    Sources/swarm/network/IPAddress.cxx Sources/swarm/network/IPAddress.hxx
    Sources/swarm/http/MediaType.cxx Sources/swarm/http/MediaType.hxx
)

# Global includes. Used by all targets
target_include_directories(
    ${PROJECT_NAME} 
    
    PRIVATE
        ${cxx-log_INCLUDE_DIR}
)

# Include sources
include(Config/build.cmake)

# Include test
add_subdirectory(Tests)
