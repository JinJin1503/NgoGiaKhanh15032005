#pragma once
#include "Sach.h"
#include <string>
class Sach_TK :public Sach
{
private:
	float t;
public:
	Sach_TK();
	Sach_TK(int ms, int sl, float dg, std::string nn, std::string nsx, float t);
	~Sach_TK();
	void setT(float T);
	float getT()const;
	virtual void thongTinSach()const override;
	virtual std::string laSachGi()const override;
	virtual int thanhTien()const override;
};

