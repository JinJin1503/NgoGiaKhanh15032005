#include "Sach.h"
Sach::Sach()
{
	this->ms;
	this->sl;
	this->dg;
	this->nn;
	this->nsx;
}
Sach::Sach(int Ms, int Sl, float Dg, std::string Nn, std::string Nsx)
{
	ms = Ms;
	sl = Sl;
	dg = Dg;
	nn = Nn;
	nsx = Nsx;
}
Sach::~Sach() {}
void Sach::setMs(int Ms)
{
	ms = Ms;
}
int Sach::getMs()const
{
	return ms;
}
void Sach::setSl(int Sl)
{
	sl = Sl;
}
int Sach::getSl()const
{
	return sl;
}
void Sach::setDg(float Dg)
{
	dg = Dg;
}
float Sach::getDg()const
{
	return dg;
}
void Sach::setNn(std::string Nn)
{
	nn = Nn;
}
std::string Sach::getNn()const
{
	return nn;
}
void Sach::setNsx(std::string Nsx)
{
	nsx = Nsx;
}
std::string Sach::getNsx()const
{
	return nsx;
}

