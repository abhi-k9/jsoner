# CMakeLists.txt for JsonTests
#
# © 2020 by Abhijit Kale (inspired by version from Richard Walters)

cmake_minimum_required(VERSION 3.8)
set(This JsonTests)

# set(Headers
#     include/JsonTests/JsonTests.hpp
# )

set(Sources
    src/JsonTests.cpp
)

add_executable(${This} ${Sources})
set_target_properties(${This} PROPERTIES
    FOLDER Tests
)

target_include_directories(${This} PRIVATE 
    ${Json_SOURCE_DIR}/include
)

find_library(GTEST_LIB gtest_main HINTS ${Json_SOURCE_DIR}/lib)
find_library(JSON_LIB Json HINTS ${Json_SOURCE_DIR}/build)
message(STATUS "gtest_main library found at ${GTEST_LIB}")
message(STATUS "Json library found at ${JSON_LIB}")

target_link_libraries(${This} PUBLIC
    Json
    ${JSON_LIB}
    ${GTEST_LIB}
)

add_test(
    NAME ${This}
    COMMAND ${This}
)