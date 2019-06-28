#pragma once
#include <src/XmlAttribute.h>
#include <src/XmlConfig.h>
#include <string>

bool testXmlAttributeGetName() {
    XmlAttribute attribute("name1", "value1");
    return attribute.getName() == "name1";
}

bool testXmlAttributeGetValue() {
    XmlAttribute attribute("name1", "value1");
    return attribute.getValue() == "value1";
}

bool testXmlAttributeToString() {
    XmlAttribute attribute("name1", "value1");
    std::string quote = XmlConfig::getInstance()->getOutputQuote();
    return attribute.toString() == "name1=" + quote + "value1" + quote;
}

bool testXmlAttributeToStringCompactQuotes() {
    XmlAttribute attribute("attr", "12 14");
    std::string quote = XmlConfig::getInstance()->getOutputQuote();
    return attribute.toString() == "attr=\"12 14\"";
}

bool testXmlAttributeIsNamelessTrue() {
    XmlAttribute attribute("", "val");
    return attribute.isNameless() == true;
}

bool testXmlAttributeIsNamelessFalse() {
    XmlAttribute attribute("name", "val");
    return attribute.isNameless() == false;
}
