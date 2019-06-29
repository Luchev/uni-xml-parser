#include <src/XmlElementSpecial.h>

XmlElementSpecial::XmlElementSpecial(const std::string& name) {
    type = XmlElementType::Special;
    this->name = name;
}

XmlElementSpecial::
XmlElementSpecial(const std::string& name, const std::vector<XmlAttribute> attributes) {
    type = XmlElementType::Special;
    this->name = name;
    this->attributes = attributes;
}

std::string XmlElementSpecial::toString() const {
    std::string output;
    output += '<';
    output += '?';
    output += getName();
    for (XmlAttribute attribute : attributes) {
        output += ' ';
        output += attribute.toString();
    }
    output += '?';
    output += '>';
    return output;
}

XmlElement* XmlElementSpecial::clone() const {
    return new XmlElementSpecial(*this);
}
