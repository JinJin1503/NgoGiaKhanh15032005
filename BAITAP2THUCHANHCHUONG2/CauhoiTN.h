#ifndef CAUHOITN_H
#define CAUHOITN_H

#include <iostream>
#include <fstream>

class CauhoiTN {
private:
    std::string noiDung;
    std::string dapAnA;
    std::string dapAnB;
    char dapAnDung;

public:
    CauhoiTN();
    void nhap();
    void docfile(std::ifstream& f);
    void ghifile(std::ofstream& f);
    void kiemtra();
    void xuat();
    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};

#endif 
