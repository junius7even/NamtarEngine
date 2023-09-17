cmake_minimum_required(VERSION 3.25)
project(NamtarEngine VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BUILD_SHARED_LIBS OFF)

set(is_root_project OFF)

option(NE_EDITOR "Start editor" ON)
option(NE_PCH "Use PCH for namtar-engine" ON)
option(NE_BUILD_EXAMPLE "Build namtar-engine example" ${is_root_project})
option(NE_BUILD_SPACEFORCE "Build namtar-engine space force" ${is_root_project})

add_subdirectory(Engine)

add_subdirectory(Editor)