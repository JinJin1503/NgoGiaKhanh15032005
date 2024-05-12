#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Point.h"

using namespace std;

int main() {
    vector<Point> points;
    int n;
       
    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Khong mo duoc file!" << endl;
        return 1;
    }

    inFile >> n;
      
    for (int i = 0; i < n; ++i) {
        double x, y;
        inFile >> x >> y;
        points.push_back(Point(x, y));
    }
    inFile.close();

    sort(points.begin(), points.end());

    for (const auto& point : points) {
        cout << point << endl;
    }

    return 0;
}
