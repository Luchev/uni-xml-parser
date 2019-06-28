#include <src/XmlElementContent.h>
#include <string>

XmlElementContent::XmlElementContent(const std::string& content) {
    type = XmlElementType::Content;
    this->content = content;
}

std::string XmlElementContent::toString() const {
    return content;
}

XmlElement* XmlElementContent::clone() const {
    return new XmlElementContent(*this);
}

void XmlElementContent::setContent(const std::string& content) {
    this->content = content;
}

std::string XmlElementContent::toStringBeautified() const {
    return toString() + "\n";
}
