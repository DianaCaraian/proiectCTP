#pragma once
#include "zona.h"

class bus
{
protected:
	zona destinatie, plecare;
	std::string data;
	int nr_loc;
public:
	bus();
	bus(zona destin, zona plecare, std::string data, int nr);
	bus(const bus& b);
	~bus();
	bus& operator=(const bus& b);
	int operator==(const bus b);
	friend std::istream& operator>>(std::istream& is, bus& b);
	friend std::ostream& operator<<(std::ostream& os, bus& b);
	
	zona getDestin();
	zona getPlecare();
	std::string getData();
	int getNrLoc();
	void setDestin(zona destin);
	void setPlecare(zona plecare);
	void setData(std::string data);
	void setNrLoc(int nr);
};

