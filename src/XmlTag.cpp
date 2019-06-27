#include <src/XmlTag.h>

#include <src/XmlAttribute.h>
#include <src/StringExtension.h>
#include <src/CharacterSet.h>

#include <iostream>

std::string XmlTag::toString() const {
    return contents;
}

XmlTag::XmlTag(const std::string& contents) {
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

std::string XmlTag::getName() const {
    if (!isValid()) {
        return "";
    }

    size_t start = 0;
    while (this->contents[start] == '<' || this->contents[start] == '/' ||
    this->contents[start] == '?' || isspace(this->contents[start])) {
        start++;
    }

    size_t end = start;
    while (end < this->contents.length() &&
    CharacterSet::isXmlNameCharacter(this->contents[end])) {
        end++;
    }

    return this->contents.substr(start, end - start);
}

std::vector<XmlAttribute> XmlTag::getAttributes() const {
    if (!isValid()) {
        return std::vector<XmlAttribute>();
    }
    size_t start = 0;
    while (this->contents[start] == '<' || this->contents[start] == '/' ||
    this->contents[start] == '?' || isspace(this->contents[start])) {
        start++;
    }
    while (start < this->contents.length() &&
    CharacterSet::isXmlNameCharacter(this->contents[start])) {
        start++;
    }

    std::vector<XmlAttribute> attributes;
    std::string name;
    std::string value;
    bool beforeEquals = true;
    bool hasDoubleQuotes = false;
    for (size_t i = start; i < this->contents.length(); i++) {
        // std::cout << name << std::endl;
        if (this->contents[i] == '=') {
            beforeEquals = false;
            continue;
        }
        if (beforeEquals) {
            name.push_back(this->contents[i]);
        } else {
            if (this->contents[i] == '"') {
                if (hasDoubleQuotes) {  // done reading
                    hasDoubleQuotes = false;
                    StringExtension::trim(&name);
                    StringExtension::trim(&value);
                    XmlAttribute next(name, value);
                    attributes.push_back(next);
                    name = "";
                    value = "";
                    beforeEquals = true;
                } else {
                    hasDoubleQuotes = true;
                }
            } else {
                value.push_back(this->contents[i]);
            }
        }
    }

    return attributes;
}
