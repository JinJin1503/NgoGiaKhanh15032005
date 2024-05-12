#include <iostream>
#include <fstream>
#include "CauhoiTN.h"

using namespace std;

int main() {
    int choice;
    string NGK_CN2301E;
    CauhoiTN deThi;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Tao mot de thi moi" << endl;
        cout << "2. Them mot cau hoi moi vao de thi hien hanh" << endl;
        cout << "3. In danh sach cau hoi hien dang co trong de thi" << endl;
        cout << "4. Luu danh sach cau hoi vao file *.TTN" << endl;
        cout << "5. Doc noi dung mot file *.TTN vao bo nho" << endl;
        cout << "6. Cho thi va tinh so cau tra loi dung" << endl;
        cout << "7. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            deThi.taoDeThiMoi();
            break;
        case 2:
            deThi.themCauHoi();
            break;
        case 3:
            deThi.inDanhSachCauHoi();
            break;
        case 4:
            cout << "Nhap ten file de luu (*.TTN): ";
            cin >> NGK_CN2301E;
            deThi.luuFile(NGK_CN2301E);
            break;
        case 5:
            cout << "Nhap ten file de doc (*.TTN): ";
            cin >> NGK_CN2301E;
            deThi.docFile(NGK_CN2301E);
            break;
        case 6:
            deThi.choThi();
            break;
        case 7:
            cout << "Tam biet!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 7);

    return 0;
}
