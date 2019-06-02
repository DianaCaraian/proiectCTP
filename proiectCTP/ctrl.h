#pragma once
#include "zona.h"
#include "repo.h"
#include <iostream>


class ctrl
{
protected:
	repo rb;
public:
	ctrl();
	ctrl(const ctrl& c);
	~ctrl();
	ctrl& operator=(const ctrl& c);
	repo getRepoBus();
	
};

