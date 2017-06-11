# Set minimum version of CMake.
cmake_minimum_required(VERSION 3.0)

# Set variables:
#   * PROJECT_NAME
#   * PROJECT_VERSION
project(swarm-commons VERSION 0.1.0)

# include config
include(Config/config.cmake)

# Include sources
include(Config/build.cmake)

# Include test
add_subdirectory(Tests)
