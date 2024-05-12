#include "CauhoiTN.h"
#include<string>

void CauhoiTN::taoDeThiMoi() {
    danhSachCauHoi.clear();
    std::cout << "Da tao mot de thi moi!" << std::endl;
}

void CauhoiTN::themCauHoi() {
    CauhoiTN cauHoi;
    cauHoi.nhap();
    danhSachCauHoi.push_back(cauHoi);
}

void CauhoiTN::inDanhSachCauHoi() {
    for (size_t i = 0; i < danhSachCauHoi.size(); ++i) {
        std::cout << "Cau hoi " << i + 1 << ":" << std::endl;
        danhSachCauHoi[i].xuat();
        std::cout << std::endl;
    }
}

void CauhoiTN::luuFile(std::string NGK_CN2301E) {
    std::ofstream outFile(NGK_CN2301E);
    if (outFile.is_open()) {
        for (const auto& cauHoi : danhSachCauHoi) {
            outFile << cauHoi.noiDung << std::endl;
            outFile << cauHoi.dapAnA << std::endl;
            outFile << cauHoi.dapAnB << std::endl;
            outFile << cauHoi.dapAnDung << std::endl;
        }
        outFile.close();
        std::cout << "Da luu danh sach cau hoi vao file " << NGK_CN2301E << std::endl;
    }
    else {
        std::cout << "Khong the mo file de luu!" << std::endl;
    }
}

void CauhoiTN::docFile(std::string NGK_CN2301E) {
    danhSachCauHoi.clear();
    std::ifstream inFile(NGK_CN2301E);
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            CauhoiTN cauHoi;
            std::getline(inFile, cauHoi.noiDung);
            std::getline(inFile, cauHoi.dapAnA);
            std::getline(inFile, cauHoi.dapAnB);
            inFile >> cauHoi.dapAnDung;
            inFile.ignore();
            danhSachCauHoi.push_back(cauHoi);
        }
        inFile.close();
        std::cout << "Da doc file " << NGK_CN2301E << " thanh cong!" << std::endl;
    }
    else {
        std::cout << "Khong the mo file de doc!" << std::endl;
    }
}

void CauhoiTN::choThi() {
    int diem = 0;
    for (size_t i = 0; i < danhSachCauHoi.size(); ++i) {
        std::cout << "Cau hoi " << i + 1 << ":" << std::endl;
        danhSachCauHoi[i].xuat();
        danhSachCauHoi[i].kiemtra();
        diem++;
    }
    std::cout << "So cau tra loi dung: " << diem << "/" << danhSachCauHoi.size() << std::endl;
}

void CauhoiTN::nhap() {
    std::cout << "Nhap noi dung cau hoi: ";
    std::cin.ignore();
    std::getline(std::cin, noiDung);

    std::cout << "Nhap dap an A: ";
    std::getline(std::cin, dapAnA);

    std::cout << "Nhap dap an B: ";
    std::getline(std::cin, dapAnB);

    std::cout;
}
void CauhoiTN::xuat() {
    std::cout << "Cau hoi: " << noiDung << std::endl;
    std::cout << "A. " << dapAnA << std::endl;
    std::cout << "B. " << dapAnB << std::endl;
    std::cout << "Dap an dung la: " << dapAnDung << std::endl;
}
void CauhoiTN::kiemtra() {
    char luaChon;
    std::cout << "Cau hoi: " << noiDung << std::endl;
    std::cout << "A. " << dapAnA << std::endl;
    std::cout << "B. " << dapAnB << std::endl;
    std::cout << "Nhap dap an cua ban (A hoac B): ";
    std::cin >> luaChon;

    if (toupper(luaChon) == toupper(dapAnDung)) {
        std::cout << "Dap an dung!" << std::endl;
    }
    else {
        std::cout << "Dap an sai!" << std::endl;
    }
}
