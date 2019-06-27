#pragma once
#include <src/XmlElementSpecial.h>

bool testXmlElementSpecialToStringNoAttributes() {
    XmlElementSpecial element;
    element.setName("xml");
    return element.toString() == "<?xml?>";
}

bool testXmlElementSpecialToStringOneAttribute() {
    XmlElementSpecial element;
    element.setName("xml");
    element.addAttribute(XmlAttribute("version", "1.0"));
    return element.toString() == "<?xml version=\"1.0\"?>";
}

bool testXmlElementSpecialToStringTwoAttributes() {
    XmlElementSpecial element;
    element.setName("xml");
    element.addAttribute(XmlAttribute("version", "1.0"));
    element.addAttribute(XmlAttribute("encoding", "UTF-8"));
    return element.toString() == "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
}
