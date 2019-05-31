#include "ui.h"

ui::ui()
{
	//nimic
}

//ui::ui(ctrl c2)
//{
//	this->c = c2;
//}

ui::ui(const ui& u)
{
	this->c = u.c;
}

ui::~ui()
{
	//nimic
}

ui& ui::operator=(const ui& u)
{
	this->c = u.c;
	return *this;
}

ctrl& ui::getCtrl()
{
	return this->c;
}

void ui::afisZone()
{
	
}

void ui::logare(std::string &iduser, std::string &parolauser)
{
	std::cout << "id : ";
	std::cin >> iduser;
	std::cout << "paroala : ";
	std::cin >> parolauser;
	bool GASIT = 0;
	std::ifstream fi("listaid.in");
	while (!fi.eof() && GASIT == 0)
	{
		std::string idfisier, parolafis;
		fi >> idfisier >> parolafis;
		if (iduser == idfisier && parolauser == parolafis)
			GASIT = 1;
	}
	if (GASIT == 1)
		std::cout << "autentificare cu succes" << std::endl;
	else std::cout << "id sau parola incorecta" << std::endl;
}