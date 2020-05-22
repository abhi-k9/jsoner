#ifndef JSON_JSON_HPP
#define JSON_JSON_HPP

/**
 * @file Json.hpp
 * 
 * This module declares the Json:Json class.
 * 
 * © 2019 by Abhijit Kale (inspired by version from Richard Walters)
 */

#include <memory>
#include <string>

namespace Json{

    /**
     * This class represents a data structure that was parsed from,
     * or can be rendered to, a string in the JSON Data Interchange
     * Format as specified in RFC 7159 (https://tools.ietf.org/html/rfc7159)
     */

    class Json {

        public:
        // Life cycle management
        ~Json();
        Json(const Json&) = delete;
        Json(Json&&) = delete;
        Json& operator=(const Json&) = delete;
        Json& operator=(Json&&) = delete;

        // Public methods
        public:
        /**
         * This is the default constructor.
         */
        Json();

        // Private properties
        private:
        /**
         * This is the type of structure that contains the private
         * properties of the instance. It is defined in the implementation
         * and declared here to ensure that it is scoped inside the class
         */

        struct Impl;

        /**
         * This contains the private properties of the instance
         */
        std::unique_ptr< struct Impl > impl_;

    };


}

#endif // JSON_JSON_HPP