#pragma once
#include <src/XmlElement.h>
#include <string>

/** The text between an open and close tags
 */
class XmlElementContent : public XmlElement {
 public:
    /** Constructor
     * \param[in] content - string (the actual text between the open and close tags)
     */
    explicit XmlElementContent(const std::string& content = "");
    /** Get the content text
     * \return string - the content
     */
    std::string getContent() const;
    /** Set the content text
     * \param[in] content - string containing the content
     */
    void setContent(const std::string& content);
    /** Get the string representation of the element
     * \return string - the element in the form of a string
     */
    std::string toString() const override;
    /** Get the string representation of the element beautified - on new lines
     * \return string - the element in the form of a string
     */
    std::string toStringBeautified() const override;
    /** Create a copy on the heap of this object
     * return XmlElement pointer ot the created copy
     */
    XmlElement* clone() const override;

 private:
    std::string content;
};
