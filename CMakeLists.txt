cmake_minimum_required(VERSION 3.14)
project(ContainersTests)

set(CMAKE_CXX_STANDARD 17)

# Подключаем GoogleTest (важно указать правильный путь к подмодулю)
add_subdirectory(tests/GoogleTest EXCLUDE_FROM_ALL)

include_directories(include)

# Создаем исполняемый файл
add_executable(
    ContainersTestsExecutable
    tests/test_main.cpp
)

# Линкуем библиотеки
target_link_libraries(
    ContainersTestsExecutable
    gtest
    gtest_main
    pthread  # Требуется для Linux
)