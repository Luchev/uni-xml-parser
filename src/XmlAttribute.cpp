#include <src/XmlAttribute.h>

#include <src/CharacterSet.h>

#include <string>

XmlAttribute::XmlAttribute(const std::string& name, const std::string& value) {
    this->name = name;
    this->value = value;
}

std::string XmlAttribute::getName() const {
    return this->value;
}

std::string XmlAttribute::getValue() const {
    return this->value;
}

std::string XmlAttribute::toString() const {
    return this->name + " = \"" + this->value + "\"";
}

std::string XmlAttribute::toStringCompact() const {
    if (CharacterSet::hasWhiteSpace(value)) {
        return this->name + "=\"" + this->value + "\"";
    } else {
        return this->name + "=" + this->value;
    }
}
