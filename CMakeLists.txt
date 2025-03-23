cmake_minimum_required(VERSION 3.14)
project(ContainersTests)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_subdirectory(tests/GoogleTest)

add_executable(
    ContainersTests
    tests/test_main.cpp
)

target_link_libraries(
    ContainersTests
    GTest::GTest
    GTest::Main
)