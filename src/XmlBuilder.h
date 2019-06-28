#pragma once
#include <src/XmlTag.h>
#include <src/XmlElementDefault.h>
#include <string>
#include <vector>
#include <iostream>

class XmlBuilder {
 public:
    XmlBuilder();
    void operator=(const XmlBuilder&) = delete;
    XmlBuilder(const XmlBuilder&) = delete;
    ~XmlBuilder();

    XmlElementDefault* parseFile(const std::string & path);
    XmlElementDefault* parseString(const std::string & xml);

 private:
    std::istream* inputStream = nullptr;

    XmlElementDefault* parseInputStream() const;
    XmlElementDefault* parseXmlTagsToXmlElements(const std::vector<XmlTag>& tags) const;
    std::vector<XmlTag> parseStreamToTags() const;

    void openFileStream(const std::string & path);
    void openStringStream(const std::string & string);
    void deleteInputStream();
};
