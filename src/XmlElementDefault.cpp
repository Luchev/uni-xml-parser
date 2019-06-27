#include <src/XmlElementDefault.h>

XmlElementDefault::XmlElementDefault() {
    type = XmlElementType::Default;
}

XmlElementDefault::XmlElementDefault(const XmlElementDefault& rhs) {
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
    return "";
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
