#include <src/XmlElement.h>
#include <src/XmlAttribute.h>

XmlElement::~XmlElement() {
    // Intentionally empy - has nothing to delete
}

XmlElementType XmlElement::getType() const {
    return this->type;
}

std::string XmlElement::getName() const {
    return this->name;
}

void XmlElement::setName(const std::string& name) {
    this->name = name;
}

XmlElement* XmlElement::getParent() const {
    return parent;
}

void XmlElement::setParent(XmlElement* parent) {
    this->parent = parent;
}

const XmlElement* XmlElement::getRoot() const {
    const XmlElement* root = this;

    while (root->getParent() != nullptr) {
        root = parent;
    }

    return root;
}
