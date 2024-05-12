#include <iostream>
#include <fstream>
#include <vector>
#include "SinhVien.h"

using namespace std;

int main() {
    vector<SinhVien> danhSachSV;
    int choice;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Nhap danh sach sinh vien" << endl;
        cout << "2. Xuat danh sach sinh vien" << endl;
        cout << "3. Doc danh sach sinh vien tu file" << endl;
        cout << "4. Tinh diem quatrinh va in danh sach du dieu kien du thi" << endl;
        cout << "5. In danh sach sinh vien co ho la 'Nguyen'" << endl;
        cout << "6. In danh sach sinh vien co cung ten voi mot sinh vien khac" << endl;
        cout << "7. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            SinhVien::nhapDanhSach(danhSachSV);
            break;
        case 2:
            SinhVien::xuatDanhSach(danhSachSV);
            break;
        case 3:
            SinhVien::docDanhSachTuFile(danhSachSV);
            break;
        case 4:
            SinhVien::tinhDiemVaInDuDieuKien(danhSachSV);
            break;
        case 5:
            SinhVien::inSinhVienCoHoLaNguyen(danhSachSV);
            break;
        case 6:
            SinhVien::inSinhVienCungTen(danhSachSV);
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
