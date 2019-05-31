#pragma once
#include "zona.h"
#include "repo.h"
#include "bus.h"
#include "user.h"
#include <iostream>


class ctrl
{
protected:
	repo<bus> rb;
public:
	ctrl();
	ctrl(const ctrl& c);
	~ctrl();
	ctrl& operator=(const ctrl& c);
	repo<bus> getRepoBus();
	
};

