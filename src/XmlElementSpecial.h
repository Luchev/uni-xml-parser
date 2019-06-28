#pragma once
#include <src/XmlElementEmpty.h>
#include <string>

class XmlElementSpecial : public XmlElementEmpty {
 public:
    explicit XmlElementSpecial(const std::string& name = "");

    std::string toString() const override;

    XmlElement* clone() const override;
};
