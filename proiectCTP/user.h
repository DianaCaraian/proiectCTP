#include "zona.h"
#include <vector>

class user
{
protected:
	std::string id, passw;
	std::vector<zona> bilete;
public:
	user();
	user(const user& u);
	~user();
	user& operator=(const user& u);
	int operator==(const user u);
	friend std::istream& operator>>(std::istream& is, user& u);
	std::string getId();
	std::string getPassw();
	zona getBilet(int poz);
	int getDimBilete();
	void setId(std::string id);
	void setPassw(std::string passw);
	void setBilet(int poz, zona z);
	

};