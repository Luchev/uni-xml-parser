#pragma once

#include <string>
#include <unordered_set>

class CharacterSet {
 public:
    bool static hasWhiteSpace(const std::string& string);
    bool static isWhiteSpace(char character);
    bool static isXmlNameCharacter(char character);
 private:
    static const std::unordered_set<char>& getWhiteSpaces();
};