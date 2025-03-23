cmake_minimum_required(VERSION 3.14)
project(ContainersTests)

set(CMAKE_CXX_STANDARD 17)

# Подключаем GoogleTest как подмодуль
add_subdirectory(tests/GoogleTest)

include_directories(
    include
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/GoogleTest/googletest/include
)

add_executable(ContainersTests tests/test_main.cpp)

target_link_libraries(ContainersTests 
    GTest::gtest_main
    GTest::gmock
)
