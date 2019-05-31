#pragma once
#include "ctrl.h"
#include "bus.h"

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
	void show_tickets();
	void buy_tickets();
	std::vector<bus> give_fastest_route();
	std::vector<bus> give_cheapest_route();
	bool logare(std::string &iduser, std::string &parolauser);
};

