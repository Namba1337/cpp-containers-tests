cmake_minimum_required(VERSION 3.14)
project(ContainersTests)

# Явно задаем тип runtime библиотек
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

if(MSVC)
    # Для Visual Studio
    add_compile_options(/MDd)  # Используем динамическую runtime библиотеку
else()
    set(CMAKE_CXX_STANDARD 17)
endif()

# Подключаем GoogleTest
add_subdirectory(tests/GoogleTest EXCLUDE_FROM_ALL)

include_directories(include)

# Исполняемый файл
add_executable(ContainersTestsExecutable tests/test_main.cpp)

# Линковка
target_link_libraries(ContainersTestsExecutable 
    gtest
    gtest_main
)