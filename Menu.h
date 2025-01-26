#pragma once
#include "FileManager.h"
#include "TreeNode.h"
#include <vector>
#include <string>

class Menu {
public:
    static void showMenu();
    static void executeChoice(int choice, std::vector<DataPoint>& data);
};
