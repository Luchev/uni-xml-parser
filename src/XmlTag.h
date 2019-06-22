#pragma once

#include <string>

class XmlTag {
 public:
    explicit XmlTag(const std::string & contents);
    std::string toString() const;
    bool isOpening() const;
    bool isClosing() const;
    bool isSelfClosing() const;
    bool isValid() const;
    bool isContents() const;
    bool isEmpty() const;
 private:
    std::string contents;
    bool endsWithSlash() const;
    bool startsWithQuestion() const;
};
