/**
 * @file Json.cpp
 * 
 * This module contains the definition of the
 * Json::Json class
 * 
 * © 2019 by Abhijit Kale (inspired by version from Richard Walters)
 */
#include <Json\Json.hpp>

namespace Json{

    /**
     * This contains the private properties of a Json instance
     */
    struct Json::Impl {
    };

    Json::~Json() = default;

    Json::Json()
        : impl_(new Impl)
    {
        
                

    }

}