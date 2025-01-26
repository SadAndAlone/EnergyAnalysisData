#include "Logger.h"
#include <fstream>

void Logger::logToFile(const std::string& logFile, const std::string& message) {
    std::ofstream log(logFile, std::ios::app);
    log << message << std::endl;
}
