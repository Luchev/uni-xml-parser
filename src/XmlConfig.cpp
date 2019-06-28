#include <src/XmlConfig.h>

XmlConfig * XmlConfig::instance = nullptr;

XmlConfig::XmlConfig() {
    // Intentionally empty
}

XmlConfig * XmlConfig::getInstance() {
    if (XmlConfig::instance == nullptr) {
        XmlConfig::instance = new XmlConfig();
    }
    return XmlConfig::instance;
}

std::string XmlConfig::getOutputQuote() const {
    return outputQuote;
}

XmlConfig::~XmlConfig() {
    delete instance;
}
