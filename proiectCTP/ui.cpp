#include "ui.h"

ui::ui()
{
	//nimic
}

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

void ui::print_bus()
{
	for (unsigned int i = 0; i < c.getRepoBus().getDim(); i++)
	{
		bus b = c.getRepoBus().getElem(i);
		std::cout << b << std::endl;
	}
}

void ui::show_tickets(std::string id_wanted)
{
	std::ifstream fi("listabilete.txt");
	bool FOUND = 0;
	while (!fi.eof() && !FOUND)
	{
		std::string id;
		int no_tickets;
		bus b; 
		fi >> id >> no_tickets;
		if (id == id_wanted)
			FOUND = 1;
		for (int i = 1; i <= no_tickets; i++)
		{
			fi >> b;
			if (FOUND == 1)
				std::cout << b << std::endl;
		}
	}
	fi.close();
}

// trebe facuta validare pe numar de locuri
bool ui::buy_tickets(std::string id_wanted,zona& z1,zona& z2,std::string date)
{
	// se descarca fisierul
	std::vector <std::string> id;
	std::vector<bus> b[100];	// matrix
	std::ifstream fi("listabilete.txt");
	int nr_id = 0;
	while (!fi.eof())
	{
		std::string new_id;
		fi >> new_id;
		id.push_back(new_id);
		int no_tickets;
		fi >> no_tickets;
		bus a;
		for (int i = 1; i <= no_tickets; i++)
		{
			fi >> a;
			b[nr_id].push_back(a);
		}
		nr_id++;
	}

	// se scad nr de locuri
	bool FOUND=0;
	for (int i = 0; i < nr_id && !FOUND; i++)
		for (int j = 0; j < b[i].size() && !FOUND; j++)
			if (b[i][j].getData() == date)
				if (b[i][j].getDestinatie()/*.getDenumire()*/ == z2/*.getDenumire()*/)
					if (b[i][j].getPlecare().getDenumire() == z1.getDenumire())
					{
						FOUND = 1;
						b[i][j].setNrLoc(b[i][j].getNrLoc() - 1);
					}

	if (!FOUND)
	{
		std::cout << "biletul cautat nu exista" << std::endl;
		return 0;
	}

	std::ofstream fo("listabilete.txt");
	// se incarca datele noi in fisier
	for (int i = 0; i < nr_id; i++)
	{
		fo << id[i] << " " << b[i].size() << std::endl;
		for (int j = 0; j < b[i].size(); j++)
		{
			fo << b[i][j] /*<< std::endl*/;
			if (j < b[i].size() - 1 || i < nr_id-1)					// se evita aparitia ultimului endl
				fo << std::endl;									// rezolva bugul pt cumparari multiple
		}
	}

	std::cout << "bilet cumparat!" << std::endl;
	return FOUND;
}

//std::vector<bus> ui::get_fastest_route()
//{
//	std::string a="";
//	return a;
//}

bool ui::logare(std::string &iduser, std::string &parolauser)
{
	std::cout << "id : ";
	std::cin >> iduser;
	std::cout << "paroala : ";
	std::cin >> parolauser;
	bool GASIT = false;
	std::ifstream fi("listaid.txt");
	while (!fi.eof() && GASIT == 0)
	{
		std::string idfisier, parolafis;
		fi >> idfisier >> parolafis;
		if (iduser == idfisier && parolauser == parolafis)
			GASIT = true;
	}
	/*if (GASIT == 1)
		std::cout << "autentificare cu succes" << std::endl;
	else std::cout << "id sau parola incorecta" << std::endl;*/

	return GASIT;
}

void ui::read_data_4buy( zona& z1, zona& z2, std::string& date)
{
	/*std::cout << "dati id-ul : ";
	std::cin >> id;*/
	std::cout << "dati zona de plecare : ";
	std::string nume_plecare, nume_destinatie;
	std::cin >> nume_plecare;
	zona read_z1 = zona(nume_plecare);
	z1 = read_z1;
	std::cout << "dati zona de destinatie : ";
	std::cin >> nume_destinatie;
	zona read_z2 = zona(nume_destinatie);
	z2 = read_z2;
	std::cout << "dati data : ";
	std::cin >> date;
}