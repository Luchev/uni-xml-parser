#pragma once
#include <string>

class XmlConfig {
 public:
    static XmlConfig * getInstance();

    std::string getOutputQuote() const;
    std::string getLogLocation() const;

    ~XmlConfig();

 private:
    XmlConfig();
    XmlConfig(const XmlConfig &) = delete;
    XmlConfig& operator=(const XmlConfig &) = delete;

    static XmlConfig * instance;

    std::string outputQuote = "\"";
    std::string logLocation = "logs/logs.log";
};
