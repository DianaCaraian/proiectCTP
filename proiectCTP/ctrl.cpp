#include "ctrl.h"

// constructorul fara parametrii
ctrl::ctrl()
{
	//nimic
}

// construcotrul de copiere
ctrl::ctrl(const ctrl& c)
{
	this->rb = c.rb;
}

// destructorul
ctrl::~ctrl()
{
	//nimic
}

// suprascrierea operatorului "="
ctrl& ctrl::operator=(const ctrl& c)
{
	this->rb = c.rb;
	return *this;
}

// functie care returneaza tot vectorul cu elemente de tip "bus"
repo& ctrl::getRepoBus()
{
	return this->rb;
}