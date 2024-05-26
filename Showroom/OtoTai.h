#pragma once
#include "Showroom.h"
class OtoTai :public Showroom
{
private:
	int  taiTrong;
public:
	OtoTai();
	OtoTai(string, int, double, long long int, int);
	void setTaiTrong( int taiTrong);
	int getTaiTrong() const;
	void toString() const override;
	long long int tinhThue() const override;
	long int thueTruocBa() const override;
	friend ostream& operator<<(ostream& out, const OtoTai& f);
};



