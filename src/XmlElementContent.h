#pragma once
#include <src/XmlElement.h>
#include <string>

class XmlElementContent : public XmlElement {
 public:
    explicit XmlElementContent(const std::string& string = "");

    void setContent(const std::string& content);

    std::string toString() const override;
    std::string toStringBeautified() const override;

    XmlElement* clone() const override;
 private:
    std::string content;
};
