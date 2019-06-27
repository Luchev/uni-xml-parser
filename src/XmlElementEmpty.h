#pragma once
#include <src/XmlElement.h>
#include <src/XmlAttribute.h>
#include <string>
#include <vector>

class XmlElementEmpty : public XmlElement {
 public:
    XmlElementEmpty();
    void addAttribute(const XmlAttribute& xmlAttribute);
    std::vector<XmlAttribute> getAttributes() const;

    std::string toString() const override;

    XmlElement* clone() const override;
 protected:
    std::vector<XmlAttribute> attributes;
};
