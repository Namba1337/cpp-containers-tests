cmake_minimum_required(VERSION 3.14)
project(ContainersTests)

set(CMAKE_CXX_STANDARD 17)

# Подключаем GoogleTest как подмодуль (исправленный путь)
add_subdirectory(tests/GoogleTest EXCLUDE_FROM_ALL)

include_directories(include)

# Изменим имя исполняемого файла, чтобы избежать конфликта
add_executable(
    ContainersTestsExecutable  # Новое уникальное имя
    tests/test_main.cpp
)

target_link_libraries(
    ContainersTestsExecutable
    gtest
    gtest_main
)