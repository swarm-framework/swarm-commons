
# Include current and cxxlog Sources to include search directories
include_directories(.)

# Add sources files
set (${PROJECT_NAME}_SOURCES
    swarm/exception/SwarmException.cxx swarm/exception/SwarmException.hxx
    swarm/network/IPAddress.cxx swarm/network/IPAddress.hxx
    swarm/http/MediaType.cxx swarm/http/MediaType.hxx
)

# Create library
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})   
target_link_libraries(${PROJECT_NAME}
    cxxlog
)

# Install exec in bin directory
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
