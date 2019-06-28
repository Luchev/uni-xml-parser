#include <src/XmlBuilder.h>

#include <iostream>
#include <cstring>

#include <lib/catch.hpp>
#include <test/test-utilities.hpp>
#include <test/test-XmlBuilder.hpp>

TEST_CASE("XmlBuilder parseString() correctness", "[xmlBuilder]") {
    REQUIRE(testXmlBuilderParseStringEmpty());
    REQUIRE(testXmlBuilderParseStringNoteXml());
}

TEST_CASE("XmlBuilder parseFile() correctness", "[xmlBuilder]") {
    REQUIRE(testXmlBuilderParseFileNoteXml());
}
