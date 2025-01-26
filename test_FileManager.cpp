#include <gtest/gtest.h>
#include "FileManager.h"
#include <vector>

TEST(FileManagerTest, LoadCSV) {
    std::string logFile = "log_data_test.txt";
    std::string errorLogFile = "log_error_data_test.txt";
    std::vector<DataPoint> data = FileManager::loadDataFromCSV("Chart Export.csv", logFile, errorLogFile);
    ASSERT_FALSE(data.empty());
}

TEST(FileManagerTest, SaveAndLoadBinary) {
    std::vector<DataPoint> originalData = {
        DataPoint("01.01.2021 00:00", 0, 0, 0, 0, 0)
    };
    FileManager::saveDataToBinary(originalData, "test_data.bin");
    std::vector<DataPoint> loadedData = FileManager::loadDataFromBinary("test_data.bin");

    ASSERT_EQ(originalData.size(), loadedData.size());
    ASSERT_EQ(originalData[0].timestamp, loadedData[0].timestamp);
}
