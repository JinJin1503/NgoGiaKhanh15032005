#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <memory>
#include "Nhan_Vien.h"
#include "Nhan_Vien_PartTime.h"
#include "Nhan_Vien_FullTime.h"

using namespace std;

void nhapCung(vector<shared_ptr<Nhan_Vien>>& dsNhanVien)
{
    dsNhanVien.push_back(make_shared<Nhan_Vien_FullTime>(123, "Alice", "2018-01-15", "0123456789", 1800000, 3.0, 5));
    dsNhanVien.push_back(make_shared<Nhan_Vien_FullTime>(234, "Bob", "2019-06-10", "0987654321", 2000000, 2.5, 3));
    dsNhanVien.push_back(make_shared<Nhan_Vien_PartTime>(345, "Charlie", "2020-03-20", "0912345678", 1500000, 30, 100000));
    dsNhanVien.push_back(make_shared<Nhan_Vien_PartTime>(456, "David", "2021-07-30", "0908765432", 1600000, 45, 80000));
    dsNhanVien.push_back(make_shared<Nhan_Vien_FullTime>(567, "Eve", "2022-11-05", "0923456789", 2200000, 4.0, 2));
}

void cacThongTinChung(int& ms, string& ht, string& nvl, string& sdt, int& lcb)
{
    cout << "Nhap ma so nhan vien: ";
    cin >> ms;
    cout << "Nhap ho ten nhan vien: ";
    cin.ignore();
    getline(cin, ht);
    cout << "Nhap ngay vao lam: ";
    cin >> nvl;
    cout << "Nhap so dien thoai: ";
    cin >> sdt;
    cout << "Nhap muc luong can ban: ";
    cin >> lcb;
}

void nhapThemThongTin(vector<shared_ptr<Nhan_Vien>>& dsNhanVien)
{
    int ms, lcb;
    string ht, nvl, sdt;
    float sgl, ml, hsl, snkn;
    int chon;

    while (true)
    {
        cout << "------NHAP THEM THONG TIN NHAN VIEN------\n";
        cout << "1. Nhap thong tin nhan vien FullTime\n";
        cout << "2. Nhap thong tin nhan vien PartTime\n";
        cout << "3. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        if (chon == 3)
        {
            break;
        }

        cacThongTinChung(ms, ht, nvl, sdt, lcb);
        bool duplicate = false;
        for (const auto& nv : dsNhanVien)
        {
            if (nv->getMs() == ms)
            {
                cout << "Thong tin ma so trung vui long nhap lai\n";
                duplicate = true;
                break;
            }
        }

        if (duplicate)
        {
            continue;
        }

        if (chon == 1)
        {
            cout << "Nhap he so luong: ";
            cin >> hsl;
            cout << "Nhap so nam kinh nghiem: ";
            cin >> snkn;
            dsNhanVien.push_back(make_shared<Nhan_Vien_FullTime>(ms, ht, nvl, sdt, lcb, hsl, snkn));
        }
        else if (chon == 2)
        {
            cout << "Nhap so gio lam: ";
            cin >> sgl;
            cout << "Nhap muc luong: ";
            cin >> ml;
            dsNhanVien.push_back(make_shared<Nhan_Vien_PartTime>(ms, ht, nvl, sdt, lcb, sgl, ml));
        }
    }
}

void xuatDanhSachNhanVien(const vector<shared_ptr<Nhan_Vien>>& dsNhanVien)
{
    cout << setfill('=') << setw(38) << left << "=" << " *Nhan Vien FullTime* " << setw(39) << left << "=" << endl;
    cout << setfill(' ');
    cout << setw(5) << left << "Ma so" << setw(20) << left << "Ho ten";
    cout << setw(15) << left << "Ngay vao lam" << setw(15) << right << "So dien thoai" << setw(10) << right << "Luong can ban";
    cout << setw(15) << right << "He so luong" << setw(15) << right << "So nam kinh nghiem" << endl;
    cout << setfill('_') << setw(105) << "_" << endl;
    for (const auto& nv : dsNhanVien)
    {
        if (dynamic_cast<Nhan_Vien_FullTime*>(nv.get()))
        {
            nv->thongTinNhanVien();
        }
    }
    cout << setfill('=') << setw(38) << left << "=" << " *Nhan Vien PartTime* " << setw(39) << left << "=" << endl;
    cout << setfill(' ');
    cout << setw(5) << left << "Ma so" << setw(20) << left << "Ho ten";
    cout << setw(15) << left << "Ngay vao lam" << setw(15) << right << "So dien thoai" << setw(10) << right << "Luong can ban";
    cout << setw(15) << right << "So gio lam" << setw(15) << right << "Muc luong" << endl;
    cout << setfill('_') << setw(105) << "_" << endl;
    for (const auto& nv : dsNhanVien)
    {
        if (dynamic_cast<Nhan_Vien_PartTime*>(nv.get()))
        {
            nv->thongTinNhanVien();
        }
    }
}

float sumLuong(const vector<shared_ptr<Nhan_Vien>>& dsNhanVien)
{
    float sumLuong = 0;
    for (const auto& nv : dsNhanVien)
    {
        sumLuong += nv->luong();
    }
    cout << "Tong luong cua tat ca nhan vien: " << sumLuong << endl;
    return sumLuong;
}

void demLuong(const vector<shared_ptr<Nhan_Vien>>& dsNhanVien)
{
    int namdem;
    int dem = 0;
    cout << "Nhap nam de dem luong: ";
    cin >> namdem;
    for (const auto& nv : dsNhanVien)
    {
        if (stoi(nv->getNvl().substr(0, 4)) == namdem)
        {
            dem++;
        }
    }
    cout << "So nhan vien trong nam " << namdem << " la: " << dem << endl;
}

void suaThongTin(vector<shared_ptr<Nhan_Vien>>& dsNhanVien)
{
    int mssua;
    float sglsua;
    cout << "Nhap ma so nhan vien can sua thong tin: ";
    cin >> mssua;
    cout << "Nhap so gio sua doi lai: ";
    cin >> sglsua;
    for (const auto& nv : dsNhanVien)
    {
        auto NVPT = dynamic_cast<Nhan_Vien_PartTime*>(nv.get());
        if (NVPT && nv->getMs() == mssua)
        {
            NVPT->setSgl(sglsua);
        }
    }
}

void sapXepNgayVao(vector<shared_ptr<Nhan_Vien>>& dsNhanVien)
{
    sort(dsNhanVien.begin(), dsNhanVien.end(), [](const shared_ptr<Nhan_Vien>& a, const shared_ptr<Nhan_Vien>& b)
        {
            return a->getNvl() > b->getNvl();
        });
}

void xoaNhanVien(vector<shared_ptr<Nhan_Vien>>& dsNhanVien)
{
    int msxoa, chon;
    cout << "Nhap ma so de xoa: ";
    cin >> msxoa;
    for (auto it = dsNhanVien.begin(); it != dsNhanVien.end(); ++it)
    {
        if ((*it)->getMs() == msxoa)
        {
            cout << "Ban co muon xoa? (1: Co, 0: Khong): ";
            cin >> chon;
            if (chon == 1)
            {
                dsNhanVien.erase(it);
                cout << "Nhan vien da duoc xoa.\n";
                break;
            }
            else
            {
                cout << "Khong muon xoa.\n";
                break;
            }
        }
    }
}

void menu()
{
    cout << "=========================* Menu *=======================\n";
    cout << "*1. Nhap cung nhan vien                                *\n";
    cout << "*2. Nhap them nhan vien                                *\n";
    cout << "*3. Tinh tong luong nhan vien                          *\n";
    cout << "*4. Dem nhan vien trong nam bat ky                     *\n";
    cout << "*5. Sua cap nhat gio lam viec                          *\n";
    cout << "*6. Sap xep nhan vien theo ngay vao lam                *\n";
    cout << "*7. Xoa nhan vien ra khoi danh sach                    *\n";
    cout << "*0. Thoat                                              *\n";
    cout << "=======================================================\n";
}

int main()
{
    vector<shared_ptr<Nhan_Vien>> dsNhanVien;

    int luaChon;
    do
    {


        menu();

        int chon;
        cout << "Nhap lua chon: ";
        cin >> chon;
        switch (chon)
        {
        case 0:
            return 0;
        case 1:
            nhapCung(dsNhanVien);
            xuatDanhSachNhanVien(dsNhanVien);
            break;
        case 2:
            nhapThemThongTin(dsNhanVien);
            xuatDanhSachNhanVien(dsNhanVien);
            break;
        case 3:
            sumLuong(dsNhanVien);
            break;
        case 4:
            demLuong(dsNhanVien);
            break;
        case 5:
            suaThongTin(dsNhanVien);
            xuatDanhSachNhanVien(dsNhanVien);
            break;
        case 6:
            sapXepNgayVao(dsNhanVien);
            xuatDanhSachNhanVien(dsNhanVien);
            break;
        case 7:
            xoaNhanVien(dsNhanVien);
            xuatDanhSachNhanVien(dsNhanVien);
            break;
        default:
            luaChon = 0;
        }
        cout << "----------Ban co muon tiep chuong trinh------------\n";
        cout << "1. Tiep tuc    0. Thoat\n";
        cout << "Chon: ";
        cin >> luaChon;
    } while (luaChon != 0);

    return 0;
}
