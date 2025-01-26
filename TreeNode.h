#pragma once
#include <vector>
#include "DataPoint.h"

class TreeNode {
public:
    int year;
    int month;
    int day;
    int quarter;
    std::vector<DataPoint> dataPoints;
    std::vector<TreeNode*> children;  // Podwęzły (kolejne poziomy drzewa)

    TreeNode(int y, int m, int d, int q) : year(y), month(m), day(d), quarter(q) {}

    void addDataPoint(DataPoint data) {
        dataPoints.push_back(data);
    }
};
