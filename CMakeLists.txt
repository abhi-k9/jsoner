# CMakeLists.txt for JSONer
#
# © 2020 by Abhijit Kale (inspired by version from Richard Walters)

cmake_minimum_required(VERSION 3.8)
project(Json VERSION 1.0)

set(This Json)

set(Headers
    include/Json/Json.hpp
    include/StringOps/StringOps.hpp
)

set(Sources
    src/Json.cpp
    src/StringOps.cpp
)

option(BUILD_SHARED_LIBS "Build as shared library" OFF)

add_library(${This} ${Sources} ${Headers})
set_target_properties(${This} PROPERTIES
    FOLDER Libraries
)

target_include_directories(${This} PUBLIC 
    include
)

# target_link_libraries(${This} PUBLIC
#     lib
# )

enable_testing()

add_subdirectory(test)