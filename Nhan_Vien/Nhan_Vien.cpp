#include "Nhan_Vien.h"
#include <sstream>
using namespace std;
Nhan_Vien::Nhan_Vien()
{
	this->ms;
	this->ht;
	this->nvl;
	this->sdt;
	this->lcb;
}
Nhan_Vien::Nhan_Vien(int ms, std::string ht, std::string nvl, std::string sdt, int lcb)
{
	this->ms = ms;
	this->ht = ht;
	this->nvl = nvl;
	this->sdt = sdt;
	this->lcb = lcb;
}
Nhan_Vien::~Nhan_Vien() {}
void Nhan_Vien::setMs(int ms)
{
	if (ms <= 0)
	{
		throw invalid_argument("Ma so khong duoc be hon 0");
	}
	this->ms = ms;
}
void Nhan_Vien::setHt(std::string ht)
{
	if (ht.empty())
	{
		throw invalid_argument("Ho ten nhan vien khong duoc de trong");
	}
	this->ht = ht;
}
void Nhan_Vien::setNvl(std::string nvl)
{
	if (!kiemTraNgayHopLe(nvl) || !ngayTruocHoacBangHomNay(nvl))
	{
		throw invalid_argument("Ngay vao lam khong hop le");
	}
	this->nvl = nvl;
}
void Nhan_Vien::setSdt(std::string sdt)
{
	if (!kiemTraSoDienThoaiHopLe(sdt))
	{
		throw invalid_argument("So dien thoai khong hop le");
	}
	this->sdt = sdt;
}
void Nhan_Vien::setLcb(int lcb)
{
	if (lcb < 0)
	{
		throw invalid_argument("Luong can ban khong duoc nho hon 0");
	}
	this->lcb = lcb;
}
int Nhan_Vien::getMs()const
{
	return ms;
}
std::string Nhan_Vien::getHt()const
{
	return ht;
}
std::string Nhan_Vien::getNvl()const
{
	return nvl;
}
std::string Nhan_Vien::getSdt()const
{
	return sdt;
}
int Nhan_Vien::getLcb()const
{
	return lcb;
}
bool Nhan_Vien::ngayTruocHoacBangHomNay(const string& ngay)
{
	std::tm tm = {};
	std::stringstream  ss(ngay);
	ss >> std::get_time(&tm, "%Y-%m-%d");

	std::time_t hireTime = std::mktime(&tm);

	std::time_t now = std::time(nullptr);

	return hireTime <= now;

}
bool Nhan_Vien::kiemTraNgayHopLe(const std::string& ngay)
{
	std::regex datePattern("^\\d{4}-\\d{2}-\\d{2}$");
	return std::regex_match(ngay, datePattern);
}

bool Nhan_Vien::kiemTraSoDienThoaiHopLe(const std::string& sdt)
{
	std::regex phonePattern("^0\\d{9}$");
	return std::regex_match(sdt, phonePattern);
}
