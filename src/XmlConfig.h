#pragma once
#include <string>
/** \file */

/** Configuration of the whole system
 * 
 * Singleton class which contains the global documentation of the XML parsing
 * and printing.
 * Has the following config fields:
 * - output quote (specify if the output quote should be single or double)
 * - log path (path to the log files)
 */
class XmlConfig {
 public:
    /** Get the instance of the singleton
	 * 
	 * Initializes an instance if such doesn't exist already
	 * and returns it.
	 * \return XmlConfig pointer - the instance of the singleton
	 */
    static XmlConfig * getInstance();
	/** Get the output quote (single or double)
	 * \return string
	 */
    std::string getOutputQuote() const;
	/** Get the log path
	 * \return string
	 */
    std::string getLogPath() const;
	/** Destructor
	 */
    ~XmlConfig();

 private:
    XmlConfig();
    XmlConfig(const XmlConfig &) = delete;
    XmlConfig& operator=(const XmlConfig &) = delete;

    static XmlConfig * instance;

    std::string outputQuote = "\"";
    std::string logPath = "logs/logs.log";
};
