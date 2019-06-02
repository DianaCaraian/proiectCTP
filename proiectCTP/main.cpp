#include <iostream>
#include "ui.h"
#include "teste.h"

using namespace std;

void meniu(int &alege)
{
	cout << "0- iesire" << endl;
	cout << "1- login" << endl;
	cin >> alege;
}

int main()
{
	ui u;
	zona a = zona("Regioasdsdasdasnala");
	zona b = zona("Centru");
	u.buy_tickets("diana", a, b, "20-08-2019");
	//testFinal();
	ui u;
	bool log;
	std::string iduser, parolauser, decizie, data_4buy, id_4buy;
	zona zona_plecare, zona_destinatie;
	int alege;
	meniu(alege);
	while (alege != 0)
	{
		log = u.logare(iduser, parolauser);
		while (log != true)
		{
			cout << "id sau parola incorecta... incercati din nou" << endl;
			log = u.logare(iduser, parolauser);
		}
		if (log == 1)
		{
			cout << "autentificare cu succes" << endl;
			cout << "doriti sa cumparati un bilet ? da/nu" << endl;
			cin >> decizie;
			while (decizie == "da" || decizie == "DA" || decizie == "Da")
			{
				u.read_data_4buy(zona_plecare, zona_destinatie, data_4buy);
				bool FOUND = u.buy_tickets(iduser, zona_plecare, zona_destinatie, data_4buy);
				if (FOUND == 0)
				{
					cout << "doriti sa mai incercati ? da/nu" << endl;
					cin >> decizie;
				}
				else decizie = "nu";

			}
			cout << "doriti afisarea istoricului dumneavoastra ? da/nu" << endl;
			cin >> decizie;
			if (decizie == "da" || decizie == "DA" || decizie == "Da")
			{
				u.show_tickets(iduser);
			}

		meniu(alege);
		}

	}

	return 0;
}