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
    inputStream = nullptr;
}

XmlBuilder::~XmlBuilder() {
    deleteInputStream();
}

XmlElementDefault* XmlBuilder::parseFile(const std::string& path) {
    deleteInputStream();
    openFileStream(path);
    return parse();
}

void XmlBuilder::openStringStream(const std::string& string) {
    inputStream = new std::stringstream(string);
}

XmlElementDefault* XmlBuilder::parseString(const std::string& xml) {
    deleteInputStream();
    openStringStream(xml);
    return parse();
}

XmlElementDefault* XmlBuilder::parse() {
    if (inputStream->fail()) {
        return nullptr;
    } else {
        return parseInputStreamToXml();
    }
}

void XmlBuilder::deleteInputStream() {
    delete inputStream;
}

void XmlBuilder::openFileStream(const std::string& path) {
    inputStream = new std::ifstream(path);
    if (inputStream->fail()) {
        std::cout << "Failed to open input stream\n";
    }
}

XmlElementDefault* XmlBuilder::parseInputStreamToXml() const {
    std::vector<XmlTag> tags = parseStreamToTags();
    XmlElementDefault* root = parseXmlTagsToXmlElements(tags);
    return root;
}

std::vector<XmlTag> XmlBuilder::parseStreamToTags() const {
    std::string buffer;
    char character;
    std::vector<XmlTag> tags;
    while (this->inputStream->get(character)) {
        if (character == '<') {
            StringExtension::trim(&buffer);
            XmlTag contents(buffer);
            if (!contents.isEmpty()) {
                tags.push_back(contents);
            }
            buffer.clear();
        } else if (character == '>') {
            buffer.push_back(character);
            XmlTag tag(buffer);
            tags.push_back(tag);
            buffer.clear();
            continue;
        }
        buffer.push_back(character);
    }
    return tags;
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
                    XmlElement* lastElement =
                        currentNode->getChildElements()[currentNode->getChildElements().size() - 1];
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
