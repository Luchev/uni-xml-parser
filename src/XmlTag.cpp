#include <src/XmlTag.h>
#include <src/XmlAttribute.h>
#include <src/StringExtension.h>
#include <src/CharacterSet.h>
#include <src/Logger.h>
#include <iostream>

XmlTag::XmlTag(const std::string& content) {
    this->content = content;
    StringExtension::trim(&this->content);
}

std::string XmlTag::toString() const {
    return this->content;
}

std::string XmlTag::getContent() const {
    return this->content;
}

std::string XmlTag::getName() const {
    if (!isValid()) {
        return "";
    }

    size_t start = findNameStart();
    size_t end = findNameEnd();
    size_t length = end - start;

    return this->content.substr(start, length);
}

std::vector<XmlAttribute> XmlTag::getAttributes() const {
    if (!isValid()) {
        return std::vector<XmlAttribute>();
    }

    try {
        return getAttributesWithoutValidation();
    } catch (std::invalid_argument ex) {
        Logger::error("Failed to parse xml attribute: " + std::string(ex.what()));
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

bool XmlTag::isEmpty() const {
    return endsWithChar('/');
}

bool XmlTag::isSpecial() const {
    return startsWithChar('?');
}

bool XmlTag::isValid() const {
    if (this->content.length() > 0) {
        return *this->content.begin() == '<' && *this->content.rbegin() == '>';
    }
    return false;
}

bool XmlTag::isContents() const {
    return !isValid();
}

bool XmlTag::startsWithChar(char character) const {
    for (auto it = content.begin() + 1; it != content.end(); it++) {
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
    for (auto it = content.rbegin() + 1; it != content.rend(); it++) {
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

    while (start < this->content.length() &&
    !CharacterSet::isXmlNameCharacter(this->content[start])) {
        start++;
    }

    return start;
}

size_t XmlTag::findNameEnd(size_t start) const {
    size_t end = start;

    while (end < this->content.length() && CharacterSet::isXmlNameCharacter(this->content[end])) {
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
    while (i < this->content.length()) {
        std::string name = readXmlAttributeNameStartingFromIndex(&i);
        std::string value = readXmlAttributeValueStartingFromIndex(&i);
        if (name.length() != 0 && value.length() != 0) {
            attributes.push_back(XmlAttribute(name, value));
        } else {
            break;
        }
    }

    return attributes;
}

std::string XmlTag::readXmlAttributeNameStartingFromIndex(size_t* index) const {
    std::string name;

    while (*index < this->content.length()) {
        if (this->content[*index] != '=') {
            name.push_back(this->content[*index]);
        } else {
            (*index)++;
            break;
        }
        (*index)++;
    }

    return name;
}

std::string XmlTag::readXmlAttributeValueStartingFromIndex(size_t* index) const {
    std::string value;
    bool encounteredDoubleQuotes = false;

    while (*index < this->content.length()) {
        if (this->content[*index] != '"') {
            value.push_back(this->content[*index]);
        } else if (!encounteredDoubleQuotes) {
            encounteredDoubleQuotes = true;
        } else {
            (*index)++;
            break;
        }
        (*index)++;
    }

    return value;
}
