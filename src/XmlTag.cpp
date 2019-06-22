#include <src/XmlTag.h>

#include "StringExtension.h"
#include <iostream>

std::string XmlTag::toString() const {
    return contents;
}

XmlTag::XmlTag(const std::string & contents) {
    this->contents = contents;
    StringExtension::trim(&this->contents);
}

bool XmlTag::isOpening() const {
    return !isClosing();
}

bool XmlTag::isClosing() const {
    for (auto it = contents.begin() + 1; it != contents.end(); it++) {
        if (*it == '/') {
            return true;
        } else if (std::isspace(*it)) {
            continue;
        } else {
            break;
        }
    }
    return false;
}

bool XmlTag::endsWithSlash() const {
    for (auto it = contents.rbegin() + 1; it != contents.rend(); it++) {
        if (*it == '/') {
            return true;
        } else if (std::isspace(*it)) {
            continue;
        } else {
            break;
        }
    }
    return false;
}

bool XmlTag::startsWithQuestion() const {
    for (auto it = contents.begin() + 1; it != contents.end(); it++) {
        if (*it == '?') {
            return true;
        } else if (std::isspace(*it)) {
            continue;
        } else {
            break;
        }
    }
    return false;
}

bool XmlTag::isSelfClosing() const {
    return endsWithSlash() || startsWithQuestion();
}

bool XmlTag::isValid() const {
    if (this->contents.length() > 0) {
        return *this->contents.begin() == '<' &&
            *this->contents.rbegin() == '>';
    }
    return false;
}

bool XmlTag::isContents() const {
    return !isValid();
}

bool XmlTag::isEmpty() const {
    return this->contents.size() == 0;
}
