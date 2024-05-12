#include "CauhoiTN.h"
#include<string>

CauhoiTN::CauhoiTN() {
    noiDung = "";
    dapAnA = "";
    dapAnB = "";
    dapAnDung = '\0';
}

void CauhoiTN::nhap() {
    std::cout << "Nhap noi dung cau hoi: ";
    std::cin.ignore();
    std::getline(std::cin, noiDung);

    std::cout << "Nhap dap an A: ";
    std::getline(std::cin, dapAnA);

    std::cout << "Nhap dap an B: ";
    std::getline(std::cin, dapAnB);

    std::cout << "Nhap dap an dung (A hoac B): ";
    std::cin >> dapAnDung;
}

void CauhoiTN::docfile(std::ifstream& f) {
    std::getline(f, noiDung);
    std::getline(f, dapAnA);
    std::getline(f, dapAnB);
    f >> dapAnDung;
    f.ignore();
}

void CauhoiTN::ghifile(std::ofstream& f) {
    f << noiDung << std::endl;
    f << dapAnA << std::endl;
    f << dapAnB << std::endl;
    f << dapAnDung << std::endl;
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

void CauhoiTN::xuat() {
    std::cout << "Cau hoi: " << noiDung << std::endl;
    std::cout << "A. " << dapAnA << std::endl;
    std::cout << "B. " << dapAnB << std::endl;
    std::cout << "Dap an dung la: " << dapAnDung << std::endl;
}

bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
    return (cau1.noiDung == cau2.noiDung && cau1.dapAnA == cau2.dapAnA &&
        cau1.dapAnB == cau2.dapAnB && cau1.dapAnDung == cau2.dapAnDung);
}
