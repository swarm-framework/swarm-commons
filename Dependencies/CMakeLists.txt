
# Enable ExternalProject CMake module
include(ExternalProject)

if (NOT DEFINED VOLATILE_PACKAGE_DIRECTORY)
    set(VOLATILE_PACKAGE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/volatile)
endif()

if(NOT DEFINED cxx-logs-LIB)

    # cxxlog version
    set(cxx-logs-VERSION master)

    # Download and install swarm commons
    ExternalProject_Add(
        cxx-logs
        PREFIX ${VOLATILE_PACKAGE_DIRECTORY}
        GIT_REPOSITORY git@github.com:lib-cxx/cxx-log.git
        GIT_TAG "${swarm-commons-VERSION}"
        INSTALL_COMMAND ""
    )

    # Include current and cxxlog Sources to include search directories
    set(cxx-logs-INCLUDE ${VOLATILE_PACKAGE_DIRECTORY}/src/cxx-logs/Sources PARENT_SCOPE)
    set(cxx-logs-LIB ${VOLATILE_PACKAGE_DIRECTORY}/volatile/src/cxx-logs-build/Sources/libcxxlog.a PARENT_SCOPE)

endif()
