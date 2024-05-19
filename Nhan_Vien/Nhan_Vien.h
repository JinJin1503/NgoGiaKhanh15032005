#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <regex>
#include <ctime>

class Nhan_Vien
{
protected:
	int ms, lcb;
	std::string ht, nvl, sdt;
public:
	Nhan_Vien();
	Nhan_Vien(int ms, std::string ht, std::string nvl, std::string sdt, int lcb);
	~Nhan_Vien();
	void setMs(int ms);
	void setHt(std::string ht);
	void setNvl(std::string nvl);
	void setSdt(std::string sdt);
	void setLcb(int lcb);
	int getMs()const;
	std::string getHt()const;
	std::string getNvl()const;
	std::string getSdt()const;
	int getLcb()const;
	virtual void thongTinNhanVien()const = 0;
	virtual float luong()const = 0;
	static bool ngayTruocHoacBangHomNay(const std::string& ngay);
	static bool kiemTraNgayHopLe(const std::string& ngay);
	static bool kiemTraSoDienThoaiHopLe(const std::string& sdt);

};

