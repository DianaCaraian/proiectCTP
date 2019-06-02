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
	c.getRepoBus().loadfile("listabus.txt");
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
	// se descarca fisierul cu lista bilete
	std::vector <std::string> id;
	std::vector<bus> b[100];	// matrix
	std::ifstream fi("listabilete.txt");
	int nr_id = 0;
	int POS_ID_WANTED;
	int pos = 0;
	while (!fi.eof())
	{
		std::string new_id;
		fi >> new_id;
		if (new_id == id_wanted)
			POS_ID_WANTED = pos;
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
		pos++;
	}

	c.getRepoBus().loadfile("listabus.txt");

	bool FOUND = 0;
	bus searched_bus;
	for (int i=0;i<c.getRepoBus().getDim() && !FOUND;i++)
		if (c.getRepoBus().getElem(i).getPlecare()==z1)
			if (c.getRepoBus().getElem(i).getDestinatie() == z2)
				if (c.getRepoBus().getElem(i).getData() == date)
				{
					if (c.getRepoBus().getElem(i).getNrLoc() <= 0)
					{
						std::cout << "nu mai exista locuri pentru cursa selectata" << std::endl;
						return 0;
					}
					searched_bus = c.getRepoBus().getElem(i);
					std::cout << "pretul biletului : " << c.getRepoBus().getElem(i).getPlecare().getPret() << " lei " << std::endl;
					FOUND = 1;
					c.getRepoBus().getElem(i).setNrLoc(c.getRepoBus().getElem(i).getNrLoc() - 1);
				}

	if (!FOUND)
	{
		std::cout << "biletul cautat nu exista" << std::endl;
		return 0;
	}

	// modificam in lista bilete de la useri
	b[POS_ID_WANTED].push_back(searched_bus);

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

	std::ofstream fo2("listabus.txt");
	// se incarca datele noi in fisier
	for (int i = 0; i < c.getRepoBus().getDim(); i++)
	{
		bus b= c.getRepoBus().getElem(i);
		fo2 << b;
		if (i < c.getRepoBus().getDim() - 1)
			fo2 << std::endl;
	}

	std::cout << "bilet cumparat!" << std::endl;
	return FOUND;
}

void initiate_previous(std::vector <int>& previous_node, int dim)
{
	for (int i = 0; i < dim; i++)
		previous_node.push_back(-1);
}

void initiate_s(int& s, zona & plecare, std::vector <std::string> node_set)
{
	for (int i = 0; i < node_set.size(); i++)
		if (node_set[i] == plecare.getDenumire())
		{
			s = i;
			return;
		}
}

void set_node_set(std::vector <std::string> & node_set)
{
	std::ifstream fi("listabus.txt");
	while (!fi.eof())
	{
		bus b;
		fi >> b;
		bool FOUND1 = 0;										// verificam sa nu apara in multime
		bool FOUND2 = 0;
		for (int i = 0; i < node_set.size(); i++)
		{
			if (node_set[i] == b.getDestinatie().getDenumire())
				FOUND1 = 1;

			if (node_set[i] == b.getPlecare().getDenumire())
				FOUND2 = 1;		
		}
		if (!FOUND2)
			node_set.push_back(b.getPlecare().getDenumire());
		if (!FOUND1)
			node_set.push_back(b.getDestinatie().getDenumire());
	}
}

void set_adjacency_list(std::vector<int> v[100], std::vector <std::string> node_set)
{
	std::ifstream fi("listabus.txt");
	while (!fi.eof())
	{
		bus b;
		fi >> b;
		int ind_plecare = -1, ind_destinatie = -1;
		for (int i = 0; i < node_set.size() && (ind_plecare == -1 || ind_destinatie == -1); i++)
		{
			if (node_set[i] == b.getPlecare().getDenumire())
				ind_plecare = i;
			if (node_set[i] == b.getDestinatie().getDenumire())
				ind_destinatie = i;
		}
		v[ind_plecare].push_back(ind_destinatie);
	}
}

//vector <int> v[100];   //Vector for maintaining adjacency list explained above
//int level[100]; //To determine the level of each node
//bool vis[100]; //Mark the node if visited 

void bfs(std::vector<int> v[100], int level[100], bool vis[100], int s, std::vector <int> & previous_node)
{
	std::queue <int> q;
	q.push(s);
	level[s] = 0;  //Setting the level of the source node as 0
	vis[s] = true;
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		for (unsigned int i = 0; i < v[p].size(); i++)
		{
			if (vis[v[p][i]] == false)
			{
				//Setting the level of each node with an increment in the level of parent node
				previous_node[v[p][i]] = p;
				level[v[p][i]] = level[p] + 1;
				q.push(v[p][i]);
				vis[v[p][i]] = true;
			}
		}
	}
}

void afis(int s2, std::vector <int> previous_node, std::vector <std::string> node_set)
{
	if (s2 != 0 && previous_node[s2] != -1)
	{
		afis(previous_node[s2], previous_node, node_set);
		std::cout << node_set[previous_node[s2]] << "-" << node_set[s2] << " ";
	}
}

void ui::get_fastest_route(std::string id_wanted, zona& z, zona& z2, std::string date)
{
	std::vector<int> v[100];
	int level[100] = { 0 };
	bool vis[100] = { 0 };
	int s = 0;
	int s2 = 0;
	
	std::vector <std::string> node_set;				// multime cu numele tuturor zonelor
	set_node_set(node_set);							// initializam multimea
	
	std::vector <int> previous_node;				// multime cu vector de tati (cu indici) pt fiecare nod cand scoatem cea mai rapida ruta
	set_adjacency_list(v, node_set);			

	initiate_s(s, z, node_set);						// initializam nodul de unde pornim bfs

	initiate_s(s2, z2, node_set);						// initializam nodul unde trebuie sa ajungem

	int dim = node_set.size();
	initiate_previous(previous_node, dim);			// initializam vectorul de tati

	bfs(v, level, vis, s, previous_node);			// bfs care da distanta 

	int min = 1000000;								// se ia nivelul minim
	for (int i = 0; i < node_set.size(); i++)
		if (level[i] < min && level[i]>0)
 			min = level[i];

	/*while (s2 != 0 && previous_node[s2]!=-1)
	{
		std::cout << node_set[previous_node[s2]] << "-" << node_set[s2] << " ";
		s2 = previous_node[s2];
	}*/
	afis(s2, previous_node, node_set);
}

bool ui::logare(std::string &iduser, std::string &parolauser)
{
	std::cout << "id : ";
	std::cin >> iduser;
	std::cout << "parola : ";
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
