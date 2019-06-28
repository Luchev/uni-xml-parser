#pragma once
#include <src/XmlElementEmpty.h>

bool testXmlElementEmptyName() {
    XmlElementEmpty element;
    element.setName("Test name");
    return element.getName() == "Test name";
}

bool testXmlElementEmptyParent() {
    XmlElementEmpty element;
    element.setParent(&element);
    return element.getParent() == &element;
}

bool testXmlElementEmptyAddAttributeCountZero() {
    XmlElementEmpty element;
    element.setName("tag");
    return element.getAttributes().size() == 0;
}

bool testXmlElementEmptyAddAttributeCountOne() {
    XmlElementEmpty element;
    element.setName("tag");
    element.addAttribute(XmlAttribute("name", "value"));
    return element.getAttributes().size() == 1;
}

bool testXmlElementEmptyAddAttributeValueIsCorrect() {
    XmlElementEmpty element;
    element.setName("tag");
    element.addAttribute(XmlAttribute("name", "value"));
    assert(element.getAttributes().size() == 1);
    return element.getAttributes().begin()->getName() == "name" &&
        element.getAttributes().begin()->getValue() == "value";
}

bool testXmlElementEmptyToStringNoAttributes() {
    XmlElementEmpty element;
    element.setName("name1");
    return element.toString() == "<name1/>";
}

bool testXmlElementEmptyToStringOneAttribute() {
    XmlElementEmpty element;
    element.setName("tag");
    element.addAttribute(XmlAttribute("one", "1"));
    return element.toString() == "<tag one=\"1\"/>";
}

bool testXmlElementEmptyToStringTwoAttributes() {
    XmlElementEmpty element;
    element.setName("tag");
    element.addAttribute(XmlAttribute("one", "1"));
    element.addAttribute(XmlAttribute("two", "2"));
    return element.toString() == "<tag one=\"1\" two=\"2\"/>";
}
