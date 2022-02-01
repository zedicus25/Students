#pragma once
#include <iostream>
#include <string>
class c_Student
{
private:
	std::string name;
	int* marks;
	int size;
public:
	c_Student();
	c_Student(std::string name);

	inline std::string getName() const{
		return this->name;
	}
	int getAvagare();
	void addMark(int mark);
	std::string info();
};

