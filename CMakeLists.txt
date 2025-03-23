cmake_minimum_required(VERSION 3.14)
project(ContainersTests)

set(CMAKE_CXX_STANDARD 17)

# Подключаем GoogleTest
add_subdirectory(tests/GoogleTest EXCLUDE_FROM_ALL)

# Указываем компилятору искать заголовки в include/
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/GoogleTest/googletest/include
)

add_executable(
    ContainersTestsExecutable
    tests/test_main.cpp
)

target_link_libraries(
    ContainersTestsExecutable
    gtest
    gtest_main
    pthread
)