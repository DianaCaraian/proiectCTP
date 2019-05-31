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
	this->c.afis();
}

void ui::logare(string &iduser, string &parolauser)
{
	cout << "id : ";
	cin >> iduser;
	cout << "paroala : ";
	cin >> parolauser;
	bool GASIT = 0;
	ifstream fi("listaid.in");
	while (!fi.eof() && GASIT == 0)
	{
		string idfisier, parolafis;
		fi >> idfisier >> parolafis;
		if (iduser == idfisier && parolauser == parolafis)
			GASIT = 1;
	}
	if (GASIT == 1)
		cout << "autentificare cu succes" << endl;
	else cout << "id sau parola incorecta" << endl;
}