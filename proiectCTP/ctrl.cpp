#include "ctrl.h"

ctrl::ctrl()
{
	//nimic
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

repo& ctrl::getRepoBus()
{
	return this->rb;
}
