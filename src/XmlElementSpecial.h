#pragma once
#include <src/XmlElementEmpty.h>
#include <string>
#include <vector>

/** Represents a header XML tag
 */
class XmlElementSpecial : public XmlElementEmpty {
 public:
    /** Constructor
     * \param name - the name of the tag
     */
    explicit XmlElementSpecial(const std::string& name = "");
    /** Constructor
     * \param name - the name of the tag
     * \param attributes - vector of XML attributes
     */
    XmlElementSpecial(const std::string& name, const std::vector<XmlAttribute> attributes);

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
};
