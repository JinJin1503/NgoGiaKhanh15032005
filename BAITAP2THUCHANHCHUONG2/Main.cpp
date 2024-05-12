#include <iostream>
#include <fstream>
#include "CauhoiTN.h"

using namespace std;

int main() {
    CauhoiTN cauhoi;
    int choice;
    ifstream DETHI;
    ofstream DETHIOUT;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Nhap cau hoi" << endl;
        cout << "2. Doc tu file" << endl;
        cout << "3. Ghi vao file" << endl;
        cout << "4. Kiem tra cau hoi" << endl;
        cout << "5. Xuat cau hoi" << endl;
        cout << "6. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cauhoi.nhap();
            break;
        case 2:
            DETHI.open("DETHI.TTN");
            if (!DETHI) {
                cout << "Khong mo duoc file!" << endl;
            }
            else {
                while (!DETHI.eof()) {
                    cauhoi.docfile(DETHI);
                }
                DETHI.close();
            }
            break;
        case 3:
            DETHIOUT.open("DETHIOUT.TTN");
            cauhoi.ghifile(DETHIOUT);
            DETHIOUT.close();
            break;
        case 4:
            cauhoi.kiemtra();
            break;
        case 5:
            cauhoi.xuat();
            break;
        case 6:
            cout << "Tam biet!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 6);

    return 0;
}
