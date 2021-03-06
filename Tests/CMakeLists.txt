# Set catch version
set(CATCH_VERSION v1.9.3)

# Set download file
set(CATCH_FILE_PATH ${PROJECT_SOURCE_DIR}/Dependencies/volatile/${CATCH_VERSION}/catch/catch.hxx)

# Test if file does not exist
if (NOT "${CATCH_FILE_PATH}")
    # Download Catch Unit test
    file(DOWNLOAD "https://github.com/philsquared/Catch/releases/download/${CATCH_VERSION}/catch.hpp" "${CATCH_FILE_PATH}")
endif()

# Create create executable
add_executable(${PROJECT_NAME}Tests 
    main.cxx
    exception/SwarmExceptionTest.cxx
)
target_include_directories(
    ${PROJECT_NAME}Tests 
    
    PRIVATE
        ${cxx-log_INCLUDE_DIR}
    
    PUBLIC
        ../Sources  # Project sources
        ${PROJECT_SOURCE_DIR}/Dependencies/volatile/${CATCH_VERSION} # catch directory
)
target_link_libraries(${PROJECT_NAME}Tests
    ${PROJECT_NAME}
)
# Register test
add_test(${PROJECT_NAME}Tests ${PROJECT_NAME}Tests)
