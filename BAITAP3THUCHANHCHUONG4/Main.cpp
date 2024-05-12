#include <iostream>
#include <vector>
#include "Fraction.h"

using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    vector<Fraction> fractions;

    for (int i = 0; i < 100; ++i) {
        fractions.push_back(Fraction(n));
    }

    cout << "Cac phan so trong cac phan so da sinh ra khong vuot qua 1/2:" << endl;
    for (const Fraction& frac : fractions) {
        if (frac >= Fraction(1, 2)) {
            cout << frac << endl;
        }
    }

    cout << "Cac phan so khong trung nhau tu cac phan so da sinh ra:" << endl;
    for (size_t i = 0; i < fractions.size(); ++i) {
        bool isUnique = true;
        for (size_t j = 0; j < i; ++j) {
            if (fractions[i] == fractions[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            cout << fractions[i] << endl;
        }
    }

    return 0;
}

        