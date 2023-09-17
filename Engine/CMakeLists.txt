add_library(${PROJECT_NAME})
add_library(ne::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include(header_list.cmake)

#Fetch content to get sfml from source & build a static library
include(FetchContent)

FETCHCONTENT_DECLARE(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG 11b73743c42cf7ecd7c596ba83fdbf1150ffa96c # release-2.6.0
)

FetchContent_MakeAvailable(sfml)

target_link_libraries(${PROJECT_NAME} PUBLIC
        sfml-graphics
        )

target_compile_definitions(${PROJECT_NAME} PUBLIC
        $<$<CONFIG:Debug>:NE_DEBUG>
        $<$<BOOL:${NE_PCH}>:NE_PCH>
)

target_include_directories(${PROJECT_NAME} PUBLIC
        include
        "${CMAKE_CURRENT_BINARY_DIR}/include"
        )

target_include_directories(${PROJECT_NAME} PRIVATE
        .
        )

target_compile_features(${PROJECT_NAME} PUBLIC
        cxx_std_20
        )

add_subdirectory(Source)


target_sources(${PROJECT_NAME} PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
        ${header_list}
        )

if(NE_PCH)
    target_precompile_headers(${PROJECT_NAME} PRIVATE
            <atomic>
            <mutex>
            <string>
            <iostream>
            <vector>
            )
endif()