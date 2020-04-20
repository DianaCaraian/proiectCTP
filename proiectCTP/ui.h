#pragma once
#include "ctrl.h"

class ui
{
protected:
	ctrl c;
public:
	ui();
	ui(const ui& u);
	~ui();

	ui& operator=(const ui& u);
	ctrl& getCtrl();

	void print_bus();
	void show_tickets(string id_wanted);
	bool buy_tickets(string id_wanted, zona& z, zona& z2, string date);
	void get_fastest_route(string id_wanted, zona& z, zona& z2);
	bool logare(string& iduser, string& parolauser);
	void read_data_buy(zona& z1, zona& z2, string& date);
	void read_data_route(zona& z1, zona& z2);
};
