#include <lib/catch.hpp>
#include <test/test-utilities.hpp>
#include <test/test-XmlElementDefault.hpp>

TEST_CASE("XmlElementDefault addChildElement() correctness", "[xmlElementDefault]") {
    REQUIRE(testXmlElementDefaultAddChildCountOneChild());
    REQUIRE(testXmlElementDefaultAddChildCountTwoChildren());
}

TEST_CASE("XmlElementContent toString() correctness", "[xmlElementDefault]") {
    REQUIRE(testXmlElementDefaultToStringEmptyTag());
    REQUIRE(testXmlElementDefaultToStringWithOneChild());
    REQUIRE(testXmlElementDefaultToStringWithChildInChild());
}
