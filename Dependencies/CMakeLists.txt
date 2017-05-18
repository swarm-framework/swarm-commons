
# Enable ExternalProject CMake module
include(ExternalProject)

# cxxlog version
set(cxx-logs-VERSION master)

# Download and install swarm commons
ExternalProject_Add(
    cxx-logs
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/volatile
    GIT_REPOSITORY git@github.com:lib-cxx/cxx-log.git
    GIT_TAG "${swarm-commons-VERSION}"
    INSTALL_COMMAND ""
)

# Include current and cxxlog Sources to include search directories
set(cxx-logs-INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/volatile/src/cxx-logs/Sources PARENT_SCOPE)
