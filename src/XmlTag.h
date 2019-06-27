#pragma once

#include <src/XmlAttribute.h>

#include <string>
#include <vector>
#include <utility>

class XmlTag {
 public:
    explicit XmlTag(const std::string& contents);
    std::string toString() const;
    bool isOpening() const;
    bool isClosing() const;
    bool isSelfClosing() const;
    bool isValid() const;
    bool isContents() const;
    bool isEmpty() const;
    std::string getName() const;
    std::vector<XmlAttribute> getAttributes() const;
 private:
    std::string contents;
    bool endsWithSlash() const;
    bool startsWithQuestion() const;
};
