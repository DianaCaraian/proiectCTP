#pragma once
#include "ui.h"
#include <queue>

using namespace std;

// constructor fara parametrii
ui::ui()
{
	//nimic
}

// construcotr de copiere
ui::ui(const ui& u)
{
	this->c = u.c;
}

// destructorul
ui::~ui()
{
	//nimic
}

// suprascrierea operatorului "="
ui& ui::operator=(const ui& u)
{
	this->c = u.c;
	return *this;
}

// functie care returneaza intreg controller-ul
ctrl& ui::getCtrl()
{
	return this->c;
}

// functie pentru afisarea vectorului de autobuze de tip "bus"
void ui::print_bus()
{
	c.getRepoBus().loadfile("listabus.txt");
	for (int i = 0; i < c.getRepoBus().getDim(); i++)
	{
		bus b = c.getRepoBus().getElem(i);
		cout << b << endl;
	}
}

/*
DESC: functie care afiseaza istoricul de bilete cumparate pentru un utilizator dat ca parametru
IN: id_wanted - id-ul utilizatorului cautat
OUT: -
*/
void ui::show_tickets(string id_wanted)
{
	ifstream fi("listabilete.txt");
	bool FOUND = 0;
	while (!fi.eof() && !FOUND)            // se parcurge fisierul cu istoricul toturor utilizatorilor
	{
		string id;
		int no_tickets;
		bus b;
		fi >> id >> no_tickets;            // se citesc din fisier numele si numarul de bilete cumparate
		if (id == id_wanted)
			FOUND = 1;
		for (int i = 1; i <= no_tickets; i++)
		{
			fi >> b;
			if (FOUND == 1)
				cout << b << endl;                  // se afiseaza fiecare autobuz de la acel utilizator
		}
	}
	fi.close();
}


/*
DESC: functie pentru cumpararea unui bilet si se returneaza o valoare de tip bool daca ruta dorita exista.
	  se actualizeaza istoricul de bilete cumparate al utilizatorului.
IN: id_wanted-> id-ul utilizatorului, z1-> zona de pelecare, z2-> zona de destinatie, date- data dorita
OUT: FOUND-> valoare de tip bool
*/
bool ui::buy_tickets(string id_wanted, zona& z1, zona& z2, string date)
{
	// se descarca fisierul cu lista bilete
	vector <string> id;
	vector<bus> b[100];	 // matrice
	ifstream fi("listabilete.txt");
	int nr_id = 0;
	int POS_ID_WANTED;
	int pos = 0;
	while (!fi.eof())
	{
		string new_id;
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

	bool FOUND = 0;
	bus searched_bus;
	for (int i = 0; i < c.getRepoBus().getDim() && !FOUND; i++)
		if (c.getRepoBus().getElem(i).getPlecare() == z1)
			if (c.getRepoBus().getElem(i).getDestinatie() == z2)
				if (c.getRepoBus().getElem(i).getData() == date)
				{
					if (c.getRepoBus().getElem(i).getNrLoc() <= 0)
					{
						cout << "nu mai exista locuri pentru cursa selectata" << endl;
						return 0;
					}
					searched_bus = c.getRepoBus().getElem(i);
					cout << "pretul unui bilet : " << c.getRepoBus().getElem(i).getPlecare().getPret() << " lei " << endl;
					FOUND = 1;
					c.getRepoBus().getElem(i).setNrLoc(c.getRepoBus().getElem(i).getNrLoc() - 1);
				}

	if (!FOUND)
	{
		cout << "biletul cautat nu exista" << endl;
		return 0;
	}

	b[POS_ID_WANTED].push_back(searched_bus);            // modificam in lista bilete de la useri

	ofstream fo("listabilete.txt");

	for (int i = 0; i < nr_id; i++)                       // se incarca datele noi in fisier
	{
		fo << id[i] << " " << b[i].size() << endl;
		for (int j = 0; (unsigned)j < b[i].size(); j++)
		{
			fo << b[i][j];
			if ((unsigned)j < b[i].size() - 1 || i < nr_id - 1)					// se evita aparitia ultimului endl
				fo << endl;							// rezolva bugul pentru cumparari multiple, care apare din cauza fi.eof()
		}
	}

	ofstream fo2("listabus.txt");

	for (int i = 0; i < c.getRepoBus().getDim(); i++)     // se incarca datele noi in fisier
	{
		bus b = c.getRepoBus().getElem(i);
		fo2 << b;
		if (i < c.getRepoBus().getDim() - 1)
			fo2 << endl;
	}

	cout << "bilet cumparat!" << endl;
	return FOUND;
}

/*
DESC: functie care initializeaza vectorul de tati cu -1
IN: dim - dimensiunea vectorului de tati
OUT: previous_node[] - vector de tati
*/
void initiate_previous(vector <int>& previous_node, int dim)
{
	for (int i = 0; i < dim; i++)
		previous_node.push_back(-1);
}


/*
DESC: funtie care cauta indicele zonei "plecare" in multime de zone "node_set" si il returneaza (prin s)
IN: plecare ( de tip zona ), node_set - multimea de zone
OUT: s- indicele corespunzator lui plecare in multimea node_set
*/
void initiate_s(int& s, zona& plecare, vector <string> node_set)
{
	for (int i = 0; (unsigned)i < node_set.size(); i++)
		if (node_set[i] == plecare.getDenumire())
		{
			s = i;
			return;
		}
}


/*
DESC: initializeaza node_set cu date din fisierul "listabus.txt" si pune in node_set fiecare locatie o singura data
IN: -
OUT: node_set[]
*/

// node_set[] - vector care stocheaza o multime cu numele tuturor destinatiilor
void set_node_set(vector <string>& node_set)
{
	ifstream fi("listabus.txt");
	while (!fi.eof())
	{
		bus b;
		fi >> b;
		bool FOUND1 = 0;										// verificam sa nu apara in multime
		bool FOUND2 = 0;
		for (int i = 0; (unsigned)i < node_set.size(); i++)
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

/*
DESC: functie care creeaza o lista de adiacenta
IN: node_set[] - multime locatii
OUT: v[][] - lista de adiacenta, v[i]= {a, b, c} inseamna ca din i pot ajunge in a, b, sau c
*/
void set_adjacency_list(vector<int> v[100], vector <string> node_set)
{
	ifstream fi("listabus.txt");
	while (!fi.eof())
	{
		bus b;
		fi >> b;
		int ind_plecare = -1, ind_destinatie = -1;
		for (int i = 0; (unsigned)i < node_set.size() && (ind_plecare == -1 || ind_destinatie == -1); i++)
		{
			if (node_set[i] == b.getPlecare().getDenumire())
				ind_plecare = i;
			if (node_set[i] == b.getDestinatie().getDenumire())
				ind_destinatie = i;
		}
		v[ind_plecare].push_back(ind_destinatie);

	}
}


/*
DESC: functie pentru implementarea algoritmului BFS pentru rezolvarea problemei de tip "find the shortest path"
IN: v[][], s, previous_node[]
OUT: level[], vis[]
*/

// vector <int> v[100] -> lista de adiacenta
// int level[100] -> determina nivelul fiecarui nod 
// bool vis[100] -> marcheaza nodurile vizitate
// s - nodul de inceput al bsf-ului (nodul radacina)
// level[] - vector de distanta (pentru bfs) - stocheaza distanta de la nodul de start (s) la nodul i = 1,n
// vis[] - vector care marcheaza nodurile vizitate (1- vizitat , 0- altfel)
// previous_node[] - vector de tati cu radacina s
// v[][] - lista de adiacenta

void bfs(vector<int> v[100], int level[100], bool vis[100], int s, vector <int>& previous_node)
{
	queue <int> q;
	q.push(s);
	//level[s] = 0;  //Setting the level of the source node as 0
	vis[s] = true;
	while (!q.empty())
	{
		int p = q.front();               // luam primul element din coada
		q.pop();
		for (unsigned int i = 0; i < v[p].size(); i++)
		{
			if (vis[v[p][i]] == false)
			{
				// setam nivelul fiecarui nod si crestem nivelul nodului parinte
				previous_node[v[p][i]] = p;
				//level[v[p][i]] = level[p] + 1;
				q.push(v[p][i]);
				vis[v[p][i]] = true;
			}
		}
	}
}

/*
DESC: functie de afisare recursiva pentru distanta de la nodul 1 la nodul 2
IN: s2 - nodul destinatie, previous_node[] - vector de tati, node_set - multimea de noduri
OUT: mesaj
*/
void afis(int s2, vector <int> previous_node, vector <string> node_set)
{
	if (s2 != 0 && previous_node[s2] != -1)
	{
		afis(previous_node[s2], previous_node, node_set);
		cout << node_set[previous_node[s2]] << "-" << node_set[s2] << " ";
	}
}

/*
DESC: functie care afiseaza cea mai scurta ruta de la zona z la zona z2
IN: id - id client, z - zona plecare, z2 - zona destinatie
OUT: mesaj cu cea mai scurta ruta de la z la z2
*/

// z - zona de plecare
// z2 - zona de destinatie
void ui::get_fastest_route(string id_wanted, zona& z, zona& z2)
{
	vector<int> v[100];
	int level[100] = { 0 };
	bool vis[100] = { 0 };
	int s = 0;               // s- indicele corespunzator lui z
	int s2 = 0;              // s2- indicele corespunzator lui z2

	vector <string> node_set;				// multime cu numele tuturor zonelor
	set_node_set(node_set);							// initializam multimea

	vector <int> previous_node;				// multime cu vector de tati (cu indici) pt fiecare nod cand scoatem cea mai rapida ruta
	set_adjacency_list(v, node_set);

	initiate_s(s, z, node_set);						// initializam nodul de unde pornim bfs

	initiate_s(s2, z2, node_set);						// initializam nodul unde trebuie sa ajungem

	int dim = node_set.size();
	initiate_previous(previous_node, dim);			// initializam vectorul de tati

	bfs(v, level, vis, s, previous_node);			// bfs care da distanta 

	/*
	int min = 1000000;								// se ia nivelul minim
	for (int i = 0; (unsigned)i < node_set.size(); i++)           // calculam distanta de la z la z2
		if (level[i] < min && level[i]>0)
			min = level[i];
	*/
	afis(s2, previous_node, node_set);
}


/*
DESC: functie care verifica daca id-ul si parola exista in fisier
IN: iduser, parolauser-> variabile tip string
OUT: GASIT-> variabila de tip bool
*/
bool ui::logare(string& iduser, string& parolauser)
{
	cout << "id : ";
	cin >> iduser;
	cout << "parola : ";
	cin >> parolauser;
	bool GASIT = false;
	ifstream fi("listaid.txt");
	while (!fi.eof() && GASIT == 0)
	{
		string idfisier, parolafis;
		fi >> idfisier >> parolafis;
		if (iduser == idfisier && parolauser == parolafis)
			GASIT = true;
	}

	return GASIT;
}

/*
DESC: functie care citeste variabilele z1, z2 si data de la tastaura
IN: z1-> zona de placare, z2-> zona de destinatie, data-> data dorita
OUT: z1, z2 si data citite
*/
void ui::read_data_buy(zona& z1, zona& z2, string& date)
{
	cout << "dati zona de plecare : ";
	string nume_plecare, nume_destinatie;
	cin >> nume_plecare;
	zona read_z1 = zona(nume_plecare);
	z1 = read_z1;
	cout << "dati zona de destinatie : ";
	cin >> nume_destinatie;
	zona read_z2 = zona(nume_destinatie);
	z2 = read_z2;
	cin >> date;
}

/*
DESC: functie care citeste variabilele z1, z2 de la tastaura
IN: z1-> zona de placare, z2-> zona de destinatie
OUT: z1, z2-> variabile de tip zona
*/
void ui::read_data_route(zona& z1, zona& z2)
{
	cout << "dati zona de plecare : ";
	string nume_plecare, nume_destinatie;
	cin >> nume_plecare;
	zona read_z1 = zona(nume_plecare);
	z1 = read_z1;
	cout << "dati zona de destinatie : ";
	cin >> nume_destinatie;
	zona read_z2 = zona(nume_destinatie);
	z2 = read_z2;
	cout << endl;
}
