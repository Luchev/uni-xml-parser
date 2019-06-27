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
