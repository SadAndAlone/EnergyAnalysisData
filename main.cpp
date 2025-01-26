#include <iostream>
#include "Menu.h"
#include <vector>
#include "DataPoint.h"

int main() {
    std::vector<DataPoint> data;
    int choice;

    do {
        Menu::showMenu();
        std::cout << "Wybierz opcję: ";
        std::cin >> choice;
        Menu::executeChoice(choice, data);
    } while (choice != 4);

    return 0;
}
