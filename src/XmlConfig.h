#pragma once

#include <string>

class XmlConfig {
 public:
    static XmlConfig * getInstance();
    std::string getOutputQuote() const;
 private:
    XmlConfig();
    XmlConfig(const XmlConfig &) = delete;
    XmlConfig& operator=(const XmlConfig &) = delete;

    static XmlConfig * instance;

    std::string outputQuote = "\"";
};
