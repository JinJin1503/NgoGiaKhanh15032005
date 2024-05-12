#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <fstream>
#include <vector>

class SinhVien {
private:
    std::string maSV;
    std::string hoTen;
    int soBuoiVang;
    float diemTH;
    float diemGK;

public:
    static void nhapDanhSach(std::vector<SinhVien>& danhSachSV);
    static void xuatDanhSach(const std::vector<SinhVien>& danhSachSV);
    static void docDanhSachTuFile(std::vector<SinhVien>& danhSachSV);
    static void tinhDiemVaInDuDieuKien(const std::vector<SinhVien>& danhSachSV);
    static void inSinhVienCoHoLaNguyen(const std::vector<SinhVien>& danhSachSV);
    static void inSinhVienCungTen(const std::vector<SinhVien>& danhSachSV);

private:
    float tinhDiemQT() const;
};

#endif // SINHVIEN_H
