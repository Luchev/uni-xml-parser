#include <src/XmlElementContent.h>
#include <string>

XmlElementContent::XmlElementContent(const std::string& content) {
    type = XmlElementType::Content;
    this->content = content;
}

std::string XmlElementContent::getContent() const {
    return this->content;
}

void XmlElementContent::setContent(const std::string& content) {
    this->content = content;
}

std::string XmlElementContent::toString() const {
    return getContent();
}

std::string XmlElementContent::toStringBeautified() const {
    return toString() + "\n";
}

XmlElement* XmlElementContent::clone() const {
    return new XmlElementContent(*this);
}
