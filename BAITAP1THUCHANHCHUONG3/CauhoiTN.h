#ifndef CAUHOITN_H
#define CAUHOITN_H

#include <iostream>
#include <fstream>
#include <vector>

class CauhoiTN {
private:
    std::string noiDung;
    std::string dapAnA;
    std::string dapAnB;
    char dapAnDung;

    void nhap();
    void xuat();
    void kiemtra();

    std::vector<CauhoiTN> danhSachCauHoi;

public:
    void taoDeThiMoi();
    void themCauHoi();
    void inDanhSachCauHoi();
    void luuFile(std::string fileName);
    void docFile(std::string fileName);
    void choThi();

};

#endif 

