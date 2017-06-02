if(EXISTS ${PROJECT_SOURCE_DIR}/Dependencies/cxx-log/CMakeLists.txt)

    if(NOT TARGET cxx-log)
    
        # Include cxx-log
        add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/cxx-log)

        # Include sources
        include_directories(${PROJECT_SOURCE_DIR}/Dependencies/cxx-log/Sources)
        
    endif()

endif()
