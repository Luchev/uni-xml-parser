#include <src/XmlConfig.h>

XmlConfig * XmlConfig::instance = nullptr;

XmlConfig * XmlConfig::getInstance() {
    if (XmlConfig::instance == nullptr) {
        XmlConfig::instance = new XmlConfig();
    }
    return XmlConfig::instance;
}

std::string XmlConfig::getOutputQuote() const {
    return outputQuote;
}

std::string XmlConfig::getLogLocation() const {
    return logLocation;
}

XmlConfig::~XmlConfig() {
    delete instance;
}

XmlConfig::XmlConfig() {
    // Intentionally empty - has nothing to initialize
}
