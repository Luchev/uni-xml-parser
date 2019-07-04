#pragma once
#include <src/XmlTag.h>
#include <src/XmlElementDefault.h>
#include <string>
#include <vector>
#include <iostream>
/** \file */

/** The XML tree parser
 * 
 * Parse streams of XML (string or file stream) into an XML tree
 * of XML elements. Destructor is not needed as the stream is closed
 * after each parse.
 */
class XmlBuilder {
 public:
    /** Constructor
     * 
     * Initializes the stream to NULL
     */
    XmlBuilder();
    /** Forbid copy constructor
     */
    XmlBuilder(const XmlBuilder&) = delete;
    /** Forbid operator=
     */
    void operator=(const XmlBuilder&) = delete;
    /** Parse file to XML tree
     * 
     * \param[in] path - path to file
     */
    XmlElementDefault* parseFile(const std::string & path);
    /** Parse string to XML tree
     * 
     * \param[in] xml - string containing xml
     */
    XmlElementDefault* parseString(const std::string & xml);

 private:
    std::istream* inputStream = nullptr;

    XmlElementDefault* parseInputStream() const;
    XmlElementDefault* parseXmlTagsToXmlElements(const std::vector<XmlTag>& tags) const;
    std::vector<XmlTag> parseStreamToTags() const;

    XmlElementDefault* addXmlContentToXmlElement(XmlElementDefault* element, const XmlTag& tag) const;
    XmlElementDefault* addXmlEmptyToXmlElement(XmlElementDefault* element, const XmlTag& tag) const;
    XmlElementDefault* addXmlSpecialToXmlElement(XmlElementDefault* element, const XmlTag& tag) const;
    XmlElementDefault* addXmlOpenTagToXmlElement(XmlElementDefault* element, const XmlTag& tag) const;
    XmlElementDefault* addXmlCloseTagToXmlElement(XmlElementDefault* element, const XmlTag& tag) const;

    void openFileStream(const std::string & path);
    void openStringStream(const std::string & string);
    void deleteInputStream();

    XmlTag getTagFromStream() const;
};
