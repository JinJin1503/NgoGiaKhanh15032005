#include "SinhVien.h"
#include<fstream>
#include<vector>

void SinhVien::nhapDanhSach(std::vector<SinhVien>& danhSachSV) {
    
}

void SinhVien::xuatDanhSach(const std::vector<SinhVien>& danhSachSV) {
  
}

void SinhVien::docDanhSachTuFile(std::vector<SinhVien>& danhSachSV) {
    
}

void SinhVien::tinhDiemVaInDuDieuKien(const std::vector<SinhVien>& danhSachSV) {
  
}

void SinhVien::inSinhVienCoHoLaNguyen(const std::vector<SinhVien>& danhSachSV) {
    
}

void SinhVien::inSinhVienCungTen(const std::vector<SinhVien>& danhSachSV) {
   
}

float SinhVien::tinhDiemQT() const {
    float diemQT = (10 - soBuoiVang * 2) * 0.2 + diemTH * 0.3 + diemGK * 0.5;
    if (soBuoiVang > 5) {
        diemQT = 0;
    }
    return diemQT;
}
void SinhVien::docDanhSachTuFile(std::vector<SinhVien>& danhSachSV) {
    std::ifstream inFile("DANHSACHSINHVIEN.TTN");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            SinhVien sv;
            inFile >> sv.maSV >> sv.hoTen >> sv.soBuoiVang >> sv.diemTH >> sv.diemGK;
            danhSachSV.push_back(sv);
        }
        inFile.close();
        std::cout << "Da doc danh sach sinh vien tu file sinh_vien.ttn" << std::endl;
    }
    else {
        std::cout << "Khong the mo file de doc!" << std::endl;
    }
}
