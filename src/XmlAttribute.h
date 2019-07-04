#pragma once
#include <string>
#include <vector>

/** Represents an xml attribute
 * 
 * Can be thought of as a name-value pair
 * e.g: attributeName = "attributeValue"
 */
class XmlAttribute {
 public:
    /** Constructor
     * 
     * Create a new object with the given parameters
     * Trims the name to see if it's valid
     * \param[in] name - xml attribute name
     * \param[in] value - xml attribute value
     * \throws std::invalid_argument
     */
    XmlAttribute(std::string name, std::string value);
    /** Return the name
     * \return string - the xml attribute name
     */
    std::string getName() const;
    /** Return the value
     * \return string - the xml attribute value
     */
    std::string getValue() const;
    /** Return the xml attribute formatted as a string
     * \return string - the name and value looking like a proper xml (e.g name="value")
     */
    std::string toString() const;
    /** Return the xml attribute formatted as a string and try to not use quotes if possible
     * \return string - the name and value looking like a proper xml (e.g if the value has no spaces name=value, toString() otherwise)
     */
    std::string toStringCompact() const;
    /** Is the tag nameless, aka the name is an empty string
     * \return bool
     */
    bool isNameless() const;

 private:
    std::string name;
    std::string value;

    void validateAttributeParameters(const std::string& name, const std::string& value);
};
