#pragma once
#include <src/XmlElementEmpty.h>
#include <string>
#include <vector>

class XmlElementDefault : public XmlElementEmpty {
 public:
    explicit XmlElementDefault(const std::string& name = "");
    XmlElementDefault(const std::string& name, const std::vector<XmlAttribute>& attributes);
    XmlElementDefault(const XmlElementDefault& rhs);
    XmlElementDefault& operator=(const XmlElementDefault& rhs);
    ~XmlElementDefault();

    void addChildElement(const XmlElement* element);
    size_t getNumberOfChildren() const;
    XmlElement* getChild(size_t index);

    bool isNameless() const;

    std::string toString() const override;
    std::string toStringBeautified() const override;

    XmlElement* clone() const override;

 private:
    std::vector<XmlElement*> children;

    void copyXmlElementDefault(const XmlElementDefault& element);
    void setChildren(const std::vector<XmlElement*>& children);
    void deleteChildren();

    std::string toStringOpenTag() const;
    std::string toStringCloseTag() const;
};
