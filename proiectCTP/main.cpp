#include <iostream>
#include "ui.h"
#include "teste.h"

using namespace std;

void meniu(int &alege)
{
	cout << "0- iesire" << endl;
	cout << "1- login" << endl;
	cout << "2-logout" << endl;
	cin >> alege;
}

int main()
{
	//testFinal();
	ui u;
	std::string iduser, parolauser;
	int alege;
	meniu(alege);
	while (alege != 0)
	{
		if (alege == 1)
		{	
			u.logare(iduser, parolauser);
			cout << "doriti afisarea zonelor? 1-DA, 2-NU " << endl;
			cin >> alege;
			if (alege == 1)
			{
				u.afisZone();
			}
			meniu(alege);
		}
		else if (alege == 2)
		{
			cout << "0- iesire, 1- logare cu un alt cont" << endl;
			cin >> alege;
			if (alege == 1)
			{
				u.logare(iduser, parolauser);
				meniu(alege);
			}

		}

	}


	return 0;
}