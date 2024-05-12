#include "Chuyen_Xe_Ngoai.h"
#include "Chuyen_Xe.h"
using namespace std;
Chuyen_Xe_Ngoai::Chuyen_Xe_Ngoai() :Chuyen_Xe()
{
	this->sn;
	this->nd;
}
Chuyen_Xe_Ngoai::Chuyen_Xe_Ngoai(int Msx, int Sx, int Dt, std::string Ht, int Sn, std::string Nd) :Chuyen_Xe(Msx, Sx, Dt, Ht)
{
	this->sn = Sn;
	this->nd = Nd;
}
Chuyen_Xe_Ngoai::~Chuyen_Xe_Ngoai() {}
void Chuyen_Xe_Ngoai::setSoNgay(int Sn)
{
	this->sn = Sn;
}
int Chuyen_Xe_Ngoai::getSoNgay()const
{
	return sn;
}
void Chuyen_Xe_Ngoai::setNoiDen(std::string Nd)
{
	this->nd = Nd;
}
std::string Chuyen_Xe_Ngoai::getNoiDen()const
{
	return nd;
}
void Chuyen_Xe_Ngoai::thongTinChuyenXe() const
{
	cout << setfill(' ');
	cout << setw(10) << left << getMaSo() << setw(25) << left << getHoTen();
	cout << setw(15) << left << getSoXe() << setw(10) << right << getSoNgay() << setw(10) << right << getNoiDen();
	cout << setw(15) << right << getDthu() << endl;
}
std::string  Chuyen_Xe_Ngoai::laChuyenXeGi() const
{
	return "ngoai thanh";
}


