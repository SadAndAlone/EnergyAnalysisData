#pragma once
#include <string>
#include <iostream>

class Logger {
public:
    static void logToFile(const std::string& logFile, const std::string& message);
};
