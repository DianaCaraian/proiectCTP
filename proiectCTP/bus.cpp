#include "bus.h"

bus::bus()
{
	this->data = "";
	this->nr_loc = 0;
}

bus::bus(zona destin, zona plecare, std::string data, int nr)
{
	this->destinatie = destin;
	this->plecare = plecare;
	this->data = data;
	this->nr_loc = nr;
}

bus::bus(const bus& b)
{
	this->destinatie = b.destinatie;
	this->plecare = b.plecare;
	this->data = b.data;
	this->nr_loc = b.nr_loc;
}

bus::~bus()
{
	//nimic
}

bus& bus::operator=(const bus& b)
{
	this->destinatie = b.destinatie;
	this->plecare = b.plecare;
	this->data = b.data;
	this->nr_loc = b.nr_loc;
	return *this;
}

int bus::operator==(const bus b)
{
	return (this->destinatie == b.destinatie && this->plecare == b.plecare && this->data == b.data && this->nr_loc == b.nr_loc);
}


std::istream& operator>>(std::istream& is, bus& b)
{
	std::string numezona1, numezona2;
	is >> numezona1 >> numezona2 >> b.data >> b.nr_loc;
	zona z1=zona(numezona1);
	zona z2=zona(numezona2);
	b.destinatie = z2;
	b.plecare = z1;
	return is;
}


std::ostream& operator<<(std::ostream& os,bus& b)
{
	os << b.plecare.getDenumire() << " " << b.destinatie.getDenumire() << " " << b.data << " " << b.nr_loc;
	return os;
}

zona bus::getDestinatie()
{
	return this->destinatie;
}

zona bus::getPlecare()
{
	return this->plecare;
}

std::string bus::getData()
{
	return this->data;
}

int bus::getNrLoc()
{
	return this->nr_loc;
}

void bus::setDestinatie(zona destin)
{
	this->destinatie = destin;
}

void bus::setPlecare(zona plecare)
{
	this->plecare = plecare;
}

void bus::setData(std::string data)
{
	this->data = data;
}

void bus::setNrLoc(int nr)
{
	this->nr_loc = nr;
}