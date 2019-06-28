#pragma once
#include <src/XmlElement.h>
#include <src/XmlAttribute.h>
#include <string>
#include <vector>

class XmlElementEmpty : public XmlElement {
 public:
    explicit XmlElementEmpty(const std::string& name = "");
    void addAttribute(const XmlAttribute& xmlAttribute);
    std::vector<XmlAttribute> getAttributes() const;
    void setAttributes(const std::vector<XmlAttribute>& attributes);

    std::string toString() const override;
    std::string toStringBeautified() const override;

    XmlElement* clone() const override;
 protected:
    std::vector<XmlAttribute> attributes;
};
