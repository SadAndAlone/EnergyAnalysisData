#pragma once
#include <vector>
#include "DataPoint.h"
#include <fstream>
#include <iostream>

class FileManager {
public:
    static std::vector<DataPoint> loadDataFromCSV(const std::string& filename, std::string& logFile, std::string& errorLogFile);
    static void saveDataToBinary(const std::vector<DataPoint>& data, const std::string& filename);
    static std::vector<DataPoint> loadDataFromBinary(const std::string& filename);
};
