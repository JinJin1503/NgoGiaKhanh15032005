#pragma once
#include "Chuyen_Xe.h"
#include <string>
class Chuyen_Xe_Noi :public Chuyen_Xe
{
private:
	int st, km;
public:
	Chuyen_Xe_Noi();
	Chuyen_Xe_Noi(int msx, int sx, int dt, std::string ht, int st, int km);
	~Chuyen_Xe_Noi();
	void setSoTuyen(int st);
	int getSoTuyen()const;
	void setKM(int km);
	int getKM()const;
	virtual void thongTinChuyenXe()const override;
	virtual std::string laChuyenXeGi()const override;

};

