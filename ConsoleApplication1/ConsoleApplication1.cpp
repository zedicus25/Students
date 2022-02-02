#include <iostream>
#include "c_Group.h"
using std::cout;
using std::cin;
int main()
{
	c_Group* gr = new c_Group();
	
	int userInput = -1;
	do
	{
		system("cls");
		cout << "1 - Add student to group\n";
		cout << "2 - Show group\n";
		cout << "3 - Save to file\n";
		cout << "4 - Load from file\n";
		cout << "0 - Exit\n";
		cin >> userInput;
		switch (userInput)
		{
		case 1:
		{
			system("cls");
			std::string name;
			cin.ignore();
			cout << "Enter name ";
			std::getline(cin, name);
			c_Student* st = new c_Student(name);
			int mark = 0;
			cout << "Enter 3 marks ";
			cin >> mark;
			st->addMark(mark);
			cin >> mark;
			st->addMark(mark);
			cin >> mark;
			st->addMark(mark);
			gr->addToList(*st);
			delete st;
			system("pause");
			break; 
		}
		case 2:
		{
			system("cls");
			gr->showList();
			system("pause");
			break; 
		}
		case 3:
			system("cls");
			gr->saveToFile();
			system("pause");
			break;
		case 4:
			system("cls");
			gr->loadFromFile();
			system("pause");
			break;
		case 0:
			break;

		}
	} while (userInput != 0);
	delete gr;
}