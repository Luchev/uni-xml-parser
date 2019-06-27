#include <src/XmlElement.h>

#include <src/XmlAttribute.h>

XmlElement::~XmlElement() {
    // Intentionally empy
}

void XmlElement::setName(const std::string& name) {
    this->name = name;
}

std::string XmlElement::getName() const {
    return name;
}

void XmlElement::setParent(XmlElement* parent) {
    this->parent = parent;
}

XmlElement* XmlElement::getParent() const {
    return parent;
}
