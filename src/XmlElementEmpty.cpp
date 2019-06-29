#include <src/XmlElementEmpty.h>

XmlElementEmpty::XmlElementEmpty(const std::string& name) {
    type = XmlElementType::Empty;
    this->name = name;
}

XmlElementEmpty::
XmlElementEmpty(const std::string& name, const std::vector<XmlAttribute> attributes) {
    type = XmlElementType::Empty;
    this->name = name;
    this->attributes = attributes;
}

void XmlElementEmpty::addAttribute(const XmlAttribute& attribute) {
    attributes.push_back(attribute);
}

std::vector<XmlAttribute> XmlElementEmpty::getAttributes() const {
    return attributes;
}

void XmlElementEmpty::setAttributes(const std::vector<XmlAttribute>& attributes) {
    this->attributes = attributes;
}

std::string XmlElementEmpty::toString() const {
    std::string output;
    output += '<';
    output += getName();

    for (XmlAttribute attribute : attributes) {
        output += ' ';
        output += attribute.toString();
    }

    output += "/>";
    return output;
}

std::string XmlElementEmpty::toStringBeautified() const {
    return toString() + "\n";
}

XmlElement* XmlElementEmpty::clone() const {
    return new XmlElementEmpty(*this);
}
