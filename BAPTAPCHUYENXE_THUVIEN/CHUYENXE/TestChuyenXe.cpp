#include <iostream>
#include "Chuyen_Xe.h"
#include "Chuyen_Xe_Noi.h"
#include "Chuyen_Xe_Ngoai.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

string chuanHoaTen2(string& ten)
{
	for (int i = 0; i < ten.size(); i++)
	{
		if (ten != " ")
		{
			ten[i] = toupper(ten[i]);
		}
		else
		{
			break;
		}
	}
	return ten;
}

void nhapCung(vector<Chuyen_Xe*>& danhSachXe)
{
	danhSachXe.push_back(new Chuyen_Xe_Noi(01, 05257, 100000, "Ngo Manh Kien", 15, 11));
	danhSachXe.push_back(new Chuyen_Xe_Noi(01, 05672, 700000, "Ngo Gia Bao", 15, 12));
	danhSachXe.push_back(new Chuyen_Xe_Noi(01, 05265, 500000, "Ngo Bao Chau", 15, 13));
	danhSachXe.push_back(new Chuyen_Xe_Ngoai(02, 05467, 800000, "Ha Bao Minh", 3, "Thai Lan"));
	danhSachXe.push_back(new Chuyen_Xe_Ngoai(02, 05457, 240000, "Ha My Dien", 3, "Campuchia"));
	danhSachXe.push_back(new Chuyen_Xe_Ngoai(02, 05437, 450000, "Ha Ngoc Thien", 3, "Trung Quoc"));
}
void nhapCacThongTinChung(int& Msx, int& Sx, int& Dt, string& Ht)
{

	cout << "Nhap ma so xe: ";
	cin >> Msx;
	cout << "Nhap so xe: ";
	cin >> Sx;
	cout << "Nhap doanh thu: ";
	cin >> Dt;
	cout << "Nhap ho ten tai xe: ";
	cin >> Ht;
	chuanHoaTen2(Ht);


}
void nhapdanhSachChuyenXe(vector<Chuyen_Xe*>& danhSachXe)
{
	int xeNgoaiThanh, xeNoiThanh, St, Km, Sn, chon;
	string  Nd;
	int Msx, Sx, Dt;
	string Ht;
	while (true)
	{
		cout << "*NHAP MEM CAC LOAI XE* " << endl;
		cout << "1. ---Nhap Chuyen Xe Noi Thanh--- " << endl;
		cout << "2. ---Nhap Chuyen Xe Ngoai Thanh--- " << endl;
		cout << "3. ---Thoat Nhap Mem Cac Loai Xe--- " << endl;
		cin >> chon;
		if (chon == 1)
		{
			cout << "Nhap so xe noi thanh: ";
			cin >> xeNoiThanh;
			for (int i = 0; i < xeNoiThanh; i++)
			{
				cout << "***CHUYEN XE NOI THANH***" << endl;
				nhapCacThongTinChung(Msx, Sx, Dt, Ht);
				cout << "Nhap so tuyen: ";
				cin >> St;
				cout << "Nhap so km di duoc: ";
				cin >> Km;
				danhSachXe.push_back(new Chuyen_Xe_Noi(Msx, Sx, Dt, Ht, St, Km));
			}
		}
		else if (chon == 2)
		{
			cout << "Nhap so xe ngoai thanh: ";
			cin >> xeNgoaiThanh;
			for (int i = 0; i < xeNgoaiThanh; i++)
			{
				cout << "***CHUYEN XE NGOAI THANH***" << endl;
				nhapCacThongTinChung(Msx, Sx, Dt, Ht);
				cout << "Nhap so ngay di: ";
				cin >> Sn;
				cout << "Nhap noi  den: ";
				cin >> Nd;
				chuanHoaTen2(Nd);
				danhSachXe.push_back(new Chuyen_Xe_Ngoai(Msx, Sx, Dt, Ht, Sn, Nd));
			}
		}
		else if (chon == 3)
		{
			break;
		}
	}
}



int  sumNoiThanh(vector<Chuyen_Xe*> danhSachXe)
{
	int sum = 0;
	for (Chuyen_Xe* Chuyen_Xe : danhSachXe)
	{
		if (dynamic_cast<Chuyen_Xe_Noi*>(Chuyen_Xe))
		{
			sum = sum + Chuyen_Xe->getDthu();
		}
	}
	return sum;
}
int  sumNgoaiThanh(vector<Chuyen_Xe*> danhSachXe)
{
	int sum = 0;
	for (Chuyen_Xe* Chuyen_Xe : danhSachXe)
	{
		if (dynamic_cast<Chuyen_Xe_Ngoai*>(Chuyen_Xe))
		{
			sum = sum + Chuyen_Xe->getDthu();
		}
	}
	return sum;
}
int  sumAll(vector<Chuyen_Xe*> danhSachXe)
{
	int sum = 0;
	for (Chuyen_Xe* Chuyen_Xe : danhSachXe)
	{
		sum = sum + Chuyen_Xe->getDthu();
	}
	return sum;
}
void xuatDanhSach(vector<Chuyen_Xe*> danhSachXe)
{
	cout << setfill('=') << setw(31) << left << "=" << "* Chuyen xe noi thanh *" << setw(31) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma xe" << setw(25) << left << "Ho ten tai xe";
	cout << setw(15) << left << "So xe" << setw(10) << right << "So tuyen" << setw(10) << right << "So km";
	cout << setw(15) << right << "Doanh thu" << endl;
	cout << setfill('_') << setw(85) << "_" << endl;
	for (Chuyen_Xe* Chuyen_Xe : danhSachXe)
	{
		if (dynamic_cast<Chuyen_Xe_Noi*>(Chuyen_Xe))
		{
			Chuyen_Xe->thongTinChuyenXe();
		}
	}
	cout << endl;
	cout << "Tong doanh thu cua chuyen xe noi thanh: " << sumNoiThanh(danhSachXe) << endl;
	cout << endl;
	cout << setfill('=') << setw(30) << left << "=" << "* Chuyen xe ngoai thanh *" << setw(30) << left << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "Ma xe" << setw(25) << left << "Ho ten tai xe";
	cout << setw(15) << left << "So xe" << setw(10) << left << "So ngay di" << setw(10) << right << "Noi den";
	cout << setw(15) << right << "Doanh thu" << endl;
	cout << setfill('_') << setw(85) << "_" << endl;
	for (Chuyen_Xe* Chuyen_Xe : danhSachXe)
	{
		if (dynamic_cast<Chuyen_Xe_Ngoai*>(Chuyen_Xe))
		{
			Chuyen_Xe->thongTinChuyenXe();
		}
	}
	cout << endl;
	cout << "Tong doanh thu cua chuyen xe ngoai thanh: " << sumNgoaiThanh(danhSachXe) << endl;
	cout << "\n\n\n";
	cout << "\t\t\t\t Tong danh thu cua Noi Thanh va Ngoai Thanh: " << sumAll(danhSachXe) << endl;
}
void menu()
{
	cout << "=========================* Menu *=======================" << endl;
	cout << "1. Nhap cung                                           *\n";
	cout << "2. Nhap mem                                            *\n";
	cout << "0. Thoat                                               *\n";
	cout << "=========================================================" << endl;
}
int main()
{
	vector<Chuyen_Xe*> danhSachXe;

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
			nhapCung(danhSachXe);
			xuatDanhSach(danhSachXe);
			break;
		}
		case 2:
		{
			nhapdanhSachChuyenXe(danhSachXe);
			xuatDanhSach(danhSachXe);
			break;
		}

		default:
		{
			luaChon = 0;
		}
		}
		cout << "----------------------" << endl;
		cout << "1. Tiep tuc    0.Thoat" << endl;
		cout << "Chon:";
		cin >> luaChon;
	} while (luaChon != 0);


}
