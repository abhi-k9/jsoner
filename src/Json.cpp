/**
 * @file Json.cpp
 * 
 * This module contains the definition of the
 * Json::Json class
 * 
 * © 2020 by Abhijit Kale (inspired by version from Richard Walters)
 */
#include <Json/Json.hpp>

namespace Json{

    /**
     * This contains the private properties of a Json instance
     */
    struct Json::Impl {
        /**
         * These are the different kinds of values that a JSON object can be.
         */
        enum class Type {
            Invalid,
            Null,
            Boolean,
            String,
        };

        /**
         * This indicates the type of the value represented
         * by the JSON object
         */
        Type type = Type::Invalid;

        /**
         * This holds the actual value represented by the JSON
         * object. Use the member that matches the actual type.
         */
        union {
            bool booleanValue;
            std::string* stringValue;
        };

        // Life cycle management
        ~Impl(){
            switch (type) {
                case Impl::Type::String: {
                    delete stringValue;
                } break;

                default: break;
            }
            
        };

        Impl(const Impl&) = delete;
        Impl(Impl&&) = delete;
        Impl& operator=(const Impl&) = delete;
        Impl& operator=(Impl&&) = delete;

        // Methods

        /**
         * This is the default constructor
         */
        Impl() = default;

    };

    Json::~Json() = default;
    Json& Json::operator=(Json&&) = default;
    Json::Json(Json&&) = default;    

    Json::Json()
        : impl_(new Impl)
    {
        
                

    }

    Json::Json(std::nullptr_t) 
        : impl_(new Impl)
    {
        impl_->type = Impl::Type::Null;
    }

    Json::Json(bool value)
        : impl_(new Impl)
    {
        impl_->type = Impl::Type::Boolean;
        impl_->booleanValue = value;
    }

    Json::Json(const std::string& value)
        : impl_(new Impl)
    {
        impl_->type = Impl::Type::String;
        impl_->stringValue = new std::string(value);
    }


    // TODO: Easy to take out the "return false" case
    bool Json::operator==(const Json& other) const {
        if(impl_->type != other.impl_->type) {
            return false;
        } else switch(impl_->type) {
            case Impl::Type::Null: return true;
            case Impl::Type::Boolean: 
                return impl_->booleanValue == other.impl_->booleanValue;
            default: return true; 
        }
    }

    std::string Json::ToString() const{
        switch(impl_->type) {

            case Impl::Type::Null: return "null";
            case Impl::Type::Boolean: return impl_->booleanValue? "true" : "false";
            default: return "Invalid";
        
        }
    }

    Json Json::FromString(const std::string& encoding){
        if(encoding == "null"){
            return nullptr;
        } else if (encoding == "true") {
            return true;
        } else if (encoding == "false") {
            return false;
        } else {
            return Json();
        }
    }

}