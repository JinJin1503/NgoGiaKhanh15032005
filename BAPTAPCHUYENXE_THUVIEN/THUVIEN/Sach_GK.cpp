#include "Sach_GK.h"
#include"Sach.h"
using namespace std;
Sach_GK::Sach_GK() :Sach()
{
	this->tt;
}
Sach_GK::Sach_GK(int Ms, int Sl, float Dg, std::string Nn, std::string Nsx, std::string Tt) :Sach(Ms, Sl, Dg, Nn, Nsx)
{
	tt = Tt;
}
Sach_GK::~Sach_GK() {}
void Sach_GK::setTt(std::string Tt)
{
	tt = Tt;
}
std::string Sach_GK::getTt()const
{
	return tt;
}
void Sach_GK::thongTinSach()const
{
	cout << setfill(' ');
	cout << setw(10) << left << getMs() << setw(30) << left << getSl();
	cout << setw(20) << left << getDg() << setw(15) << right << getNn() << setw(15) << right << getNsx();
	cout << setw(15) << right << getTt() << endl;
}
std::string Sach_GK::laSachGi()const
{
	return "giao khoa";
}

int Sach_GK::thanhTien()const
{
	if (tt == "moi")
	{
		return getSl() * getDg();
	}
	else if (tt == "cu")
	{
		return getSl() * getDg() * 0.5;
	}
}