#pragma once
#include <src/XmlBuilder.h>
#include <src/XmlElementDefault.h>
#include <string>

bool testXmlBuilderParseStringEmpty() {
    XmlBuilder builder;
    XmlElementDefault* root = builder.parseString("");
    std::string output = root->toString();
    return output == "";
}

bool testXmlBuilderParseStringNoteXml() {
    XmlBuilder builder;
    std::string input = R"##(<?xml version="1.0" encoding="UTF-8"?><note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>)##";
    XmlElementDefault* root = builder.parseString(input);
    std::string output = root->toString();
    return output == input;
}

bool testXmlBuilderParseFileNoteXml() {
    XmlBuilder builder;
    XmlElementDefault* root = builder.parseFile("data/note.xml");
    std::string output = root->toString();
    std::string expectedOutput = R"##(<?xml version="1.0" encoding="UTF-8"?><note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>)##";
    return output == expectedOutput;
}
