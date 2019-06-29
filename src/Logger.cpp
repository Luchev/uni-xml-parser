#include <src/Logger.h>
#include <src/XmlConfig.h>
#define MB 1024 * 1024

static std::shared_ptr<spdlog::logger> logger = spdlog::rotating_logger_mt
    ("spinlogger", XmlConfig::getInstance()->getLogLocation(), 5 * MB, 3);

void Logger::info(std::string message) {
    auto logger = spdlog::get("spinlogger");
    logger->info(message);
}

void Logger::error(std::string message) {
    auto logger = spdlog::get("spinlogger");
    logger->error(message);
}
