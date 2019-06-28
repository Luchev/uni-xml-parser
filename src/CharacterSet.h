#pragma once
#include <string>
#include <unordered_set>

class CharacterSet {
 public:
    static bool hasWhiteSpace(const std::string& string);
    static bool isWhiteSpace(char character);
    static bool isXmlNameCharacter(char character);

 private:
    static const std::unordered_set<char>& getWhiteSpaces();
    static const std::unordered_set<char>& getXmlSpecialCharacters();

    static bool isLowercase(char character);
    static bool isUppercase(char character);
    static bool isDigit(char character);
    static bool isXmlSpecialChar(char character);
};
