#include "ctrl.h"

ctrl::ctrl()
{
	//nimic
}

ctrl::ctrl(repo<bus> rb2)
{
	this->rb = rb2;
}

ctrl::ctrl(const ctrl& c)
{
	this->rb = c.rb;
}

ctrl::~ctrl()
{
	//nimic
}

ctrl& ctrl::operator=(const ctrl& c)
{
	this->rb = c.rb;
	return *this;
}

repo<bus> ctrl::getRepoBus()
{
	return this->rb;
}

repo<user> ctrl::getRepoUser()
{
	return this->ru;
}

void ctrl::afis()
{
	cout << endl << "lista zonelor si pretul: " << endl;
	this->rz.loadfile("listazone.in");

	for (int i = 0; i < this->rz.getDim(); i++)
	{
		zona z2 = this->rz.getElem(i);
		cout << z2 << endl;
	}

}

