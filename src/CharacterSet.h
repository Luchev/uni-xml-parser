#pragma once
#include <string>
#include <unordered_set>

/** Character filtering
 * 
 * Introduce static methods to check if a character or a string
 * is in a certain set of characters (e.g whitesapces)
 */
class CharacterSet {
 public:
    /** Check if a string has any whitespaces
     * \param[in] string - string to check
     * \return bool
    */
    static bool hasWhiteSpace(const std::string& string);
    /** Check if a character is a whitespace
     * \param character - character to check
     * \return bool
     */
    static bool isWhiteSpace(char character);
    /** Check if a character is valid in an xml name
     * 
     * Check if the character is one of the following:
     * - Uppercase letter
     * - Lowercase letter
     * - Digit
     * - Special character "-_." (dash, underscore or dot)
     * \param character - character to check
     * \return bool
     */
    static bool isXmlNameCharacter(char character);

 private:
    static const std::unordered_set<char>& getWhiteSpaces();
    static const std::unordered_set<char>& getXmlSpecialCharacters();

    static bool isLowercase(char character);
    static bool isUppercase(char character);
    static bool isDigit(char character);
    static bool isXmlSpecialChar(char character);
};
