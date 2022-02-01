#include "c_Student.h"

c_Student::c_Student()
{
	this->name = "None";
	this->marks = new int[0];
	this->size = 0;
}

c_Student::c_Student(std::string name)
{
	this->name = name;
	this->marks = new int[0];
	this->size = 0;
}

int c_Student::getAvagare()
{
	int result = 0;
	for (int i = 0; i < this->size; i++)
	{
		result += this->marks[i];
	}
	result = result / this->size;
	return result;	
}

void c_Student::addMark(int mark)
{
	int* tmp = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = this->marks[i];
	}

	delete[] this->marks;
	this->marks = new int[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		this->marks[i] = tmp[i];
	}
	this->marks[size] = mark;
	this->size++;
	delete[] tmp;
}

std::string c_Student::info()
{
	std::string res;
	res += this->getName();
	res += ":";
	for (int i = 0; i < this->size; i++)
	{
		res += std::to_string(this->marks[i]);
		res += ",";
	}
	return res;
}
