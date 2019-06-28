#include <lib/catch.hpp>
#include <test/test-utilities.hpp>
#include <test/test-XmlElementSpecial.hpp>

TEST_CASE("XmlElementSepcial toString() correctness", "[xmlElementSpecial]") {
    REQUIRE(testXmlElementSpecialToStringNoAttributes());
    REQUIRE(testXmlElementSpecialToStringOneAttribute());
    REQUIRE(testXmlElementSpecialToStringTwoAttributes());
}
