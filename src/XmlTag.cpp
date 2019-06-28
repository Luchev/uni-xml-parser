#include <src/XmlTag.h>
#include <src/XmlAttribute.h>
#include <src/StringExtension.h>
#include <src/CharacterSet.h>
#include <iostream>

XmlTag::XmlTag(const std::string& contents) {
    this->contents = contents;
    StringExtension::trim(&this->contents);
}

std::string XmlTag::toString() const {
    return contents;
}

std::string XmlTag::getName() const {
    if (!isValid()) {
        return "";
    }

    size_t start = findNameStart();
    size_t end = findNameEnd();
    size_t length = end - start;

    return this->contents.substr(start, length);
}

std::vector<XmlAttribute> XmlTag::getAttributes() const {
    if (!isValid()) {
        return std::vector<XmlAttribute>();
    }

    return getAttributesWithoutValidation();
}


bool XmlTag::isOpening() const {
    return !isClosing();
}

bool XmlTag::isClosing() const {
    return startsWithChar('/');
}

bool XmlTag::isSelfClosing() const {
    return endsWithChar('/');
}

bool XmlTag::isSpecial() const {
    return startsWithChar('?');
}

bool XmlTag::isValid() const {
    if (this->contents.length() > 0) {
        return *this->contents.begin() == '<' && *this->contents.rbegin() == '>';
    }
    return false;
}

bool XmlTag::isContents() const {
    return !isValid();
}

bool XmlTag::isEmpty() const {
    return this->contents.size() == 0;
}

bool XmlTag::startsWithChar(char character) const {
    for (auto it = contents.begin() + 1; it != contents.end(); it++) {
        if (*it == character) {
            return true;
        } else if (std::isspace(*it)) {
            continue;
        } else {
            break;
        }
    }
    return false;
}

bool XmlTag::endsWithChar(char character) const {
    for (auto it = contents.rbegin() + 1; it != contents.rend(); it++) {
        if (*it == character) {
            return true;
        } else if (std::isspace(*it)) {
            continue;
        } else {
            break;
        }
    }
    return false;
}

size_t XmlTag::findNameStart() const {
    size_t start = 0;
    while (start < this->contents.length() &&
    !CharacterSet::isXmlNameCharacter(this->contents[start])) {
        start++;
    }
    return start;
}

size_t XmlTag::findNameEnd(size_t start) const {
    size_t end = start;
    while (end < this->contents.length() && CharacterSet::isXmlNameCharacter(this->contents[end])) {
        end++;
    }
    return end;
}

size_t XmlTag::findNameEnd() const {
    size_t start = findNameStart();
    size_t end = findNameEnd(start);
    return end;
}

std::vector<XmlAttribute> XmlTag::getAttributesWithoutValidation() const {
    std::vector<XmlAttribute> attributes;

    size_t i = findNameEnd();
    while (i < this->contents.length()) {
        std::string name = readXmlAttributeNameStartingFromIndex(i);
        std::string value = readXmlAttributeValueStartingFromIndex(i);
        if (name.length() != 0 && value.length() != 0) {
            attributes.push_back({name, value});
        } else {
            break;
        }
    }

    return attributes;
}

std::string XmlTag::readXmlAttributeNameStartingFromIndex(size_t& index) const {
    std::string name;

    while (index < this->contents.length()) {
        if (this->contents[index] != '=') {
            name.push_back(this->contents[index]);
        } else {
            index++;
            break;
        }
        index++;
    }
    return name;
}

std::string XmlTag::readXmlAttributeValueStartingFromIndex(size_t& index) const {
    std::string value;
    bool encounteredDoubleQuotes = false;

    while (index < this->contents.length()) {
        if (this->contents[index] != '"') {
            value.push_back(this->contents[index]);
        } else if (!encounteredDoubleQuotes) {
            encounteredDoubleQuotes = true;
        } else {
            index++;
            break;
        }
        index++;
    }
    return value;
}
