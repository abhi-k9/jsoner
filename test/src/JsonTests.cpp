/**
 * @file JsonTests.cpp
 * 
 * This module contains the unit tests of the
 * Json::Json class
 * 
 * © 2020 by Abhijit Kale (inspired by version from Richard Walters)
 */

#include <gtest/gtest.h>
#include <Json/Json.hpp>

// /**
//  * This is the test fixture for these tests, providing common
//  * setup and teardown for each test
//  */

// struct JasonTests
//     :public ::testing::Test
// {
//     // Propertis

//     /**
//      * This is the unit under test
//      */
//     Json::Json Json;

//     virtual void SetUp(){}

//     virtual void TearDown(){}

// };

TEST(JsonTests, FromNull){
    Json::Json json(nullptr);
    ASSERT_EQ("null", json.ToString());
}

TEST(JsonTests, ToNull){
    const auto json = Json::Json::FromString("null"); 
    ASSERT_EQ(json, nullptr);
}

TEST(JsonTests, FromBoolean){
    Json::Json jsonTrue(true), jsonFalse(false);
    ASSERT_EQ("true", jsonTrue.ToString());
    ASSERT_EQ("false", jsonFalse.ToString());
}

TEST(JsonTests, ToBoolean){
    const auto jsonTrue = Json::Json::FromString("true"); 
    const auto jsonFalse = Json::Json::FromString("false"); 
    ASSERT_EQ(jsonTrue, true);
    ASSERT_EQ(jsonFalse, false);
}