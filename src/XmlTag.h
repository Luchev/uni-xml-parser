#pragma once
#include <src/XmlAttribute.h>
#include <string>
#include <vector>
#include <utility>

class XmlTag {
 public:
    explicit XmlTag(const std::string& content);

    std::string toString() const;

    std::string getContent() const;
    std::string getName() const;
    std::vector<XmlAttribute> getAttributes() const;

    bool isOpening() const;
    bool isClosing() const;
    bool isEmpty() const;
    bool isSpecial() const;
    bool isValid() const;
    bool isContents() const;

 private:
    std::string content;

    bool startsWithChar(char character) const;
    bool endsWithChar(char character) const;

    size_t findNameStart() const;
    size_t findNameEnd(size_t start) const;
    size_t findNameEnd() const;

    std::vector<XmlAttribute> getAttributesWithoutValidation() const;
    std::string readXmlAttributeNameStartingFromIndex(size_t* index) const;
    std::string readXmlAttributeValueStartingFromIndex(size_t* index) const;
};
