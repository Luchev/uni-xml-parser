#pragma once
#include <src/XmlElementEmpty.h>
#include <string>
#include <vector>

class XmlElementSpecial : public XmlElementEmpty {
 public:
    explicit XmlElementSpecial(const std::string& name = "");
    XmlElementSpecial(const std::string& name, const std::vector<XmlAttribute> attributes);

    std::string toString() const override;

    XmlElement* clone() const override;
};
