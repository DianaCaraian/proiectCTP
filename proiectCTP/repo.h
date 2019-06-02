#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "bus.h"
#include "user.h"
//#include "zona.h"

class repo
{
protected:
	std::vector<bus> v;
public:
	repo();
	repo(const repo& r);
	~repo();
	repo& operator=(const repo& r);
	bus& getElem(int poz);
	int getDim();
	void loadfile(std::string namefile);
};

void repo::loadfile(std::string namefile)
{
	std::ifstream f(namefile);
	while (!f.eof())
	{
		bus elem;
		f >> elem;
		this->v.push_back(elem);
	}
	f.close();
}

repo::repo()
{
	//nimic
}

//template <class T>
//repo<T>::repo(T v2[])
//{
//	this->v = v2;
//}
 

repo::repo(const repo& r)
{
	this->v = r.v;
}

repo::~repo()
{
	//nimic
}

repo& repo::operator=(const repo& r)
{
	this->v = r.v;
	return *this;
}

//bus& repo::getElem(int poz)
//{
//	return this->v[poz];
//}

bus& repo::getElem(int poz)
{
	return this->v[poz];
}

int repo::getDim()
{
	int dim = this->v.size();
	return dim;
}