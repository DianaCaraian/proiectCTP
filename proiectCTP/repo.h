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
