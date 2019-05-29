#pragma once
#include <iostream>
#include <string>

class zona
{
protected:
	std::string denumire;
	float pret;
public:
	zona();
	zona(std::string den);
	zona(std::string den, float pret);
	zona(const zona& z);
	~zona();
	zona& operator=(const zona& z);
	int operator==(const zona z);
	friend std::istream& operator>>(std::istream& is, zona& z);
	friend std::ostream& operator<<(std::ostream& os, const zona& z);

	std::string getDenumire();
	float getPret();
	void setDenumire(std::string den);
	void setPret(float pret);
};

