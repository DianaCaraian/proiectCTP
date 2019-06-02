#pragma once
#include "ctrl.h"
//#include "bus.h"

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
	void show_tickets(std::string id_wanted);
	bool buy_tickets(std::string id_wanted,zona& z,zona& z2,std::string date);
	//std::vector<bus> get_cheapest_route();
	void get_fastest_route(std::string id_wanted, zona& z, zona& z2, std::string date);
	bool logare(std::string &iduser, std::string &parolauser);
	void read_data_4buy( zona& z1, zona& z2, std::string& date);
};

