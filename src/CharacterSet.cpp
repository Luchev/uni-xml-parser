#include <src/CharacterSet.h>

bool CharacterSet::hasWhiteSpace(const std::string& string) {
    for (size_t i = 0; i < string.length(); i++) {
        if (isWhiteSpace(string[i])) {
            return true;
        }
    }
    return false;
}

bool CharacterSet::isWhiteSpace(char character) {
    return getWhiteSpaces().count(character) == 1;
}

bool CharacterSet::isXmlNameCharacter(char character) {
    return isLowercase(character) || isUppercase(character) ||
        isDigit(character) || isXmlSpecialChar(character);
}

const std::unordered_set<char>& CharacterSet::getWhiteSpaces() {
    static std::unordered_set<char> whitespaces;
    static std::string whitespacesString = " \t\n";

    if (whitespaces.empty()) {
        for (char& character : whitespacesString) {
            whitespaces.insert(character);
        }
    }
    return whitespaces;
}

const std::unordered_set<char>& CharacterSet::getXmlSpecialCharacters() {
    static std::unordered_set<char> xmlCharacters;
    static std::string specialCharactersString = "-_.";

    if (xmlCharacters.empty()) {
        for (char& character : specialCharactersString) {
            xmlCharacters.insert(character);
        }
    }
    return xmlCharacters;
}

bool CharacterSet::isLowercase(char character) {
    return character >= 'a' && character <= 'z';
}

bool CharacterSet::isUppercase(char character) {
    return character >= 'A' && character <= 'Z';
}

bool CharacterSet::isDigit(char character) {
    return character >= '0' && character <= '9';
}

bool CharacterSet::isXmlSpecialChar(char character) {
    return getXmlSpecialCharacters().count(character) == 1;
}
