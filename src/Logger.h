#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <memory>
#include <string>
/** \file */

/** Logging of errors and important messages for debugging
 */
class Logger {
 public:
    /** Log a message as information
     * \param[in] message - text to log
     */
    static void info(std::string message);
    /** Log a message as an error
     * \param[in] message - text to log
     */
    static void error(std::string message);

 private:
    static std::shared_ptr<spdlog::logger> logger;
};
