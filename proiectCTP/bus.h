#pragma once
#include "zona.h"

class bus
{
protected:
	zona destinatie, plecare;
	string data;
	int nr_loc;
public:
	bus();
	bus(zona destin, zona plecare, string data, int nr); // asta nu cred ca e necesar
	bus(const bus& b);
	~bus();
	bus& operator=(const bus& b);
	int operator==(const bus b);
	friend istream& operator>>(istream& is, bus& b);
	friend ostream& operator<<(ostream& os, bus& b);

	zona getDestinatie();
	zona getPlecare();
	string getData();
	int getNrLoc();
	void setDestinatie(zona destin);
	void setPlecare(zona plecare);
	void setData(string data);
	void setNrLoc(int nr);
};
