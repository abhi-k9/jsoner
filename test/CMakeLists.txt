# CMakeLists.txt for JsonTests
#
# © 2019 by Abhijit Kale (inspired by version from Richard Walters)

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

target_include_directories(${This} PRIVATE ..)

target_link_libraries(${This} PUBLIC
    Json
    gtest_main
)

add_test(
    NAME ${This}
    COMMAND ${This}
)