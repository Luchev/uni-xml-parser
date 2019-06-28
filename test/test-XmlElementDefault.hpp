#pragma once
#include <src/XmlElementDefault.h>
#include <src/XmlElementEmpty.h>
#include <src/XmlElementContent.h>
#include <string>

bool testXmlElementDefaultAddChildCountOneChild() {
    XmlElementDefault element;
    element.setName("tag");
    XmlElementEmpty empty;
    empty.setName("empty");
    element.addChildElement(&empty);
    return element.getNumberOfChildren() == 1;
}

bool testXmlElementDefaultAddChildCountTwoChildren() {
    XmlElementDefault element;
    element.setName("tag");
    XmlElementEmpty empty;
    empty.setName("empty");
    element.addChildElement(&empty);
    element.addChildElement(&empty);
    return element.getNumberOfChildren() == 2;
}

bool testXmlElementDefaultToStringEmptyTag() {
    XmlElementDefault element;
    element.setName("tag");
    return element.toString() == "<tag></tag>";
}

bool testXmlElementDefaultToStringWithOneChild() {
    XmlElementDefault element;
    element.setName("tag");
    XmlElementEmpty empty;
    empty.setName("empty");
    element.addChildElement(&empty);
    return element.toString() == "<tag><empty/></tag>";
}

bool testXmlElementDefaultToStringWithChildInChild() {
    XmlElementDefault one;
    one.setName("one");
    XmlElementDefault two;
    two.setName("two");
    XmlElementContent content("text");
    two.addChildElement(&content);
    one.addChildElement(&two);
    return one.toString() == "<one><two>text</two></one>";
}
