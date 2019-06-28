#pragma once
#include <string>

class StringExtension {
 public:
    static void trim(std::string* string);
    static void trimLeft(std::string* string);
    static void trimRight(std::string* string);
};
