#pragma once
#include "c_Student.h"
#include <fstream>
#include <string>
#include <iostream>
struct Node
{
	c_Student* val;
	Node* next;
};
class c_Group
{
private:
	Node* head;
	unsigned int size;
public:
	c_Group();
	void addToList(c_Student& student);
	void showList();
	void saveToFile();
	void loadFromFile();

	~c_Group()
	{
		delete head;
	}
};

