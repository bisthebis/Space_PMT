cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 14)

project(Space_PMT)

include_directories(lib)

add_executable(${PROJECT_NAME}
    main.cpp
    fight.h fight.cpp
    )

add_subdirectory(lib)

target_link_libraries(${PROJECT_NAME} utils game)
