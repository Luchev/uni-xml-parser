#pragma once
#include <src/XmlAttribute.h>
#include <src/XmlTag.h>
#include <src/XmlElementType.h>
#include <string>
#include <vector>

/** Abstract XML node from the XML tree
 */
class XmlElement {
 public:
    /** Abstract destructor
     */
    virtual ~XmlElement() = 0;
    /** Get the object type
     * \return XmlElementType enum
     */
    XmlElementType getType() const;
    /** Get the element name
     * \return string
     */
    std::string getName() const;
    /** Set the element name
     * \param name - string (the new name)
     */
    void setName(const std::string& name);
    /** Get the parent of the element
     * \return XmlElement pointer (nullptr if there is no parent)
     */
    XmlElement* getParent() const;
    /** Set the parent of the element
     * \param parent - XmlElement pointer to the parent
     */
    void setParent(XmlElement* parent);
    /** Get the grand parent of the element which has no parent of its own (the root of the XML tree)
     * \return XmlElement pointer to the parent
     */
    const XmlElement* getRoot() const;
    /** Get the string representation of the element
     * \return string - the element in the form of a string
     */
    virtual std::string toString() const = 0;
    /** Get the string representation of the element beautified - on new lines
     * \return string - the element in the form of a string
     */
    virtual std::string toStringBeautified() const = 0;
    /** Create a copy on the heap of this object
     * return XmlElement pointer ot the created copy
     */
    virtual XmlElement* clone() const = 0;

 protected:
    /** Enum containing the type of the element
     */
    XmlElementType type;
    /** String containing the name of the element
     */
    std::string name;
    /** XmlElement pointer to the parent (nullptr if no parent)
     */
    XmlElement * parent = nullptr;
};
