#include "Menu.h"
#include <iostream>

void Menu::showMenu() {
    std::cout << "1. Wczytaj dane z pliku CSV" << std::endl;
    std::cout << "2. Zapisz dane do pliku binarnego" << std::endl;
    std::cout << "3. Wczytaj dane z pliku binarnego" << std::endl;
    std::cout << "4. Wyjście" << std::endl;
}

void Menu::executeChoice(int choice, std::vector<DataPoint>& data) {
    switch (choice) {
    case 1:
        // Wczytaj dane z CSV
    {
        std::string logFile = "log_data_" + std::to_string(time(NULL)) + ".txt";
        std::string errorLogFile = "log_error_data_" + std::to_string(time(NULL)) + ".txt";
        data = FileManager::loadDataFromCSV("Chart Export.csv", logFile, errorLogFile);
        std::cout << "Dane zostały wczytane." << std::endl;
    }
    break;
    case 2:
        // Zapisz do pliku binarnego
        FileManager::saveDataToBinary(data, "data.bin");
        std::cout << "Dane zapisane do pliku binarnego." << std::endl;
        break;
    case 3:
        // Wczytaj z pliku binarnego
        data = FileManager::loadDataFromBinary("data.bin");
        std::cout << "Dane zostały wczytane z pliku binarnego." << std::endl;
        break;
    case 4:
        std::cout << "Zamykanie programu." << std::endl;
        break;
    }
}
