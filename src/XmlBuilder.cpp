#include <src/XmlBuilder.h>
#include <src/StringExtension.h>
#include <include/XmlElements.h>
#include <src/XmlFactory.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

XmlBuilder::XmlBuilder() {
    // Intentionally empty
}

XmlBuilder::~XmlBuilder() {
    // Intentionally empty
}

XmlElementDefault* XmlBuilder::parseFile(const std::string& path) {
    openFileStream(path);
    XmlElementDefault* root = parseInputStream();
    deleteInputStream();
    return root;
}

XmlElementDefault* XmlBuilder::parseString(const std::string& xml) {
    openStringStream(xml);
    XmlElementDefault* root = parseInputStream();
    deleteInputStream();
    return root;
}

XmlElementDefault* XmlBuilder::parseInputStream() const {
    std::vector<XmlTag> tags = parseStreamToTags();
    XmlElementDefault* root = parseXmlTagsToXmlElements(tags);
    return root;
}

XmlElementDefault* XmlBuilder::parseXmlTagsToXmlElements(const std::vector<XmlTag>& tags) const {
    XmlElementDefault* currentNode = new XmlElementDefault;
    for (XmlTag tag : tags) {
        if (tag.isValid()) {
            if (tag.isSelfClosing()) {
                XmlElementEmpty next(tag.getName());
                next.setAttributes(tag.getAttributes());
                currentNode->addChildElement(&next);
            } else if (tag.isSpecial()) {
                XmlElementSpecial next(tag.getName());
                next.setAttributes(tag.getAttributes());
                currentNode->addChildElement(&next);
            } else {
                if (tag.isOpening()) {
                    XmlElementDefault next = XmlElementDefault(tag.getName());
                    next.setAttributes(tag.getAttributes());
                    next.setParent(currentNode);
                    currentNode->addChildElement(&next);
                    XmlElement* lastElement = currentNode->getLastChild();
                    currentNode = dynamic_cast<XmlElementDefault*>(lastElement);
                } else {
                    if (currentNode->getParent() == nullptr) {
                        throw std::domain_error("Invalid xml");
                    }
                    currentNode = dynamic_cast<XmlElementDefault*>(currentNode->getParent());
                }
            }
        } else {
            XmlElementContent next(tag.toString());
            currentNode->addChildElement(&next);
        }
    }
    return currentNode;
}

std::vector<XmlTag> XmlBuilder::parseStreamToTags() const {
    std::string bufferString;
    char bufferChar;
    std::vector<XmlTag> tags;
    while (this->inputStream->get(bufferChar)) {
        if (bufferChar == '<') {
            StringExtension::trim(&bufferString);
            XmlTag contents(bufferString);
            if (!contents.isEmpty()) {
                tags.push_back(contents);
            }
            bufferString.clear();
        } else if (bufferChar == '>') {
            bufferString.push_back(bufferChar);
            XmlTag tag(bufferString);
            tags.push_back(tag);
            bufferString.clear();
            continue;
        }
        bufferString.push_back(bufferChar);
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
