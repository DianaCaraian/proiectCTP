#pragma once
#include <iostream>
#include <string>

using namespace std;

class zona
{
protected:
	string denumire;
	float pret;
public:
	zona();
	zona(string den); // trebe refacuta
	zona(string den, float pret);
	zona(const zona& z);
	~zona();
	zona& operator=(const zona& z);
	int operator==(const zona& z);	// ai uitat sa pui &, l-am pus eu
	friend istream& operator>>(istream& is, zona& z);
	friend ostream& operator<<(ostream& os, const zona& z);

	string getDenumire();
	float getPret();
	void setDenumire(string den);
	void setPret(float pret);
};
