#include <src/StringExtension.h>

#include <string>
#include <algorithm>

void StringExtension::trimLeft(std::string* string) {
    string->erase(
        string->begin(),
        std::find_if(string->begin(), string->end(), [](int ch) {
            return !std::isspace(ch);
    }));
}

void StringExtension::trimRight(std::string* string) {
    string->erase(
        std::find_if(string->rbegin(), string->rend(), [](int character) {
            return !std::isspace(character);
    }).base(), string->end());
}

void StringExtension::trim(std::string* string) {
    trimLeft(string);
    trimRight(string);
}
