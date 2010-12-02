#include <iostream>
#include <fstream>
#include <string>
#include "book.h"
#include "database.h"
using namespace std;

int menu();
int main()
{
	Database database;
	Book emp;
	string filename;
	cout << "Enter title of file (No file extension): ";
	getline(cin, filename);
	filename + ".txt";
	ifstream fin(filename.c_str());
	if(!fin.fail())
	{
		database.load(fin);
		fin.close();
		int choice;
		while(choice!=8)
		{
			choice = menu();
			switch (choice)
			{
				case 1:{
					cin >> emp;
					database.add(emp);
					break;
				}
				case 2:{
					system("cls");
					string name;
					cout << "Enter title of book to find: ";
					if(cin.peek() == '\n')cin.ignore();
					getline(cin,name);
					database.search(name);
					break;
				}
				case 3:{
					system ("cls");
					int id;
					cout << "Enter Book ID number: ";
					cin >> id;
					database.search_id(id);
					break;
				}
				case 4:{
					system("cls");
					cout << "All the books in the database!" << endl;
					database.display_all();
					break;
				}
				case 5:{
					system("cls");
					string name;
					cout << "Enter book that has been removed: ";
					if(cin.peek() == '\n')cin.ignore();
					getline(cin,name);
					database.remove(name);
					break;
				}
				case 6:{
					system("cls");
					database.sort_salary();
					cout << "Books sorted by price." << endl;
					database.display_all();
					break;
				}
				case 7:{
					system("cls");
					database.sort_name();
					cout << "Books sorted by authors name." << endl; 
					database.display_all();
					break;
				}
				case 8:{
					break;
				}
				default:{
					system("cls");
					cout << "Not a valid input!" << endl;
					break;
				}
			}
		}
		ofstream fout(filename.c_str());
		if(!fout.fail())
		{
			database.save(fout);
		}
		else{
			cout << "File could not open!" << endl;
		}
		fout.close();
		cout << "Thank you for using Jeorge's Database System!" << endl;
	}
	else{
		cout << "File does not exist, creating new file!" << endl;
		ofstream new_file(filename.c_str());
		new_file.close();
		main();
	}
	return 0;
}
int menu()
{
	int choice;
	cout << "1. Add new_books." << endl;
	cout << "2. Search for book by name." << endl;
	cout << "3. Searh for book by ID number." << endl;
	cout << "4. Display all current books." << endl;
	cout << "5. Remove book from database." << endl;
	cout << "6. Sort books by price. (Most expensive first)" << endl;
	cout << "7. Sort Books by Author's Name." << endl;
	cout << "8. Quit" << endl;
	cin >> choice;
	return choice;
}
