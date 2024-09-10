cmake_minimum_required(VERSION 3.5)
project(TelegramBot)

set(CMAKE_CXX_STANDARD 11)

find_package(TgBot REQUIRED)
find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(TelegramBot main.cpp)

target_link_libraries(TelegramBot TgBot::TgBot)
