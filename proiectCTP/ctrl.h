#pragma once
#include "zona.h"
#include "repo.h"
#include "bus.h"
#include "user.h"
#include <iostream>

//using namespace std;

class ctrl
{
protected:
	repo<bus> rb;
	/*repo<zona> rz;
	repo<user> ru;*/
public:
	ctrl();
	/*ctrl(repo<bus> rb2);*/
	ctrl(const ctrl& c);
	~ctrl();
	ctrl& operator=(const ctrl& c);
	repo<bus> getRepoBus();
	/*repo<user> getRepoUser();*/
	/*void afis();*/	// chestia asta nu se face in CTRL
	//void logare(string idUser);
};

