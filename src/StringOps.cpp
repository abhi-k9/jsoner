/**
 * @file StringOps.cpp
 * 
 * This module contains the definition of the
 * StringOps functionalities
 * 
 */

#include <StringOps/StringOps.hpp>

namespace StringOps {

    std::string Escape(const std::string& s, char escapeCharacter, const std::set< char >& charactersToEscape) {
        std::string output;
        for (size_t i = 0; i < s.length(); ++i) {
            if (charactersToEscape.find(s[i]) != charactersToEscape.end()) {
                output += escapeCharacter;
            }
            output += s[i];
        }
        return output;
    }

    std::string Unescape(const std::string& s, char escapeCharacter) {
        std::string output;
        bool escape = false;
        for (size_t i = 0; i < s.length(); ++i) {
            if (
                !escape
                && (s[i] == escapeCharacter)
            ) {
                escape = true;
            } else {
                output += s[i];
                escape = false;
            }
        }
        return output;
    }

} // End namespace StringOps