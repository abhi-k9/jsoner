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

# if Windows platform, use gtest libraries built for Windows
if(WIN32)
    find_library(GTEST_MAIN_LIB gtest_main HINTS ${Json_SOURCE_DIR}/lib/windows/)
    find_library(GTEST_LIB libgtest.a HINTS ${Json_SOURCE_DIR}/lib/windows/)
else()
    find_library(GTEST_MAIN_LIB gtest_main HINTS ${Json_SOURCE_DIR}/lib)
    find_library(GTEST_LIB libgtest.a HINTS ${Json_SOURCE_DIR}/lib)
endif()

message(STATUS "gtest_main library found at ${GTEST_MAIN_LIB}")
message(STATUS "gtest library found at ${GTEST_LIB}")

target_link_libraries(${This} PUBLIC
    Json
    ${GTEST_LIB}
    ${GTEST_MAIN_LIB}
    pthread
)

add_test(
    NAME ${This}
    COMMAND ${This}
)