#pragma once
#include <string>
/** \file */

/** Extend std::string functionality with static methods
 */
class StringExtension {
 public:
    /** Trim whitespaces from both sides
     * \param[in] string pointer to trim
     */
    static void trim(std::string* string);
    /** Trim whitespaces from the start of a string
     * \param[in] string pointer to trim
     */
    static void trimLeft(std::string* string);
    /** Trim whitespaces from the end of a string
     * \param[in] string pointer to trim
     */
    static void trimRight(std::string* string);
};
