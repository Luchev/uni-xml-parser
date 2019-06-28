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
    std::string getName() const;
    void setName(const std::string& name);
    XmlElement* getParent() const;
    void setParent(XmlElement* parent);

    virtual std::string toString() const = 0;
    virtual std::string toStringBeautified() const = 0;

    virtual XmlElement* clone() const = 0;

 protected:
    XmlElementType type;
    std::string name;
    XmlElement * parent = nullptr;
};
