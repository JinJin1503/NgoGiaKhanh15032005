#pragma once
#include "Chuyen_Xe.h"
#include <string>
class Chuyen_Xe_Ngoai :public Chuyen_Xe
{
private:
	int sn;
	std::string nd;
public:
	Chuyen_Xe_Ngoai();
	Chuyen_Xe_Ngoai(int msx, int sx, int dt, std::string ht, int sn, std::string nd);
	~Chuyen_Xe_Ngoai();
	void setSoNgay(int sn);
	int getSoNgay()const;
	void setNoiDen(std::string nd);
	std::string getNoiDen()const;
	void thongTinChuyenXe()const override;
	std::string laChuyenXeGi()const override;

};
