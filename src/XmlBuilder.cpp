#include <src/XmlBuilder.h>
#include <src/StringExtension.h>
#include <include/XmlElements.h>
#include <src/XmlFactory.h>
#include <src/Logger.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

XmlBuilder::XmlBuilder() {
    // Intentionally empty - nothing to initialize
}

XmlElementDefault* XmlBuilder::parseFile(const std::string& path) {
    try {
        openFileStream(path);
    } catch (const std::invalid_argument& ex) {
        Logger::error("Failed to create file stream: " + std::string(ex.what()));
        return new XmlElementDefault;
    }
    XmlElementDefault* root = parseInputStream();
    deleteInputStream();
    return root;
}

XmlElementDefault* XmlBuilder::parseString(const std::string& xml) {
    try {
        openStringStream(xml);
    } catch (const std::invalid_argument& ex) {
        Logger::error("Failed to create string stream: " + std::string(ex.what()));
        return new XmlElementDefault;
    }
    XmlElementDefault* root = parseInputStream();
    deleteInputStream();
    return root;
}

XmlElementDefault* XmlBuilder::parseInputStream() const {
    std::vector<XmlTag> tags = parseStreamToTags();
    try {
        XmlElementDefault* root = parseXmlTagsToXmlElements(tags);
        return root;
    } catch (const std::invalid_argument& ex) {
        Logger::error("Failed parsing xml: " + std::string(ex.what()));
        return new XmlElementDefault;
    } catch (const std::domain_error& ex) {
        Logger::error("Failed parsing xml: " + std::string(ex.what()));
        return new XmlElementDefault;
    }
}

XmlElementDefault* XmlBuilder::
addXmlContentToXmlElement(XmlElementDefault* root, const XmlTag& tag) const {
    XmlElementContent contentElement(tag.toString());
    root->addChildElement(&contentElement);
    return root;
}

XmlElementDefault* XmlBuilder::
addXmlEmptyToXmlElement(XmlElementDefault* root, const XmlTag& tag) const {
    XmlElementEmpty emptyElement(tag.getName(), tag.getAttributes());
    root->addChildElement(&emptyElement);
    return root;
}

XmlElementDefault* XmlBuilder::
addXmlSpecialToXmlElement(XmlElementDefault* root, const XmlTag& tag) const {
    XmlElementSpecial specialElement(tag.getName(), tag.getAttributes());
    root->addChildElement(&specialElement);
    return root;
}

XmlElementDefault* XmlBuilder::
addXmlOpenTagToXmlElement(XmlElementDefault* root, const XmlTag& tag) const {
    XmlElementDefault defaultElement(tag.getName(), tag.getAttributes());
    defaultElement.setParent(root);
    root->addChildElement(&defaultElement);
    XmlElement* justAddedElement = root->getLastChild();
    root = dynamic_cast<XmlElementDefault*>(justAddedElement);
    return root;
}

XmlElementDefault* XmlBuilder::
addXmlCloseTagToXmlElement(XmlElementDefault* root, const XmlTag& tag) const {
    if (root->getParent() == nullptr) {
        throw std::domain_error("Invalid xml tree, too many close tags");
    }
    if (tag.getName() != root->getName()) {
        throw std::domain_error("Invalid xml tree, mismatched name of open and close tag");
    }

    root = dynamic_cast<XmlElementDefault*>(root->getParent());
    return root;
}

XmlElementDefault* XmlBuilder::parseXmlTagsToXmlElements(const std::vector<XmlTag>& tags) const {
    XmlElementDefault* currentNode = new XmlElementDefault;
    for (XmlTag tag : tags) {
        if (tag.isContents()) {
            currentNode = addXmlContentToXmlElement(currentNode, tag);
        } else if (tag.isEmpty()) {
            currentNode = addXmlEmptyToXmlElement(currentNode, tag);
        } else if (tag.isSpecial()) {
            currentNode = addXmlSpecialToXmlElement(currentNode, tag);
        } else if (tag.isOpening()) {
            currentNode = addXmlOpenTagToXmlElement(currentNode, tag);
        } else if (tag.isClosing()) {
            currentNode = addXmlCloseTagToXmlElement(currentNode, tag);
        } else {
            delete currentNode->getRoot();
            throw std::invalid_argument("Tag is of unknown type");
        }
    }
    return currentNode;
}

std::vector<XmlTag> XmlBuilder::parseStreamToTags() const {
    std::string bufferString;
    std::vector<XmlTag> tags;
    while (!this->inputStream->eof()) {
        XmlTag nextTag = getTagFromStream();
        if (!nextTag.getContents().size() == 0) {
            tags.push_back(nextTag);
        }
    }
    return tags;
}

void XmlBuilder::openFileStream(const std::string& path) {
    inputStream = new std::ifstream(path);
    if (inputStream->fail()) {
        throw std::invalid_argument("Failed to open file " + path);
    }
}

void XmlBuilder::openStringStream(const std::string& string) {
    inputStream = new std::stringstream(string);
    if (inputStream->fail()) {
        throw std::invalid_argument("Failed to make stream from string");
    }
}

void XmlBuilder::deleteInputStream() {
    delete inputStream;
}

XmlTag XmlBuilder::getTagFromStream() const {
    std::string bufferString;
    char bufferChar;
    while (inputStream->get(bufferChar)) {
        if (bufferChar == '<') {
            StringExtension::trim(&bufferString);
            if (!bufferString.empty()) {
                inputStream->seekg(-1, std::ios_base::cur);
                break;
            }
        } else if (bufferChar == '>') {
            bufferString.push_back(bufferChar);
            break;
        }
        bufferString.push_back(bufferChar);
    }
    return XmlTag(bufferString);
}
