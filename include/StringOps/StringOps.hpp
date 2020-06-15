#ifndef STRING_OPS_HPP
#define STRING_OPS_HPP

/**
 * @file StringOps.hpp
 * 
 * This module declares the StringOps Functions
 * 
 * © Richard Walters
 */

#include <string>
#include <set>

namespace StringOps{

    /**
     * This function returns a copy of the given input string, modified
     * so that every character in the given "charactersToEscape" that is
     * found in the input string is prefixed by the given "escapeCharacter".
     *
     * @param[in] s
     *     This is the input string.
     *
     * @param[in] escapeCharacter
     *     This is the character to put in front of every character
     *     in the input string that is a member of the
     *     "charactersToEscape" set.
     *
     * @param[in] charactersToEscape
     *     These are the characters that should be escaped in the input.
     *
     * @return
     *     A copy of the input string is returned, where every character
     *     in the given "charactersToEscape" that is found in the input
     *     string is prefixed by the given "escapeCharacter".
     */
    std::string Escape(const std::string& s, char escapeCharacter, const std::set< char >& charactersToEscape);

    /**
     * This function removes the given escapeCharacter from the given
     * input string, returning the result.
     *
     * @param[in] s
     *     This is the string from which to remove all escape characters.
     *
     * @param[in] escapeCharacter
     *     This is the character to remove from the given input string.
     *
     * @return
     *     A copy of the given input string, with all instances of the
     *     given escape character removed, is returned.
     */
    std::string Unescape(const std::string& s, char escapeCharacter);

}

#endif // End STRING_OPS_HPP