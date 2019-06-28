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
    ~XmlConfig();

    static XmlConfig * instance;

    std::string outputQuote = "\"";
};
