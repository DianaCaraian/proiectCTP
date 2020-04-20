#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "bus.h"
#include "user.h"

class repo
{
protected:
	vector<bus> v;
public:
	repo();
	repo(const repo& r);
	~repo();
	repo& operator=(const repo& r);
	bus& getElem(int poz);
	int getDim();
	void loadfile(string namefile);
};