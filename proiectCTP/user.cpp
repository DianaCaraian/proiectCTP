#include "user.h"

user::user()
{
	this->id = "";
	this->passw = "";

}

user::user(const user& u)
{
	this->id = u.id;
	this->passw = u.passw;
	this->bilete = u.bilete;
}

user::~user()
{
	//nimic
}

user& user::operator=(const user& u)
{
	this->id = u.id;
	this->passw = u.passw;
	this->bilete = u.bilete;
	return *this;
}

int user::operator==(const user u)
{
	//for (int i = 0; i < this->bilete.size(); i++)
	return(this->id == u.id && this->passw == u.passw);//&& this->bilete[i].getDenumire() == u.bilete[i].getDenumire() && this->bilete[i].getPret() == u.bilete[i].getPret());
}

std::istream& operator>>(std::istream& is, user& u)
{
	is >> u.id >> u.passw;
	return is;
}

std::string user::getId()
{
	return this->id;
}

std::string user::getPassw()
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

void user::setId(std::string id)
{
	this->id = id;
}

void user::setPassw(std::string passw)
{
	this->passw = passw;
}

void user::setBilet(int poz, zona z)
{
	this->bilete[poz] = z;
}