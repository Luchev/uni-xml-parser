#include <src/XmlElementEmpty.h>

#include <iostream>
#include <cstring>

#include <lib/catch.hpp>
#include <test/test-utilities.hpp>
#include <test/test-XmlElementEmpty.hpp>

TEST_CASE("XmlElement set/getName() correctness", "[xmlElement]") {
    REQUIRE(testXmlElementEmptyName());
}

TEST_CASE("XmlElement set/getParent() correctness", "[xmlElement]") {
    REQUIRE(testXmlElementEmptyParent());
}

TEST_CASE("XmlElement addAttribute() correctness", "[xmlElementEmpty]") {
    REQUIRE(testXmlElementEmptyAddAttributeCountZero());
    REQUIRE(testXmlElementEmptyAddAttributeCountOne());
    REQUIRE(testXmlElementEmptyAddAttributeValueIsCorrect());
}

TEST_CASE("XmlElement toString() correctness", "[xmlElementEmpty]") {
    REQUIRE(testXmlElementEmptyToStringNoAttributes());
    REQUIRE(testXmlElementEmptyToStringOneAttribute());
    REQUIRE(testXmlElementEmptyToStringTwoAttributes());
}
