#include "zona.h"
#include <fstream>

zona::zona()
{
	this->denumire = "";
	this->pret = 0.0;
}

zona::zona(std::string den)
{
	this->denumire = den;
	std::ifstream fi("listazone.txt");
	bool FOUND = 0;
	while (!fi.eof() && !FOUND)
	{
		std::string statie;
		float pret2;
		fi >> statie >> pret2;
		if (statie == den)
		{
			FOUND = 1;
			this->pret = pret2;
		}
	}
	fi.close();
}

zona::zona(std::string den, float pret)
{
	this->denumire = den;
	this->pret = pret;
}

zona::zona(const zona& z)
{
	this->denumire = z.denumire;
	this->pret = z.pret;
}

zona::~zona()
{
	//nimic
}

zona& zona::operator=(const zona& z)
{
	this->denumire = z.denumire;
	this->pret = z.pret;
	return *this;
}

int zona::operator==(const zona& z)
{
	return (this->denumire == z.denumire && this->pret == z.pret);
}

std::istream& operator>>(std::istream& is, zona& z)
{
	is >> z.denumire >> z.pret;
	return is;
}

std::ostream& operator<<(std::ostream& os, const zona& z)
{
	os << z.denumire << ", " << z.pret;
	return os;
}

std::string zona::getDenumire()
{
	return this->denumire;
}

float zona::getPret()
{
	return this->pret;
}

void zona::setDenumire(std::string den)
{
	this->denumire = den;
}

void zona::setPret(float pret)
{
	this->pret = pret;
}