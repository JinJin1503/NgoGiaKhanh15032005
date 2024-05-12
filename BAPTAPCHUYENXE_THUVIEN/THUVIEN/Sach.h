#pragma once
#include<string>
#include<iostream>
#include<iomanip>

class Sach
{
protected:
	int ms, sl;
	std::string nn, nsx;
	float dg;
public:
	Sach();
	Sach(int ms, int sl, float dg, std::string nn, std::string nsx);
	~Sach();
	void setMs(int ms);
	int getMs()const;
	void setSl(int sl);
	int getSl()const;
	void setNn(std::string nn);
	std::string getNn()const;
	void setNsx(std::string nsx);
	std::string getNsx()const;
	void setDg(float dg);
	float getDg()const;
	virtual void thongTinSach()const = 0;
	virtual std::string laSachGi()const = 0;
	virtual int thanhTien()const = 0;

};

