#include <lib/catch.hpp>
#include <test/test-utilities.hpp>
#include <test/test-XmlBuilder.hpp>

TEST_CASE("XmlBuilder parseString() correctness", "[xmlBuilder]") {
    REQUIRE(testXmlBuilderParseStringEmpty());
    REQUIRE(testXmlBuilderParseStringNoteXml());
}

TEST_CASE("XmlBuilder parseFile() correctness", "[xmlBuilder]") {
    REQUIRE(testXmlBuilderParseFileBreakfastMenuXml());
    REQUIRE(testXmlBuilderParseFileCdCatalogXml());
    REQUIRE(testXmlBuilderParseFileEmailsXml());
    REQUIRE(testXmlBuilderParseFileEmailsXml());
    REQUIRE(testXmlBuilderParseFileHtmlHeadXml());
    REQUIRE(testXmlBuilderParseFileHtmlHeadingsXml());
    REQUIRE(testXmlBuilderParseFileHtmlITagXml());
    REQUIRE(testXmlBuilderParseFileHtmlImageXml());
    REQUIRE(testXmlBuilderParseFileHtmlSpanInPXml());
    REQUIRE(testXmlBuilderParseFileNoteXml());
}
