#include "c_Group.h"

c_Group::c_Group()
{
	this->head = NULL;
	this->size = 0;
}

void c_Group::addToList(c_Student& student)
{
	Node* tmp = this->head;
	if (tmp == NULL) {
		tmp = new Node;
		tmp->val = new c_Student(student);
		tmp->next = nullptr;
		this->head = tmp;
	}
	else {
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = new Node;
		tmp->next->val = new c_Student(student);
		tmp->next->next = nullptr;
	}
	this->size++;
}

void c_Group::showList()
{
	Node* tmp = this->head;
	while (tmp != nullptr) {
		std::cout << tmp->val->info() << "\n";
		tmp = tmp->next;
	}
	delete tmp;
}

void c_Group::saveToFile()
{
	if (this->size == 0) {
		std::cout << "Empty \n";
		return;
	}

	std::ofstream out("Data.txt");
	if (out.is_open()) {
		Node* tmp = this->head;

		while (tmp != nullptr)
		{
			out << tmp->val->info() << "\n";
			tmp = tmp->next;
		}
		out.close();
		std::cout << "Done" << "\n";
	}
	else {
		std::cout << "Error" << "\n";
	}
}

void c_Group::loadFromFile()
{
	std::ifstream in("Data.txt");
	std::string str;
	if (in.is_open()) {
		while (!in.eof())
		{
			in >> str;
			if (str != "NULL")
			{
				int pos = 0;
				pos = str.find(':');
				std::string name = str.substr(0, pos);
				str.erase(0, pos + 1);
				c_Student* st = new c_Student(name);
				while ((pos = str.find(',')) != std::string::npos)
				{
					st->addMark(std::stoi(str.substr(0, pos)));
					str.erase(0, pos + 1);
				}
				this->addToList(*st);
				delete st;
				str = "NULL";
			}
		}
		std::cout << "Done\n";
	}
	else {
		std::cout << "Cannot read file" << "\n";
	}
	
}
