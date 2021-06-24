cmake_minimum_required(VERSION 3.16)
project(quickerfix VERSION 0.1 LANGUAGES CXX)

include(FetchContent)

add_subdirectory(src)

option(BUILD_TESTING "Build tests" OFF)
if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif ()
