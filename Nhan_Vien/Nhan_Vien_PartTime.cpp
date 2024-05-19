#include "Nhan_Vien_PartTime.h"
#include "Nhan_Vien.h"
using namespace std;
Nhan_Vien_PartTime::Nhan_Vien_PartTime() :Nhan_Vien()
{
	this->sgl;
	this->ml;
}
Nhan_Vien_PartTime::Nhan_Vien_PartTime(int ms, std::string ht, std::string nvl, std::string sdt, int lcb, float sgl, float ml) :Nhan_Vien(ms, ht, nvl, sdt, lcb)
{
	this->sgl = sgl;
	this->ml = ml;
}
Nhan_Vien_PartTime::~Nhan_Vien_PartTime() {}
void Nhan_Vien_PartTime::setSgl(float sgl)
{
	if (sgl < 0)
	{
		throw invalid_argument("So gio lam khong hop le");
	}
	this->sgl = sgl;
}
void Nhan_Vien_PartTime::setMl(float ml)
{
	if (ml < 0)
	{
		throw invalid_argument("Muc luong khong  hop le");
	}
	this->ml = ml;
}
float Nhan_Vien_PartTime::getSgl()const
{
	return sgl;
}
float Nhan_Vien_PartTime::getMl()const
{
	return ml;
}
void Nhan_Vien_PartTime::thongTinNhanVien()const
{
	cout << setfill(' ');
	cout << setw(5) << left << getMs() << setw(20) << left << getHt();
	cout << setw(15) << left << getNvl() << setw(15) << right << getSdt() << setw(10) << right << getLcb();
	cout << setw(15) << right << getSgl() << setw(15) << right << getMl() << endl;
}
float Nhan_Vien_PartTime::luong()const
{
	float lsp = sgl * ml;
	if (sgl > 40)
	{
		lsp = lsp + ((sgl - 40) * ml) * 0.5;
	}
	return 0.3 * lcb + lsp;
}
