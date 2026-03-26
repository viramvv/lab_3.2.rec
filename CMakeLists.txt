cmake_minimum_required(VERSION 3.20)
project(ListProject CXX)

set(CMAKE_CXX_STANDARD 17)

# Додаємо вихідні файли класу
set(SOURCE_FILES list.cpp list.h)

# 1. Головна програма (лабораторна робота)
add_executable(MainApp main.cpp ${SOURCE_FILES})

# 2. Модульні тести (Google Test)
# На macOS gtest зазвичай встановлюється через Homebrew
find_package(GTest REQUIRED)

# Створюємо окремий виконуваний файл для тестів
add_executable(UnitTests UnitTest.cpp ${SOURCE_FILES})

# Лінкуємо бібліотеки GTest та GTest::Main (автоматично додає main для тестів)
target_link_libraries(UnitTests GTest::GTest GTest::Main)