#include "Sach_TK.h"
#include "Sach.h"
using namespace std;
Sach_TK::Sach_TK() :Sach()
{
	this->t;
}
Sach_TK::Sach_TK(int Ms, int Sl, float Dg, std::string Nn, std::string Nsx, float T) :Sach(Ms, Sl, Dg, Nn, Nsx)
{
	t = T;
}
Sach_TK::~Sach_TK() {}
void Sach_TK::setT(float T)
{
	t = T;
}
float Sach_TK::getT()const
{
	return t;
}
void Sach_TK::thongTinSach()const
{
	cout << setfill(' ');
	cout << setw(10) << left << getMs() << setw(30) << left << getSl();
	cout << setw(20) << left << getDg() << setw(15) << right << getNn() << setw(15) << right << getNsx();
	cout << setw(15) << right << getT() << endl;
}
std::string Sach_TK::laSachGi()const
{
	return "tham khao";
}
int Sach_TK::thanhTien()const
{
	return getSl() * getDg() + getT();
}
