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
	//testFinal();
	
	ui u;
	bool log;
	std::string iduser, parolauser, decizie, data_4buy, data_4info ;
	zona zona_plecare, zona_destinatie, z_plecare_info, z_destinatie_info;
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
			cout << "lista autobuzelor :" << endl;
			u.print_bus();
			cout << endl << "doriti afisarea celei mai scurte rute ? da/nu" << endl;
			cin >> decizie;
			if (decizie == "da" || decizie == "DA" || decizie == "Da")
			{
				u.read_data_4buy(z_plecare_info, z_destinatie_info, data_4info);
				u.get_fastest_route(iduser, z_plecare_info, z_destinatie_info, data_4info);
				
			}
			
			cout << endl << endl << "doriti sa cumparati un bilet ? da/nu" << endl;
			cin >> decizie;
			if (decizie == "da" || decizie == "DA" || decizie == "Da")
			{
				int nr_bilete;
				cout << "dati numarul de bilete : " << endl;
				cin >> nr_bilete;
				for (int i = 1; i <= nr_bilete; i++)
				{
					u.read_data_4buy(zona_plecare, zona_destinatie, data_4buy);
					bool FOUND = u.buy_tickets(iduser, zona_plecare, zona_destinatie, data_4buy);
					while (FOUND == 0)
					{
						cout << "incercati din nou ... " << endl;
						u.read_data_4buy(zona_plecare, zona_destinatie, data_4buy);
						bool FOUND = u.buy_tickets(iduser, zona_plecare, zona_destinatie, data_4buy);
					}
					
				}
			}
			cout << endl << endl << "doriti afisarea istoricului dumneavoastra ? da/nu" << endl;
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