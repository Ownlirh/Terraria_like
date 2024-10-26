cmake_minimum_required(VERSION 3.10)

project(MySFMLGame) # Put the name of your project

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_INCLUDE_DIRS "D:/libraries/SFML-2.6.1/include") # Put your library link
set(SFML_LIBRARY_DIRS "D:/libraries/SFML-2.6.1/lib") # Put your library link

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED PATHS ${SFML_LIBRARY_DIRS})

message(STATUS "SFML_INCLUDE_DIRS: ${SFML_INCLUDE_DIRS}")
message(STATUS "SFML_LIBRARY_DIRS: ${SFML_LIBRARY_DIRS}")

add_executable(my_game src/main.cpp) # Put the name of your executable replace my_game

target_include_directories(my_game PRIVATE ${SFML_INCLUDE_DIRS})

if(SFML_FOUND)
    target_link_libraries(my_game sfml-graphics sfml-window sfml-system)
else()
    message(FATAL_ERROR "SFML not found")
endif()
