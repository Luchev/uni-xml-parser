#include <src/XmlAttribute.h>

#include <iostream>
#include <cstring>

#include <lib/catch.hpp>
#include <test/test-utilities.hpp>
#include <test/test-XmlAttribute.hpp>

TEST_CASE("XmlAttribute getName() correctness", "[xmlAttribute]") {
    REQUIRE(testXmlAttributeGetName());
}

TEST_CASE("XmlAttribute getValue() correctness", "[xmlAttribute]") {
    REQUIRE(testXmlAttributeGetValue());
}

TEST_CASE("XmlAttribute toString() correctness", "[xmlAttribute]") {
    REQUIRE(testXmlAttributeToString());
}

TEST_CASE("XmlAttribute toStringCompact() correctness", "[xmlAttribute]") {
    REQUIRE(testXmlAttributeToStringCompactQuotes());
}
