#include <src/XmlElementContent.h>

#include <iostream>
#include <cstring>

#include <lib/catch.hpp>
#include <test/test-utilities.hpp>
#include <test/test-XmlElementContent.hpp>

TEST_CASE("XmlElementContent toString() correctness", "[xmlElementContent]") {
    REQUIRE(testXmlElementContentToString());
}
