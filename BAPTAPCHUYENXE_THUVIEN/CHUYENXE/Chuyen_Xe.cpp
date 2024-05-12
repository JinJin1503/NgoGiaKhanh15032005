#include "Chuyen_Xe.h"
Chuyen_Xe::Chuyen_Xe()
{
	this->msx;
	this->ht;
	this->sx;
	this->dt;
}
Chuyen_Xe::Chuyen_Xe(int Msx, int Sx, int Dt, std::string Ht)
{
	this->msx = Msx;
	this->sx = Sx;
	this->dt = Dt;
	this->ht = Ht;
}
Chuyen_Xe::~Chuyen_Xe() {}
void Chuyen_Xe::setMaSo(int Msx)
{
	this->msx = Msx;
}
int Chuyen_Xe::getMaSo()const
{
	return msx;
}
void Chuyen_Xe::setSoXe(int Sx)
{
	this->sx = Sx;
}
int Chuyen_Xe::getSoXe()const
{
	return sx;
}
void Chuyen_Xe::setDthu(int Dt)
{
	this->dt = Dt;
}
int Chuyen_Xe::getDthu()const
{
	return dt;
}
void Chuyen_Xe::setHoTen(std::string Ht)
{
	this->ht = Ht;
}
std::string Chuyen_Xe::getHoTen()const
{
	return ht;
}
