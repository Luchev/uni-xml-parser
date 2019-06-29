#include <src/XmlElementDefault.h>
#include <include/XmlElements.h>
#include <src/StringExtension.h>
#include <iostream>

XmlElementDefault::XmlElementDefault(const std::string& name) {
    type = XmlElementType::Default;
    this->name = name;
}

XmlElementDefault::
XmlElementDefault(const std::string& name, const std::vector<XmlAttribute>& attributes) {
    type = XmlElementType::Default;
    this->name = name;
    this->attributes = attributes;
}

XmlElementDefault::XmlElementDefault(const XmlElementDefault& rhs) : XmlElementEmpty(rhs) {
    copyXmlElementDefault(rhs);
}

XmlElementDefault& XmlElementDefault::operator=(const XmlElementDefault& rhs) {
    if (this != &rhs) {
        deleteChildren();
        copyXmlElementDefault(rhs);
    }
    return *this;
}

XmlElementDefault::~XmlElementDefault() {
    deleteChildren();
}

void XmlElementDefault::addChildElement(const XmlElement* element) {
    this->children.push_back(element->clone());
}

size_t XmlElementDefault::getNumberOfChildren() const {
    return this->children.size();
}

std::string XmlElementDefault::toString() const {
    std::string output;
    output += toStringOpenTag();

    for (XmlElement* child : children) {
        output += child->toString();
    }

    output += toStringCloseTag();
    return output;
}

std::string XmlElementDefault::toStringBeautified() const {
    std::string output;
    output += toStringOpenTag();
    output += '\n';

    for (XmlElement* child : children) {
        output += child->toStringBeautified();
    }

    output += toStringCloseTag();
    output += '\n';
    StringExtension::trim(&output);

    return output;
}

XmlElement* XmlElementDefault::clone() const {
    return new XmlElementDefault(*this);
}

void XmlElementDefault::copyXmlElementDefault(const XmlElementDefault& element) {
    XmlElementEmpty::operator=(element);
    setChildren(element.children);
}

void XmlElementDefault::setChildren(const std::vector<XmlElement*>& children) {
    for (XmlElement* child : children) {
        this->children.push_back(child->clone());
    }
}

void XmlElementDefault::deleteChildren() {
    for (XmlElement* child : children) {
        delete child;
    }

    children.clear();
}

XmlElement* XmlElementDefault::getChild(size_t index) {
    if (index >= children.size()) {
        throw std::out_of_range("Cannot get " + std::to_string(index) +
            " child xml element. There are only " + std::to_string(this->children.size()) +
            " child elements");
    }

    return children[index];
}

bool XmlElementDefault::isNameless() const {
    return this->name.size() == 0;
}

std::string XmlElementDefault::toStringOpenTag() const {
    if (isNameless()) {
        return "";
    }

    std::string output;
    output += '<';
    output += getName();

    for (XmlAttribute attribute : attributes) {
        output += ' ';
        output += attribute.toString();
    }

    output += '>';

    return output;
}

std::string XmlElementDefault::toStringCloseTag() const {
    if (isNameless()) {
        return "";
    }

    std::string output;
    output += '<';
    output += '/';
    output += getName();
    output += ">";

    return output;
}
