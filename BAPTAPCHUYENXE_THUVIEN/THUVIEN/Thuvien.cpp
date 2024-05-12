#include <iostream> 
#include "Sach.h"
#include "Sach_GK.h"
#include "Sach_TK.h"
#include <vector>
using namespace std;
void nhapCung(vector<Sach*>& dsSach)
{
	dsSach.push_back(new Sach_GK(24, 10, 20000, "20/10/2020", "K", "moi"));
	dsSach.push_back(new Sach_GK(26, 10, 10000, "19/10/2020", "N", "moi"));
	dsSach.push_back(new Sach_GK(25, 10, 15000, "31/10/2020", "L", "cu"));
	dsSach.push_back(new Sach_TK(21, 10, 30000, "10/10/2020", "K", 1000));
	dsSach.push_back(new Sach_TK(20, 10, 25000, "16/10/2020", "D", 1500));
	dsSach.push_back(new Sach_TK(23, 10, 20000, "17/10/2020", "K", 2500));
}
void nhapCacThongTinChung(int& Ms, int& Sl, int& Dg, string& Nn, string& Nsx)
{
	cout << "Nhap ma so sach: ";
	cin >> Ms;
	cout << "Nhap so luong sach: ";
	cin >> Sl;
	cout << "Nhap don gia sach: ";
	cin >> Dg;
	cout << "Nhap ngay nhap sach: ";
	cin >> Nn;
	cout << "Nhap nha san xuat sach: ";
	cin >> Nsx;
}
void nhapMem(vector < Sach*>& dsSach)
{
	int Ms, Sl, Dg, T, chon, sgk, stk;
	std::string Nn, Tt, Nsx;
	while (true)
	{
		cout << "*NHAP MEM CAC LOAI SACH* " << endl;
		cout << "1. ---Nhap Sach Giao Khoa--- " << endl;
		cout << "2. ---Nhap Sach Tham Khao--- " << endl;
		cout << "3. ---Thoat Nhap Mem Sach--- " << endl;
		cin >> chon;
		if (chon == 1)
		{
			cout << "Nhap so sach giao khoa: ";
			cin >> sgk;
			for (int i = 0; i < sgk; i++)
			{
				cout << "***SACH GIAO KHOA***" << endl;
				nhapCacThongTinChung(Ms, Sl, Dg, Nn, Nsx);
				cout << "Nhap tinh trang sach: ";
				cin >> Tt;
				dsSach.push_back(new Sach_GK(Ms, Sl, Dg, Nn, Nsx, Tt));
			}
		}
		else if (chon == 2)
		{
			cout << "Nhap so sach tham khao: ";
			cin >> stk;
			for (int i = 0; i < stk; i++)
			{
				cout << "***SACH THAM KHAO***" << endl;
				nhapCacThongTinChung(Ms, Sl, Dg, Nn, Nsx);
				cout << "Nhap thue sach: ";
				cin >> T;
				dsSach.push_back(new Sach_TK(Ms, Sl, Dg, Nn, Nsx, T));
			}
		}
		else if (chon == 3)
		{
			break;
		}
	}
}
int sumSgk(vector<Sach*>& dsSach)
{
	int sumSgk = 0;
	for (Sach* Sach : dsSach)
	{
		if (dynamic_cast<Sach_GK*>(Sach))
		{
			sumSgk = sumSgk + Sach->thanhTien();
		}
	}
	return sumSgk;
}
int sumStk(vector<Sach*>& dsSach)
{
	int sumStk = 0;
	for (Sach* Sach : dsSach)
	{
		if (dynamic_cast<Sach_TK*>(Sach))
		{
			sumStk = sumStk + Sach->thanhTien();
		}
	}
	return sumStk;
}
float tbDonGia(vector<Sach*>& dsSach)
{
	int tong = 0, dem = 0;
	float tbDonGia = 0;
	for (Sach* Sach : dsSach)
	{
		if (dynamic_cast<Sach_TK*>(Sach))
		{
			dem = dem + 1;
			tong = tong + Sach->getDg();
		}
	}
	if (dem != 0)
	{
		tbDonGia = tong / dem;
	}

	return tbDonGia;
}
void ktNhaXuatBan(vector<Sach*>& dsSach)
{
	std::string kt;
	cout << "Nhap nha xuat ban can xuat: ";
	cin >> kt;
	cout << setfill('=') << setw(38) << left << "=" << " * Sach Giao Khoa Can Xuat* " << setw(39) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma sach" << setw(30) << left << "So luong";
	cout << setw(20) << left << "Don gia" << setw(15) << right << "Ngay nhap" << setw(15) << right << "Nha Xuat ban";
	cout << setw(15) << right << "Tinh trang" << endl;
	cout << setfill('_') << setw(105) << "_" << endl;
	for (Sach* Sach : dsSach)
	{
		if (dynamic_cast<Sach_GK*>(Sach))
		{
			if (Sach->getNsx() == kt)
			{
				Sach->thongTinSach();
			}
		}
	}
}
void xuatDanhSach(vector<Sach*>& dsSach)
{
	cout << setfill('=') << setw(42) << left << "=" << " * Sach Giao Khoa * " << setw(43) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma sach" << setw(30) << left << "So luong";
	cout << setw(20) << left << "Don gia" << setw(15) << right << "Ngay nhap" << setw(15) << right << "Nha Xuat ban";
	cout << setw(15) << right << "Tinh trang" << endl;
	cout << setfill('_') << setw(105) << "_" << endl;
	for (Sach* Sach : dsSach)
	{
		if (dynamic_cast<Sach_GK*>(Sach))
		{
			Sach->thongTinSach();
		}
	}
	cout << endl;
	cout << "Tong thanh tien sach giao khoa: " << sumSgk(dsSach) << endl;
	cout << "\n";
	cout << endl;
	cout << setfill('=') << setw(42) << left << "=" << " * Sach Tham Khao * " << setw(43) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma sach" << setw(30) << left << "So luong";
	cout << setw(20) << left << "Don gia" << setw(15) << right << "Ngay nhap" << setw(15) << right << "Nha xuat ban";
	cout << setw(15) << right << "Thue" << endl;
	cout << setfill('_') << setw(105) << "_" << endl;
	for (Sach* Sach : dsSach)
	{
		if (dynamic_cast<Sach_TK*>(Sach))
		{
			Sach->thongTinSach();
		}
	}
	cout << endl;
	cout << "Tong thanh tien sach tham khao: " << sumStk(dsSach) << endl;
	cout << "\n";
	cout << "Trung binh cong don gia sach tham khao: " << tbDonGia(dsSach) << endl << endl;

}
void menu()
{
	cout << "=========================* Menu *=======================" << endl;
	cout << "*1. Nhap cung                                           *\n";
	cout << "*2. Nhap mem                                            *\n";
	cout << "*0. Thoat                                               *\n";
	cout << "=========================================================" << endl;
}


int main()
{
	vector<Sach*> dsSach;

	int luaChon;
	do
	{
		system("cls");
		menu();

		int chon;
		cout << "Nhap lua chon: ";
		cin >> chon;
		switch (chon)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			nhapCung(dsSach);
			xuatDanhSach(dsSach);
			ktNhaXuatBan(dsSach);
			break;
		}
		case 2:
		{
			nhapMem(dsSach);
			xuatDanhSach(dsSach);
			ktNhaXuatBan(dsSach);
			break;
		}

		default:
		{
			luaChon = 0;
		}
		}
		cout << "----------Ban co muon tiep chuong trinh------------" << endl;
		cout << "1. Tiep tuc    0.Thoat" << endl;
		cout << "Chon:";
		cin >> luaChon;
	} while (luaChon != 0);

}