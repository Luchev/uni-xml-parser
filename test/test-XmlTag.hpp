#pragma once
#include <src/XmlTag.h>

bool testXmlTagConstructorWithCorrectOpenTag() {
    XmlTag tag("<tag>");
    return tag.getName() == "tag";
}

bool testXmlTagConstructorWithCorrectCloseTag() {
    XmlTag tag("</tag>");
    return tag.getName() == "tag";
}

bool testXmlTagConstructorWithCorrectSpecialTag() {
    XmlTag tag("<?xml version=1.0 encoding=UTF-8?>");
    return tag.getName() == "xml";
}

bool testXmlTagConstructorWithIncorrectInput() {
    XmlTag tag("<tag");
    return tag.getName() == "";
}

bool testXmlTagConstructorForTrimming() {
    XmlTag tag("    <tag attr1=one>   ");
    return tag.getName() == "tag";
}

bool testXmlTagToString() {
    XmlTag tag("    <tag attr1=one>   ");
    return tag.toString() == "<tag attr1=one>";
}

bool testXmlTagIsOpeningWithOpenTag() {
    XmlTag tag("<tag>");
    return tag.isOpening() == true;
}

bool testXmlTagIsOpeningWithCloseTag() {
    XmlTag tag("</tag>");
    return tag.isOpening() == false;
}

bool testXmlTagIsClosingWithOpenTag() {
    XmlTag tag("<tag>");
    return tag.isClosing() == false;
}

bool testXmlTagIsClosingWithCloseTag() {
    XmlTag tag("</tag>");
    return tag.isClosing() == true;
}

bool testXmlTagIsSelfClosingWithSelfClosing() {
    XmlTag tag("<tag />");
    return tag.isSelfClosing() == true;
}

bool testXmlTagIsSelfClosingWithOpenTag() {
    XmlTag tag("<tag>");
    return tag.isSelfClosing() == false;
}

bool testXmlTagIsSelfClosingWithCloseTag() {
    XmlTag tag("</tag>");
    return tag.isSelfClosing() == false;
}

bool testXmlTagGetNameCorrectTag() {
    XmlTag tag("< tag attribute=one >");
    return tag.getName() == "tag";
}

bool testXmlTagGetNameIncorrectTag() {
    XmlTag tag(" tag attribute=one >");
    return tag.getName() == "";
}

bool testXmlTagGetNameOpenTag() {
    XmlTag tag("<tag>");
    return tag.getName() == "tag";
}

bool testXmlTagGetNameCloseTag() {
    XmlTag tag("</tag>");
    return tag.getName() == "tag";
}

bool testXmlTagGetNameSpecialTag() {
    XmlTag tag("<?tag?>");
    return tag.getName() == "tag";
}

bool testXmlTagGetNameSelfClosingTag() {
    XmlTag tag("<tag/>");
    return tag.getName() == "tag";
}

bool testXmlTagIsValidTrue() {
    XmlTag tag("<tag>");
    return tag.isValid() == true;
}

bool testXmlTagIsValidFalse() {
    XmlTag tag("<tag<");
    return tag.isValid() == false;
}

bool testIsContentsTrue() {
    XmlTag tag("<tag<");
    return tag.isContents() == true;
}

bool testIsContentsFalse() {
    XmlTag tag("<tag>");
    return tag.isContents() == false;
}

bool testIsEmptyTrue() {
    XmlTag tag("");
    return tag.isEmpty() == true;
}

bool testIsEmptyFalse() {
    XmlTag tag("<tag>");
    return tag.isEmpty() == false;
}
