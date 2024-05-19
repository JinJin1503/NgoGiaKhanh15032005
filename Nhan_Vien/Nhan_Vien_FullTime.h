#pragma once
#include "Nhan_Vien.h"
class Nhan_Vien_FullTime :public Nhan_Vien
{
private:
	float hsl, snkn;
public:
	Nhan_Vien_FullTime();
	Nhan_Vien_FullTime(int ms, std::string ht, std::string nvl, std::string sdt, int lcb, float hsl, float snkn);
	~Nhan_Vien_FullTime();
	void setHsl(float hsl);
	void setSnkn(float snkn);
	float getHsl()const;
	float getSnkn()const;
	virtual void thongTinNhanVien()const override;
	virtual float luong()const override;

};

