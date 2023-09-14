cmake_minimum_required(VERSION 3.25)
project(NamtarEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BUILD_SHARED_LIBS OFF)

#Fetch content to get sfml from source & build a static library

include(FetchContent)

#Add the executables
add_executable(NamtarEngine main.cpp Core/Source/Engine.cpp Core/Header/Engine.h Core/Source/IDManager.cpp Core/Header/IDManager.h Core/Source/GameObject.cpp Core/Header/GameObject.h Core/Header/Component.h Core/Header/Behaviour.h Core/Header/MonoInstance.h Core/CoreComponents/SpriteRenderer.h Core/CoreComponents/Collision2DHandler.cpp Core/CoreComponents/Collision2DHandler.h Core/CoreComponents/Collider2D.h SpaceForce/Enemy.cpp SpaceForce/Enemy.h Core/Source/InputManager.cpp Core/Header/InputManager.h SpaceForce/PlayerMovement.cpp SpaceForce/PlayerMovement.h SpaceForce/Health.cpp SpaceForce/Health.h SpaceForce/PlayerHealth.cpp SpaceForce/PlayerHealth.h SpaceForce/EnemyTemplate.cpp SpaceForce/EnemyTemplate.h SpaceForce/GameManager.cpp SpaceForce/GameManager.h Core/CoreComponents/Collider2D.cpp Core/Header/Logger.cpp Core/Header/Logger.h Core/CoreComponents/Helper/json.hpp)

FETCHCONTENT_DECLARE(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG 11b73743c42cf7ecd7c596ba83fdbf1150ffa96c # release-2.6.0
)

FetchContent_MakeAvailable(sfml)

target_link_libraries(NamtarEngine PRIVATE sfml-graphics)

target_sources(NamtarEngine PRIVATE main.cpp)

#Compiler flags
if(CMAKE_CXX_COMPILER_ID STREQUAL Clang OR CMAKE_CXX_COMPILER_ID STREQUAL GNU)
    target_compile_options(NamtarEngine PRIVATE -Wall -Wextra -Wpedantic)
endif()