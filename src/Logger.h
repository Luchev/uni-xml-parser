#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <memory>
#include <string>

class Logger {
 public:
    static void info(std::string message);
    static void error(std::string message);
 private:
    static std::shared_ptr<spdlog::logger> logger;
};
