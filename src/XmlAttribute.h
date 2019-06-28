#pragma once
#include <string>
#include <vector>

class XmlAttribute {
 public:
    XmlAttribute(const std::string& name, const std::string& value);

    std::string getName() const;
    std::string getValue() const;

    std::string toString() const;
    std::string toStringCompact() const;

    bool isNameless() const;

 private:
    std::string name;
    std::string value;

    void validateAttributeParameters(const std::string& name, const std::string& value);
};
