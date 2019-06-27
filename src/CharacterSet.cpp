#include <src/CharacterSet.h>

const std::unordered_set<char>& CharacterSet::getWhiteSpaces() {
    static std::unordered_set<char>* whitespaces = nullptr;
    static std::string whitespacesString = " \t\n";

    if (whitespaces == nullptr) {
        whitespaces = new std::unordered_set<char>();
        for (char& character : whitespacesString) {
            whitespaces->insert(character);
        }
    }
    return *whitespaces;
}

bool CharacterSet::isWhiteSpace(char character) {
    return getWhiteSpaces().count(character) == 1;
}

bool CharacterSet::hasWhiteSpace(const std::string& string) {
    for (size_t i = 0; i < string.length(); i++) {
        if (isWhiteSpace(string[i])) {
            return true;
        }
    }
    return false;
}


bool CharacterSet::isXmlNameCharacter(char character) {
    return (character >= 'a' && character <= 'z') ||
    (character >= 'A' && character <= 'Z') ||
    character == '_' || character == '-' ||
    (character >= '0' && character <= '9');
}