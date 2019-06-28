#include <src/XmlElementDefault.h>
#include <include/XmlElements.h>
#include <iostream>

XmlElementDefault::XmlElementDefault(const std::string& name) {
    type = XmlElementType::Default;
    this->name = name;
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

void XmlElementDefault::deleteChildren() {
    for (XmlElement* child : children) {
        delete child;
    }
    children.resize(0);
}

void XmlElementDefault::setChildren(const std::vector<XmlElement*>& children) {
    for (XmlElement* child : children) {
        this->children.push_back(child->clone());
    }
}

void XmlElementDefault::
copyXmlElementDefault(const XmlElementDefault& element) {
    XmlElementEmpty::operator=(element);
    setChildren(element.children);
}

XmlElement* XmlElementDefault::clone() const {
    return new XmlElementDefault(*this);
}

std::vector<XmlElement*> XmlElementDefault::getChildElements() const {
    return children;
}
