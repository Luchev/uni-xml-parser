#include <src/XmlElementDefault.h>

#include <iostream>
#include <cstring>

#include <lib/catch.hpp>
#include <test/test-utilities.hpp>
#include <test/test-XmlElementDefault.hpp>

TEST_CASE("XmlElementDefault addChildElement() correctness", "[xmlElementDefault]") {
    REQUIRE(testXmlElementDefaultAddChildCountOneChild());
}

TEST_CASE("XmlElementContent toString() correctness", "[xmlElementDefault]") {
    REQUIRE(testXmlElementDefaultToStringEmptyTag());
    REQUIRE(testXmlElementDefaultToStringWithOneChild());
    REQUIRE(testXmlElementDefaultToStringWithChildInChild());
}
