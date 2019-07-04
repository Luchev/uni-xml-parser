#pragma once
#include <src/XmlElement.h>
#include <src/XmlAttribute.h>
#include <string>
#include <vector>
/** \file */

/** XML element representing a self-closing tag
 */
class XmlElementEmpty : public XmlElement {
 public:
    /** Constructor
     * \param[in] name - the name of the tag
     */
    explicit XmlElementEmpty(const std::string& name = "");
    /** Constructor
     * \param[in] name - the name of the tag
     * \param[in] attributes - vector of XML attributes
     */
    XmlElementEmpty(const std::string& name, const std::vector<XmlAttribute> attributes);
    /** Add XML attribute
     * \param[in] attribute - the new attribute to add
     */
    void addAttribute(const XmlAttribute& attribute);
    /** Get all the attributes
     */
    std::vector<XmlAttribute> getAttributes() const;
    /** Set all the attributes, deleting the old ones
     * \return vector of attributes
     */
    void setAttributes(const std::vector<XmlAttribute>& attributes);
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

 protected:
    /** Vector of the attributes the element contains
     */
    std::vector<XmlAttribute> attributes;
};
