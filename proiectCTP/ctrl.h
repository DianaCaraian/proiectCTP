#pragma once
#include "repo.h"

class ctrl
{
protected:
	repo rb;
public:
	ctrl();
	ctrl(const ctrl& c);
	~ctrl();
	ctrl& operator=(const ctrl& c);
	repo& getRepoBus();

};