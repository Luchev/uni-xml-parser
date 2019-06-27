#pragma once
#include <src/XmlElement.h>
#include <string>

class XmlElementContent : public XmlElement {
 public:
    explicit XmlElementContent(const std::string& string = "");

    std::string toString() const override;

    XmlElement* clone() const override;
 private:
    std::string content;
};
