#pragma once
#include <src/XmlAttribute.h>
#include <string>
#include <vector>
#include <utility>
/** \file */

/** Represents a tag or the contents between a tag
 */
class XmlTag {
 public:
    /** Constructor
     * \param[in] content - the text to parse into a tag/tag content
     */
    explicit XmlTag(const std::string& content);
    /** Get the original text
     */
    std::string toString() const;
    /** Get the original text (synonym of toString())
     * \return string
     */
    std::string getContent() const;
    /** If it's a tag return its name, else return empty string
     * \return string
     */
    std::string getName() const;
    /** If the tag is valid return a vector of its attributes, else return empty vector
     */
    std::vector<XmlAttribute> getAttributes() const;

    /** Is it a opening tag
     * \return bool
     */
    bool isOpening() const;
    /** Is it a closing tag
     * \return bool
     */
    bool isClosing() const;
    /** Is it a self-closing tag
     * \return bool 
     */
    bool isEmpty() const;
    /** Is it a header tag
     * \return bool
     */
    bool isSpecial() const;
    /** Is it a valid tag
     * \return bool
     */
    bool isValid() const;
    /** Is it an invalid tag (it's tag contents)
     * \return bool
     */
    bool isContents() const;

 private:
    std::string content;

    bool startsWithChar(char character) const;
    bool endsWithChar(char character) const;

    size_t findNameStart() const;
    size_t findNameEnd(size_t start) const;
    size_t findNameEnd() const;

    std::vector<XmlAttribute> getAttributesWithoutValidation() const;
    std::string readXmlAttributeNameStartingFromIndex(size_t* index) const;
    std::string readXmlAttributeValueStartingFromIndex(size_t* index) const;
};
