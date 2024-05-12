#pragma once
#include "Sach.h"
#include <string>
class Sach_GK :public Sach
{
private:
	std::string tt;
public:
	Sach_GK();
	Sach_GK(int ms, int sl, float dg, std::string nn, std::string nsx, std::string tt);
	~Sach_GK();
	void setTt(std::string tt);
	std::string getTt()const;
	virtual void thongTinSach()const override;
	virtual std::string laSachGi()const override;
	virtual int thanhTien()const override;
};

