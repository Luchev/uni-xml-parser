#pragma once
#include <src/XmlElementEmpty.h>
#include <string>

class XmlElementSpecial : public XmlElementEmpty {
 public:
    XmlElementSpecial();

    std::string toString() const override;

    XmlElement* clone() const override;
};
