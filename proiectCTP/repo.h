#pragma once
#include <vector>
#include <iostream>
#include <fstream>

template <class T>

class repo
{
protected:
	std::vector<T> v;
public:
	repo();
	repo(T v2[]);
	repo(const repo& r);
	~repo();
	repo<T>& operator=(const repo& r);
	T getElem(int poz);
	int getDim();
	void loadfile(std::string namefile);
};

template <class T>
void repo<T>::loadfile(std::string namefile)
{
	std::ifstream f(namefile);
	while (!f.eof())
	{
		T elem;
		f >> elem;
		this->v.push_back(elem);
	}
	f.close();
}

template <class T>
repo<T>::repo()
{
	//nimic
}

template <class T>
repo<T>::repo(T v2[])
{
	this->v = v2;
}

template <class T>
repo<T>::repo(const repo& r)
{
	this->v = r.v;
}

template <class T>
repo<T>::~repo()
{
	//nimic
}

template <class T>
repo<T>& repo<T>::operator=(const repo& r)
{
	this->v = r.v;
	return *this;
}

template <class T>
T repo<T>::getElem(int poz)
{
	return this->v[poz];
}

template <class T>
int repo<T>::getDim()
{
	return this->v.size();
}