project(ne-editor)

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE
        ne::NamtarEngine # core engine
        )

target_sources(${PROJECT_NAME} PRIVATE
        main.cpp
        )

if ("${PROJECT_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(is_root_project ON)
endif ()