#pragma once
#include <src/XmlBuilder.h>
#include <src/XmlElementDefault.h>
#include <src/File.h>
#include <string>

bool testParseXmlFile(std::string path) {
    XmlBuilder builder;
    XmlElementDefault* root = builder.parseFile(path);
    std::string output = root->toString();
    std::string expectedOutput = File::readFileToString(path);
    return output == expectedOutput;
}

bool testXmlBuilderParseStringEmpty() {
    XmlBuilder builder;
    XmlElementDefault* root = builder.parseString("");
    std::string output = root->toString();
    return output == "";
}

bool testXmlBuilderParseStringNoteXml() {
    XmlBuilder builder;
    std::string input = R"##(<?xml version="1.0" encoding="UTF-8"?><note><to>Tove</to><from>Jani</from></note>)##";
    XmlElementDefault* root = builder.parseString(input);
    std::string output = root->toString();
    return output == input;
}

bool testXmlBuilderParseFileNoteXml() {
    return testParseXmlFile("data/note.xml");
}

bool testXmlBuilderParseFileBreakfastMenuXml() {
    return testParseXmlFile("data/breakfast_menu.xml");
}

bool testXmlBuilderParseFileCdCatalogXml() {
    return testParseXmlFile("data/cd_catalog.xml");
}

bool testXmlBuilderParseFileEmailsXml() {
    return testParseXmlFile("data/emails.xml");
}

bool testXmlBuilderParseFileHtmlHeadXml() {
    return testParseXmlFile("data/html-head.xml");
}

bool testXmlBuilderParseFileHtmlHeadingsXml() {
    return testParseXmlFile("data/html-headings.xml");
}

bool testXmlBuilderParseFileHtmlITagXml() {
    return testParseXmlFile("data/html-i-tag.xml");
}


bool testXmlBuilderParseFileHtmlImageXml() {
    return testParseXmlFile("data/html-image.xml");
}

bool testXmlBuilderParseFileHtmlSpanInPXml() {
    return testParseXmlFile("data/html-span-in-p.xml");
}
