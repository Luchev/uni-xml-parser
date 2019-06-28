#pragma once
#include <src/XmlElementContent.h>
#include <string>

bool testXmlElementContentToString() {
    XmlElementContent content("some text");
    return content.toString() == "some text";
}
