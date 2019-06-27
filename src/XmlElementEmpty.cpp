#include <src/XmlElementEmpty.h>

XmlElementEmpty::XmlElementEmpty() {
    type = XmlElementType::Empty;
}

void XmlElementEmpty::addAttribute(const XmlAttribute& attribute) {
    attributes.push_back(attribute);
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

XmlElement* XmlElementEmpty::clone() const {
    return new XmlElementEmpty(*this);
}

std::vector<XmlAttribute> XmlElementEmpty::getAttributes() const {
    return attributes;
}
