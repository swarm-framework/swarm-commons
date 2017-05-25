cmake_minimum_required(VERSION 3.0.0)

# Define project name
project(swarm-commons)

# enable tests
enable_testing()

# Include CMakeLists.txt
include(Config/CMakeLists.txt)

# Include dependencies
include(Dependencies/CMakeLists.txt)

# Include sources
add_subdirectory(Sources)

# Include test
add_subdirectory(Tests)
