#pragma once
#include <src/XmlElementEmpty.h>
#include <string>
#include <vector>

/** Represents an open-close tag with its child elements
 */
class XmlElementDefault : public XmlElementEmpty {
 public:
    /** Constructor
     * \param name - the name of the tag
     */
    explicit XmlElementDefault(const std::string& name = "");
    /** Constructor
     * \param name - the name of the tag
     * \param attributes - vector of XML attributes
     */
    XmlElementDefault(const std::string& name, const std::vector<XmlAttribute>& attributes);
    /** Copy constructor
     * \param rhs - the object to copy
     */
    XmlElementDefault(const XmlElementDefault& rhs);
    /** Copy constructor
     * \param rhs - the object to copy
     */
    XmlElementDefault& operator=(const XmlElementDefault& rhs);
    /** Destructor
     */
    ~XmlElementDefault();

    /** Add a child XML element
     * 
     * Add a clone of the parameter
     * \param element - pointer to the object to add a copy of
     */
    void addChildElement(const XmlElement* element);
    /** Get the number of child elements
     * \return size_t - number of direct chil elements
     */
    size_t getNumberOfChildren() const;
    /** Get the child at some index (used to iterate the children)
     * \param index - index of the child
     * \return XmlElement pointer - pointer to the given child
     * \throws std::out_of_range
     */
    XmlElement* getChild(size_t index);

    /** Does the element have an empty name (is it a root element)
     * \return bool
     */
    bool isNameless() const;

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
    std::vector<XmlElement*> children;

    void copyXmlElementDefault(const XmlElementDefault& element);
    void setChildren(const std::vector<XmlElement*>& children);
    void deleteChildren();

    std::string toStringOpenTag() const;
    std::string toStringCloseTag() const;
};
