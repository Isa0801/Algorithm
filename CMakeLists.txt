cmake_minimum_required(VERSION 3.10)

project(Algorithm)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML HINTS C:/dev/SFML-2.5.1-64bit/lib/cmake/SFML COMPONENTS audio system graphics network window REQUIRED)


add_executable(Algorithm src.cpp)

target_include_directories(Algorithm PUBLIC C:/dev/SFML-2.5.1-64bit/include/ ./include)
target_link_libraries(Algorithm sfml-graphics sfml-system sfml-window sfml-network sfml-audio )
