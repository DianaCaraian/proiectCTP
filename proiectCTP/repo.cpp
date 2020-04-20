#include "repo.h"

// functie pentru citirea din fisier a unui element de tip "bus"
void repo::loadfile(string namefile)
{
	ifstream f(namefile);
	while (!f.eof())
	{
		bus elem;
		f >> elem;
		this->v.push_back(elem);
	}
	f.close();
}

// constructorul fara parametrii
repo::repo()
{
	//nimic
}

// constructorul de copiere
repo::repo(const repo& r)
{
	this->v = r.v;
}

// destructorul
repo::~repo()
{
	//nimic
}

// suprascrierea operatorului "="
repo& repo::operator=(const repo& r)
{
	this->v = r.v;
	return *this;
}

// functie care returneaza elementul de pe pozitia "poz"
bus& repo::getElem(int poz)
{
	return this->v[poz];
}

// functie care returneaza dimensiunea vectorului
int repo::getDim()
{
	int dim = this->v.size();
	return dim;
}
