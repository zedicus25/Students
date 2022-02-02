#include <iostream>
#include "c_Group.h"
int main()
{
	c_Group* gr = new c_Group();
	
	gr->loadFromFile();
	gr->showList();
	delete gr;
}