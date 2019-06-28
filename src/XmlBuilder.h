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
    std::istream* inputStream;

    void deleteInputStream();
    void createCleanInputStream();
    void openFileStream(const std::string & path);
    void openStringStream(const std::string & string);

    XmlElementDefault* parse();
    XmlElementDefault* parseInputStreamToXml() const;
    std::vector<XmlTag> parseStreamToTags() const;
    XmlElementDefault* parseXmlTagsToXmlElements(const std::vector<XmlTag>& tags) const;
};
