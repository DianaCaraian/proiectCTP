#include "repo.h"

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