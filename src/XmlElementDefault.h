#pragma once
#include <src/XmlElementEmpty.h>
#include <string>
#include <vector>

class XmlElementDefault : public XmlElementEmpty {
 public:
    XmlElementDefault();
    XmlElementDefault(const XmlElementDefault& rhs);
    XmlElementDefault& operator=(const XmlElementDefault& rhs);
    ~XmlElementDefault();

    void addChildElement(const XmlElement* xmlElement);

    std::string toString() const override;

    XmlElement* clone() const override;
 private:
    std::vector<XmlElement*> children;

    void deleteChildren();
    void setChildren(const std::vector<XmlElement*>& children);
    void copyXmlElementDefault(const XmlElementDefault& element);
};
