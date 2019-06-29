#pragma once
#include <src/XmlTag.h>
#include <src/XmlElementDefault.h>
#include <string>
#include <vector>
#include <iostream>

class XmlBuilder {
 public:
    XmlBuilder();
    XmlBuilder(const XmlBuilder&) = delete;
    void operator=(const XmlBuilder&) = delete;

    XmlElementDefault* parseFile(const std::string & path);
    XmlElementDefault* parseString(const std::string & xml);

 private:
    std::istream* inputStream = nullptr;

    XmlElementDefault* parseInputStream() const;
    XmlElementDefault* parseXmlTagsToXmlElements(const std::vector<XmlTag>& tags) const;
    std::vector<XmlTag> parseStreamToTags() const;

    XmlElementDefault* addXmlContentToXmlElement(XmlElementDefault* root, const XmlTag& tag) const;
    XmlElementDefault* addXmlEmptyToXmlElement(XmlElementDefault* root, const XmlTag& tag) const;
    XmlElementDefault* addXmlSpecialToXmlElement(XmlElementDefault* root, const XmlTag& tag) const;
    XmlElementDefault* addXmlOpenTagToXmlElement(XmlElementDefault* root, const XmlTag& tag) const;
    XmlElementDefault* addXmlCloseTagToXmlElement(XmlElementDefault* root, const XmlTag& tag) const;

    void openFileStream(const std::string & path);
    void openStringStream(const std::string & string);
    void deleteInputStream();

    XmlTag getTagFromStream() const;
};
