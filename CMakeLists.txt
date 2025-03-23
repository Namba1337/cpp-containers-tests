cmake_minimum_required(VERSION 3.14)
project(ContainersTests)

set(CMAKE_CXX_STANDARD 17)

# Подключаем GoogleTest как подмодуль
add_subdirectory(tests/GoogleTest)

# Основные файлы проекта
include_directories(include)

# Исполняемый файл с тестами
add_executable(
    ContainersTests
    tests/test_main.cpp
)

# Линковка библиотек
target_link_libraries(
    ContainersTests
    gtest
    gtest_main
)