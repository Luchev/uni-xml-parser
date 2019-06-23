#pragma once

#include <src/XmlAttribute.h>
#include <src/XmlTag.h>

#include <string>
#include <vector>

class XmlElement {
 public:
    XmlElement();
    XmlElement(const XmlElement& element);
    XmlElement& operator=(const XmlElement& element);
    ~XmlElement();

    const std::string& GetName() const;
    const std::string& GetContent() const;

    void setName(const std::string& name);
    void setContent(const std::string& content);

    void addChildElement(const XmlElement& xmlElement);
    void addAttribute(const XmlAttribute& xmlAttribute);

    enum Type {
        Simple,
        Empty,
        Mixed,
        Comment,
        Header
    };

 private:
    std::string name;
    std::string content;
    XmlElement* parent = nullptr;
    std::vector<XmlElement*> children;
    std::vector<XmlAttribute*> attributes;
    Type type = XmlElement::Type::Simple;

    void setType(XmlElement::Type type);
    void setChildren(const std::vector<XmlElement*> children);
    void setAttributes(const std::vector<XmlAttribute*> attributes);
    void deleteChildren();
    void deleteAttributes();
    void setFromAnotherXmlElement(const XmlElement& element);
};
