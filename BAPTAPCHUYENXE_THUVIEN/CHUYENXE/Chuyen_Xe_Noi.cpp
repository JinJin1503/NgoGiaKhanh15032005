#include "Chuyen_Xe_Noi.h"
#include "Chuyen_Xe.h"
using namespace std;

Chuyen_Xe_Noi::Chuyen_Xe_Noi() :Chuyen_Xe()
{
	this->st;
	this->km;
}
Chuyen_Xe_Noi::Chuyen_Xe_Noi(int Msx, int Sx, int Dt, std::string Ht, int St, int Km) :Chuyen_Xe(Msx, Sx, Dt, Ht)
{
	this->st = St;
	this->km = Km;
}
Chuyen_Xe_Noi::~Chuyen_Xe_Noi() {}
void Chuyen_Xe_Noi::setSoTuyen(int St)
{
	this->st = St;
}
int Chuyen_Xe_Noi::getSoTuyen()const
{
	return st;
}
void Chuyen_Xe_Noi::setKM(int Km)
{
	this->km = Km;
}
int Chuyen_Xe_Noi::getKM()const
{
	return km;
}
void Chuyen_Xe_Noi::thongTinChuyenXe()const
{
	cout << setfill(' ');
	cout << setw(10) << left << getMaSo() << setw(25) << left << getHoTen();
	cout << setw(15) << left << getSoXe() << setw(10) << right << getSoTuyen() << setw(10) << right << getKM();
	cout << setw(15) << right << getDthu() << endl;
}
std::string  Chuyen_Xe_Noi::laChuyenXeGi()const
{
	return "noi thanh";
}

