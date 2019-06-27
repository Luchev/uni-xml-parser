#pragma once

#include <src/XmlAttribute.h>
#include <src/XmlTag.h>
#include <src/XmlElementType.h>
#include <string>
#include <vector>

class XmlElement {
 public:
    virtual ~XmlElement() = 0;

    XmlElementType getType() const;
    void setName(const std::string& name);
    std::string getName() const;
    void setParent(XmlElement* parent);
    XmlElement* getParent() const;

    virtual std::string toString() const = 0;

    virtual XmlElement* clone() const = 0;
 protected:
    XmlElementType type;
    std::string name;
    XmlElement * parent = nullptr;
};
