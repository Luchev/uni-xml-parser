#include "XmlElement.h"
#include "XmlAttribute.h"

XmlElement::XmlElement() {
    // Intentionally empty
}

XmlElement::XmlElement(const XmlElement & element) {
    setFromAnotherXmlElement(element);
}

XmlElement & XmlElement::operator=(const XmlElement & element) {
    if (this != &element) {
        deleteChildren();
        deleteAttributes();
        setFromAnotherXmlElement(element);
    }
    return *this;
}

XmlElement::~XmlElement() {
    deleteChildren();
    deleteAttributes();
}

void XmlElement::setFromAnotherXmlElement(const XmlElement & element) {
    SetName(element.name);
    SetContent(element.content);
    setChildren(element.children);
    setAttributes(element.attributes);
}

void XmlElement::setType(XmlElement::Type type) {
    this->type = type;
}

void XmlElement::deleteChildren() {
    size_t childrenVectorSize = this->children.size();
    for (size_t i = 0; i < childrenVectorSize; i++) {
        delete this->children[i];
    }
}

void XmlElement::deleteAttributes() {
    size_t attributesVectorSize = this->attributes.size();
    for (size_t i = 0; i < attributesVectorSize; i++) {
        delete this->attributes[i];
    }
}

void XmlElement::setChildren(const std::vector<XmlElement *> children) {
    size_t childrenVectorSize = this->children.size();
    for (size_t i = 0; i < childrenVectorSize; i++) {
        this->children.push_back(new XmlElement( * children[i]));
    }
}

void XmlElement::setAttributes(const std::vector<XmlAttribute *> attributes) {
    size_t attributesVectorSize = this->attributes.size();
    for (size_t i = 0; i < attributesVectorSize; i++) {
        this->attributes.push_back(new XmlAttribute( * attributes[i]));
    }
}

const std::string & XmlElement::GetName() const {
    return this->name;
}

const std::string & XmlElement::GetContent() const {
    return this->content;
}

void XmlElement::SetName(const std::string & name) {
    this->name = name;
}

void XmlElement::SetContent(const std::string & content) {
    this->content = content;
}

void XmlElement::AddChildElement(const XmlElement & xmlElement) {
    this->children.push_back(new XmlElement(xmlElement));
}

void XmlElement::AddAttribute(const XmlAttribute & xmlAttribute) {
    this->attributes.push_back(new XmlAttribute(xmlAttribute));
}
