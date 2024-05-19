#pragma once
#include "Nhan_Vien.h"
class Nhan_Vien_PartTime :public Nhan_Vien
{
private:
	float sgl, ml;
public:
	Nhan_Vien_PartTime();
	Nhan_Vien_PartTime(int ms, std::string ht, std::string nvl, std::string sdt, int lcb, float sgl, float ml);
	~Nhan_Vien_PartTime();
	void setSgl(float sgl);
	void setMl(float ml);
	float getSgl()const;
	float getMl()const;
	virtual void thongTinNhanVien()const override;
	virtual float luong()const override;

};

