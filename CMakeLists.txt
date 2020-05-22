# CMakeLists.txt for JSONer
#
# © 2019 by Abhijit Kale (inspired by version from Richard Walters)

cmake_minimum_required(VERSION 3.8)
project(Json VERSION 1.0)

set(This Json)

set(Headers
    include/Json/Json.hpp
)

set(Sources
    src/Json.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
set_target_properties(${This} PROPERTIES
    FOLDER Libraries
)

target_include_directories(${This} PUBLIC 
    include
)

target_link_libraries(${This} PUBLIC
    lib
)

add_subdirectory(test)