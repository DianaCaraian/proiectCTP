#include <iostream>
#include "teste.h"
#include "bus.h"
#include "ctrl.h"
#include "repo.h"
#include "zona.h"
#include <assert.h>
#include <string>

using namespace std;

// functie pentru testarea functiilor din clasa "zona"
void testZona()
{
	zona z1 = zona();
	assert(z1.getDenumire() == "");
	assert(z1.getPret() == 0.0);
	zona z2 = zona("zona2", 3);
	assert(z2.getPret() == 3);
	zona z3 = zona("zona4", 5);
	assert(z3.getDenumire() == "zona4");
	assert(z3.getPret() == 5);
	zona z4 = zona(z3);
	assert(z4.getDenumire() == "zona4");
	assert(z4.getPret() == 5);
	zona z5 = zona(z4);
	assert(z5.getDenumire() == "zona4");
	assert(z5.getPret() == 5);
	z5.setDenumire("zona6");
	z5.setPret(10);
	assert(z5.getDenumire() == "zona6");
	assert(z5.getPret() == 10);
	assert(!(z5 == z3));
	assert(!(z5 == z1));

	cout << "teste zona" << endl;
}

// functie pentru testarea functiilor din clasa "bus"
void testBus()
{
	bus b1 = bus();
	assert(b1.getData() == "");
	assert(b1.getNrLoc() == 0);
	zona z1 = zona("floresti", 5);
	zona z2 = zona("centru", 7);
	bus b2 = bus(z1, z2, "12-07-2019", 10);
	assert(b2.getData() == "12-07-2019");
	assert(b2.getNrLoc() == 10);
	assert(b2.getDestinatie() == z1);
	assert(b2.getPlecare() == z2);
	bus b3 = bus(b2);
	assert(b3.getData() == "12-07-2019");
	assert(b3.getNrLoc() == 10);
	assert(b3.getDestinatie() == z1);
	assert(b3.getPlecare() == z2);
	bus b4 = b3;
	assert(b4.getData() == "12-07-2019");
	assert(b4.getNrLoc() == 10);
	assert(b4.getDestinatie() == z1);
	assert(b4.getPlecare() == z2);
	assert(b3 == b4);
	assert(!(b2 == b1));
	bus b6 = bus();
	b6.setData("12-06-2019");
	b6.setPlecare(z1);
	b6.setDestinatie(z2);
	b6.setNrLoc(12);
	assert(b6.getData() == "12-06-2019");
	assert(b6.getDestinatie() == z2);
	assert(b6.getPlecare() == z1);
	assert(b6.getNrLoc() == 12);

	cout << "teste autobuz" << endl;
}

// functie pentru testarea functiilor din clasa "repo"
void testRepo()
{
	zona z1 = zona("floresti", 5);
	zona z2 = zona("centru", 7);
	zona z3 = zona("marasti", 6);
	bus b1 = bus(z1, z2, "12-12-2019", 1);
	bus b2 = bus(z2, z3, "12-12-2019", 2);
	bus b3 = bus();

	repo r = repo();
	assert(r.getDim() == 0);
	repo r2 = repo(r);
	assert(r2.getDim() == 0);
	repo r3 = r;
	assert(r3.getDim() == 0);
	repo  rr = repo();
	assert(rr.getDim() == 0);
	repo  rr2 = repo(rr);
	assert(rr2.getDim() == 0);
	repo rr3 = rr;
	assert(rr3.getDim() == 0);
	cout << "teste repo" << endl;
}

// functie pentru testarea functiilor din clasa "user"
void testUser()
{
	user u1 = user();
	assert(u1.getId() == "");
	assert(u1.getPassw() == "");
	user u2 = user(u1);
	assert(u2.getId() == "");
	assert(u2.getPassw() == "");
	string a = "TestId";
	string b = "TestPass";
	zona c = zona("TestZona", 15);
	int n = 0;
	u2.setId(a);
	u2.setPassw(b);
	assert(u2.getId() == "TestId");
	assert(u2.getPassw() == "TestPass");
	assert(u2.getDimBilete() == 0);
	cout << "teste user" << endl;
}

// functie pentru apelarea tuturor testelor
void testFinal()
{
	testZona();
	testBus();
	testRepo();
	testUser();
}