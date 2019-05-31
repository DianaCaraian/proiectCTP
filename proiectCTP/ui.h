#pragma once
#include "ctrl.h"

class ui
{
protected:
	ctrl c;
public:
	ui();
	/*ui(ctrl c2);*/
	ui(const ui& u);
	~ui();
	ui& operator=(const ui& u);
	ctrl& getCtrl();
	void afisZone();
	void logare(std::string &iduser, std::string &parolauser);
};

