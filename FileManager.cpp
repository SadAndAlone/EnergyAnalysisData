#include "FileManager.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>

// Funkcja wczytująca dane z pliku CSV
std::vector<DataPoint> FileManager::loadDataFromCSV(const std::string& filename, std::string& logFile, std::string& errorLogFile) {
    std::vector<DataPoint> dataPoints;
    std::ifstream file(filename);
    std::ofstream log(logFile, std::ios::app);
    std::ofstream errorLog(errorLogFile, std::ios::app);

    std::string line;
    bool firstLine = true;  // Pomijamy pierwszą linię z nagłówkiem

    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;  // Pomijamy pierwszą linię
        }

        std::istringstream ss(line);
        std::string timestamp;
        double autokonsumpcja, eksport, import, pobor, produkcja;

        char delimiter;  // Dla rozdzielacza

        // Oczekujemy formatu: "timestamp, autokonsumpcja, eksport, import, pobór, produkcja"
        ss >> std::quoted(timestamp) >> delimiter >> autokonsumpcja >> delimiter >> eksport >> delimiter >> import >> delimiter >> pobor >> delimiter >> produkcja;

        if (ss.fail()) {
            errorLog << "Błąd wczytywania: " << line << std::endl;
            continue;  // Jeśli linia jest błędna, pomijamy ją
        }

        DataPoint data(timestamp, autokonsumpcja, eksport, import, pobor, produkcja);
        dataPoints.push_back(data);
        log << "Wczytano dane: " << line << std::endl;
    }

    return dataPoints;
}

// Funkcja do zapisu do pliku binarnego
void FileManager::saveDataToBinary(const std::vector<DataPoint>& data, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    for (const auto& dataPoint : data) {
        file.write(reinterpret_cast<const char*>(&dataPoint), sizeof(DataPoint));
    }
}

// Funkcja do odczytu z pliku binarnego
std::vector<DataPoint> FileManager::loadDataFromBinary(const std::string& filename) {
    std::vector<DataPoint> dataPoints;
    std::ifstream file(filename, std::ios::binary);

    DataPoint dp("", 0, 0, 0, 0, 0);
    while (file.read(reinterpret_cast<char*>(&dp), sizeof(DataPoint))) {
        dataPoints.push_back(dp);
    }

    return dataPoints;
}
