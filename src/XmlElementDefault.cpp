#include <src/XmlElementDefault.h>
#include <include/XmlElements.h>
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

void XmlElementDefault::addChildElement(const XmlElement* xmlElement) {
    this->children.push_back(xmlElement->clone());
}

XmlElement* XmlElementDefault::getLastChild() {
    if (this->children.size() == 0) {
        throw std::out_of_range("Cannot get last child xml element. There are no child elements.");
    }
    return getChild(this->children.size() - 1);
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
    if (name.length() > 0) {
        output += '\n';
    }
    for (XmlElement* child : children) {
        output += child->toStringBeautified();
    }
    output += toStringCloseTag();
    if (name.length() > 0) {
        output += '\n';
    }
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
    children.resize(0);
}

XmlElement* XmlElementDefault::getChild(size_t index) {
    if (index >= children.size()) {
        throw std::out_of_range("Cannot get " + std::to_string(index) +
            " child xml element. There are only " + std::to_string(this->children.size()) +
            " child elements");
    }
    return children[index];
}

std::string XmlElementDefault::toStringOpenTag() const {
    if (name.length() == 0) {
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
    if (name.length() == 0) {
        return "";
    }
    std::string output;
    output += '<';
    output += '/';
    output += getName();
    output += ">";
    return output;
}
