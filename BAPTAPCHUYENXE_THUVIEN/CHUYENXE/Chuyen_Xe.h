#pragma once
#include <string>
#include<iomanip>
#include <iostream>
#include<vector>
class Chuyen_Xe
{
private:
	int msx, sx, dt;
	std::string ht;
public:
	Chuyen_Xe();
	Chuyen_Xe(int msx, int sx, int dt, std::string ht);
	~Chuyen_Xe();
	void setMaSo(int msx);
	int getMaSo()const;
	void setSoXe(int sx);
	int getSoXe()const;
	void setDthu(int dt);
	int getDthu()const;
	void setHoTen(std::string ht);
	std::string getHoTen()const;
	virtual void thongTinChuyenXe()const = 0;
	virtual std::string laChuyenXeGi()const = 0;
};