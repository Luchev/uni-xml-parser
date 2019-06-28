#include <src/XmlAttribute.h>
#include <src/CharacterSet.h>
#include <src/StringExtension.h>
#include <src/XmlConfig.h>
#include <string>
#include <stdexcept>

XmlAttribute::XmlAttribute(const std::string& name, const std::string& value) {
    this->name = name;
    this->value = value;
    StringExtension::trim(&this->name);
    StringExtension::trim(&this->value);
    validateAttributeParameters(name, value);
}

std::string XmlAttribute::getName() const {
    return this->name;
}

std::string XmlAttribute::getValue() const {
    return this->value;
}

std::string XmlAttribute::toString() const {
    std::string quote = XmlConfig::getInstance()->getOutputQuote();
    if (!isNameless()) {
        return this->name + "=" + quote + this->value + quote;
    } else {
        return this->value;
    }
}

std::string XmlAttribute::toStringCompact() const {
    std::string quote = XmlConfig::getInstance()->getOutputQuote();
    if (CharacterSet::hasWhiteSpace(this->value)) {
        return toString();
    } else {
        return this->name + "=" + this->value;
    }
}

bool XmlAttribute::isNameless() const {
    return name.length() == 0;
}

void XmlAttribute::validateAttributeParameters(const std::string& name, const std::string& value) {
    if (name == "" && CharacterSet::hasWhiteSpace(value)) {
        throw std::invalid_argument("Nameless xml attribute must have value with no spaces");
    }
}
