#include <src/XmlBuilder.h>
#include <src/StringExtension.h>
#include <include/XmlElements.h>
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
    } catch (const std::invalid_argument& exception) {
        Logger::error("Failed to create file stream: " + std::string(exception.what()));
        return new XmlElementDefault;
    }

    Logger::info("Parsing file " + path + " to xml");
    XmlElementDefault* root = parseInputStream();
    Logger::info("Finished parsing file");

    deleteInputStream();

    return root;
}

XmlElementDefault* XmlBuilder::parseString(const std::string& string) {
    try {
        openStringStream(string);
    } catch (const std::invalid_argument& exception) {
        Logger::error("Failed to create string stream: " + std::string(exception.what()));
        return new XmlElementDefault;
    }

    Logger::info("Parsing string to xml");
    XmlElementDefault* root = parseInputStream();
    Logger::info("Finished parsing string");

    deleteInputStream();

    return root;
}

XmlElementDefault* XmlBuilder::parseInputStream() const {
    std::vector<XmlTag> tags = parseStreamToTags();

    try {
        XmlElementDefault* root = parseXmlTagsToXmlElements(tags);
        return root;
    } catch (const std::invalid_argument& exception) {
        Logger::error("Failed parsing xml: " + std::string(exception.what()));
        return new XmlElementDefault;
    } catch (const std::domain_error& exception) {
        Logger::error("Failed parsing xml: " + std::string(exception.what()));
        return new XmlElementDefault;
    }
}

XmlElementDefault* XmlBuilder::parseXmlTagsToXmlElements(const std::vector<XmlTag>& tags) const {
    Logger::info("Parsing stream to vector of tags");
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
        if (!nextTag.getContent().size() == 0) {
            Logger::info("Read tag: " + nextTag.getContent());
            tags.push_back(nextTag);
        }
    }

    return tags;
}

XmlElementDefault* XmlBuilder::
addXmlContentToXmlElement(XmlElementDefault* element, const XmlTag& tag) const {
    Logger::info("Adding Content Xml Element: " + tag.getContent().substr(0, 30));

    XmlElementContent contentElement(tag.toString());
    element->addChildElement(&contentElement);
    return element;
}

XmlElementDefault* XmlBuilder::
addXmlEmptyToXmlElement(XmlElementDefault* element, const XmlTag& tag) const {
    Logger::info("Adding Empty Xml Element: <" + tag.getName() + ">");

    XmlElementEmpty emptyElement(tag.getName(), tag.getAttributes());
    element->addChildElement(&emptyElement);
    return element;
}

XmlElementDefault* XmlBuilder::
addXmlSpecialToXmlElement(XmlElementDefault* element, const XmlTag& tag) const {
    Logger::info("Adding Special Xml Element: <" + tag.getName() + ">");

    XmlElementSpecial specialElement(tag.getName(), tag.getAttributes());
    element->addChildElement(&specialElement);
    return element;
}

XmlElementDefault* XmlBuilder::
addXmlOpenTagToXmlElement(XmlElementDefault* element, const XmlTag& tag) const {
    Logger::info("Adding Opening Xml Element: <" + tag.getName() + ">");

    XmlElementDefault defaultElement(tag.getName(), tag.getAttributes());
    defaultElement.setParent(element);
    element->addChildElement(&defaultElement);

    XmlElement* justAddedElement = element->getChild(element->getNumberOfChildren() - 1);
    element = dynamic_cast<XmlElementDefault*>(justAddedElement);
    return element;
}

XmlElementDefault* XmlBuilder::
addXmlCloseTagToXmlElement(XmlElementDefault* element, const XmlTag& tag) const {
    Logger::info("Adding Closing Xml Element: <" + tag.getName() + ">");

    if (element->getParent() == nullptr) {
        throw std::domain_error("Invalid xml tree, too many close tags");
    }

    if (tag.getName() != element->getName()) {
        throw std::domain_error("Invalid xml tree, mismatched name of open and close tag");
    }

    element = dynamic_cast<XmlElementDefault*>(element->getParent());
    return element;
}

void XmlBuilder::openFileStream(const std::string& path) {
    Logger::info("Opening file stream " + path);
    inputStream = new std::ifstream(path);

    if (inputStream->fail()) {
        throw std::invalid_argument("Failed to open file " + path);
    }
}

void XmlBuilder::openStringStream(const std::string& string) {
    Logger::info("Opening string stream");
    inputStream = new std::stringstream(string);

    if (inputStream->fail()) {
        throw std::invalid_argument("Failed to make stream from string");
    }
}

void XmlBuilder::deleteInputStream() {
    Logger::info("Closing stream");

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
