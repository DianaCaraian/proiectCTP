#include "user.h"

// constructorul fara parametrii
user::user()
{
	this->id = "";
	this->passw = "";

}

// constructorul cu parametrii
user::user(const user& u)
{
	this->id = u.id;
	this->passw = u.passw;
	this->bilete = u.bilete;
}

// destructorul
user::~user()
{
	//nimic
}

// suprascrierea operatorului "="
user& user::operator=(const user& u)
{
	this->id = u.id;
	this->passw = u.passw;
	this->bilete = u.bilete;
	return *this;
}

// suprascrierea operatorului "=="
int user::operator==(const user u)
{
	return(this->id == u.id && this->passw == u.passw);
}

// suprascrierea operatorului de citire pentru atributele din clasa
istream& operator>>(istream& is, user& u)
{
	is >> u.id >> u.passw;
	return is;
}

string user::getId()
{
	return this->id;
}

string user::getPassw()
{
	return this->passw;
}

zona& user::getBilet(int poz)
{
	return this->bilete[poz];
}

int user::getDimBilete()
{
	return this->bilete.size();
}

void user::setId(string id)
{
	this->id = id;
}

void user::setPassw(string passw)
{
	this->passw = passw;
}

void user::setBilet(int poz, zona z)
{
	this->bilete[poz] = z;
}