#include "ui.h"
#include <queue>

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
	for (int i = 0; i < c.getRepoBus().getDim(); i++)
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
		}															// care apare din cauza fi.eof()
	}

	std::cout << "bilet cumparat!" << std::endl;
	return FOUND;
}

//void initiate_previous(std::vector <int>& previous_node, int dim)
//{
//	for (int i = 0; i < dim; i++)
//		previous_node.push_back(-1);
//}
//
//void initiate_s(int& s, zona & plecare, std::vector <std::string> node_set)
//{
//	for (int i = 0; i < node_set.size(); i++)
//		if (node_set[i] == plecare.getDenumire())
//		{
//			s = i;
//			return;
//		}
//}
//
//void set_note_set(std::vector <std::string> & node_set)
//{
//	std::ifstream fi("listabus.txt");
//	while (!fi.eof())
//	{
//		bus b;
//		fi >> b;
//		bool FOUND = 0;											// verificam sa nu apara in multime
//		for (int i = 0; i < node_set.size() && !FOUND; i++)
//		{
//			if (node_set[i] == b.getDestinatie().getDenumire())
//				FOUND = 1;
//			else
//				node_set.push_back(b.getDestinatie().getDenumire());
//
//			if (node_set[i] == b.getPlecare().getDenumire())
//				FOUND = 1;
//			else
//				node_set.push_back(b.getPlecare().getDenumire());
//		}
//	}
//}
//
//void set_adjacency_list(std::vector<int> v[100], std::vector <std::string> node_set)
//{
//	std::ifstream fi("listabus_txt");
//	while (!fi.eof())
//	{
//		bus b;
//		fi >> b;
//		int ind_plecare = -1, ind_destinatie = -1;
//		for (int i = 0; i < node_set.size() && ind_plecare == -1 && ind_destinatie == -1; i++)
//		{
//			if (node_set[i] == b.getPlecare().getDenumire())
//				ind_plecare = i;
//			if (node_set[i] == b.getDestinatie().getDenumire())
//				ind_destinatie = i;
//		}
//		v[ind_plecare].push_back(ind_destinatie);
//	}
//}
//
////vector <int> v[100];   //Vector for maintaining adjacency list explained above
////int level[100]; //To determine the level of each node
////bool vis[100]; //Mark the node if visited 
//
//void bfs(std::vector<int> v[100], int level[100], bool vis[100], int s, std::vector <std::string> node_set, std::vector <int> & previous_node)
//{
//	std::queue <int> q;
//	q.push(s);
//	level[s] = 0;  //Setting the level of the source node as 0
//	vis[s] = true;
//	while (!q.empty())
//	{
//		int p = q.front();
//		q.pop();
//		for (unsigned int i = 0; i < v[p].size(); i++)
//		{
//			if (vis[v[p][i]] == false)
//			{
//				//Setting the level of each node with an increment in the level of parent node
//				previous_node[i] = p;
//				level[v[p][i]] = level[p] + 1;
//				q.push(v[p][i]);
//				vis[v[p][i]] = true;
//			}
//		}
//	}
//}
//
//
//std::vector<bus> ui::get_fastest_route(std::string id_wanted, zona& z, zona& z2, std::string date)
//{
//	std::vector<int> v[100];
//	int level[100] = { 0 };
//	bool vis[100] = { 0 };
//	int s = 0;
//	
//	std::vector <std::string> node_set;				// multime cu numele tuturor zonelor
//	set_note_set(node_set);							// initializam multimea
//	
//	std::vector <int> previous_node;				// multime cu vector de tati (cu indici) pt fiecare nod cand scoatem cea mai rapida ruta
//	set_adjacency_list(v, node_set);			
//
//	initiate_s(s, z, node_set);						// initializam nodul de unde pornim bfs
//
//	int dim = node_set.size();
//	initiate_previous(previous_node, dim);			// initializam vectorul de tati
//
//	bfs(v, level, vis, s, node_set, previous_node);	// bfs care da distanta 
//
//	int min = 1000000;								// se ia nivelul minim
//	for (int i = 0; i < node_set.size(); i++)
//		if (level[i] < min)
//			min = level[i];
//
//	for (int i = 0; i < node_set.size(); i++)
//		if (level[i] == min)
//		{
//			int j = i;
//			while (previous_node[j] != -1)
//			{
//				std::cout << j << "-" << previous_node[j]<<" ";
//				j = previous_node[j];
//			}
//		}
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