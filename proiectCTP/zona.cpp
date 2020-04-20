#pragma once
#include "zona.h"
#include <fstream>

// constructor fara parametrii
zona::zona()
{
	this->denumire = "";
	this->pret = 0.0;
}

// constructor pentru citirea din fisier a unui element de tip "zona"
zona::zona(string den)
{
	this->denumire = den;
	ifstream fi("listazone.txt");
	bool FOUND = 0;
	while (!fi.eof() && !FOUND)
	{
		string statie;
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

// constructor cu parametrii
zona::zona(string den, float pret)
{
	this->denumire = den;
	this->pret = pret;
}

// constructor de copiere
zona::zona(const zona& z)
{
	this->denumire = z.denumire;
	this->pret = z.pret;
}

// destructorul
zona::~zona()
{
	//nimic
}

// suprascrierea operatorului "="
zona& zona::operator=(const zona& z)
{
	this->denumire = z.denumire;
	this->pret = z.pret;
	return *this;
}

// suprascrierea operatorului "=="
int zona::operator==(const zona& z)
{
	return (this->denumire == z.denumire && this->pret == z.pret);
}

// suprascrierea operatorului de citire pentru atributele din clasa
istream& operator>>(istream& is, zona& z)
{
	is >> z.denumire >> z.pret;
	return is;
}

// suprascrierea operatorului de afisare pentru atributele din clasa
ostream& operator<<(ostream& os, const zona& z)
{
	os << z.denumire << ", " << z.pret;
	return os;
}

string zona::getDenumire()
{
	return this->denumire;
}

float zona::getPret()
{
	return this->pret;
}

void zona::setDenumire(string den)
{
	this->denumire = den;
}

void zona::setPret(float pret)
{
	this->pret = pret;
}