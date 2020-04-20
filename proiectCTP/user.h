#pragma once
#include "zona.h"
#include <vector>

class user
{
protected:
	string id, passw;
	vector<zona> bilete;
public:
	user();
	user(const user& u);
	~user();
	user& operator=(const user& u);
	int operator==(const user u);
	friend istream& operator>>(istream& is, user& u);
	// trebe operator de scriere  , pt actualizare fisier
	string getId();
	string getPassw();
	zona& getBilet(int poz);
	int getDimBilete();
	void setId(string id);
	void setPassw(string passw);
	void setBilet(int poz, zona z);

};