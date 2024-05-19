#include "Nhan_Vien_FullTime.h"
#include "Nhan_Vien.h"
using namespace std;
Nhan_Vien_FullTime::Nhan_Vien_FullTime() :Nhan_Vien()
{
	this->hsl;
	this->snkn;
}
Nhan_Vien_FullTime::Nhan_Vien_FullTime(int ms, std::string ht, std::string nvl, std::string sdt, int lcb, float hsl, float snkn) :Nhan_Vien(ms, ht, nvl, sdt, lcb)
{
	this->hsl = hsl;
	this->snkn = snkn;
}
Nhan_Vien_FullTime::~Nhan_Vien_FullTime() {}
void Nhan_Vien_FullTime::setHsl(float hsl)
{
	if (hsl < 1.65 || hsl>8)
	{
		throw invalid_argument("He so luong khong hop le");
	}
	this->hsl = hsl;
}
void Nhan_Vien_FullTime::setSnkn(float snkn)
{
	if (snkn < 0)
	{
		throw invalid_argument("So nam kinh nghiem khong hop le");
	}
	this->snkn = snkn;
}
float Nhan_Vien_FullTime::getHsl()const
{
	return hsl;
}
float Nhan_Vien_FullTime::getSnkn()const
{
	return snkn;
}
void Nhan_Vien_FullTime::thongTinNhanVien()const
{
	cout << setfill(' ');
	cout << setw(5) << left << getMs() << setw(20) << left << getHt();
	cout << setw(15) << left << getNvl() << setw(15) << right << getSdt() << setw(10) << right << getLcb();
	cout << setw(15) << right << getHsl() << setw(15) << right << getSnkn() << endl;
}
float Nhan_Vien_FullTime::luong()const
{
	float lths = lcb * hsl;
	return lths + (snkn / 100) * lths;
}
