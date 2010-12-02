#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "database.h"
using namespace std;

Database::Database()
{
	used = 0;
	capacity = 5;
	data = new Book[capacity];
}
Database::Database(const Database& other)
{
	used = other.used;
	capacity = other.capacity;
	data = new Book[capacity];
	copy(other.data,other.data+used,data);
}
Database::~Database()
{
	delete[]data; 
}
void Database::operator =(const Database& other)
{
	if(&other == this)
        {
                return;
        }
        delete[]data;
        capacity = other.capacity;
        used = other.used;
        data = new Book[capacity];
        copy(other.data,other.data+used,data);
}
void Database::make_bigger()
{
	Employee *tmp;
	tmp = new Book[capacity+5];
	copy(data, data+used,tmp);
	delete []data;
	data = tmp;
	capacity +=5;
}
void Database::search(std::string name)
{
	int num_found = 0;
	for(int i=0; i<used;i++)
	{
		if(data[i].get_name() == name)
		{
			cout << "Found Book!" << endl;
			data[i].output(cout);
			num_found+=1;
		}
	}
	if(num_found == 0)
	{
		cout << "No Book by that title" << endl;
	}
}
void Database::search_id(int id)
{
	int num_found = 0;
	for(int i=0; i<used;i++)
	{
		if(data[i].get_id_number() == id)
		{
			cout << "Book Found!" << endl;
			data[i].output(cout);
			num_found++;
		}
	}
	if(num_found == 0)
	{
		cout << "No book with that ID number!" << endl;
	}
}
void Database::add(const Book& emp)
{
	if(used >= capacity)
	{
		make_bigger();
	}
	data[used] = emp;
	used++;
}
void Database::display_all()
{
	for(int i=0;i<used;i++)
	{
		data[i].output(cout);
	}
}
void Database::remove(std::string name)
{
	for(int i=0; i < used; i++)
	{
		if(data[i].get_name() == name)
		{
			data[i] = data[used-1];
			used--;
		}
	}
}
void Database::save(std::ostream& outs)
{
	sort_name();
	for(int i=0; i<used; i++)
	{
		outs << data[i];
	}
}
void Database::load(std::istream& ins)
{
	Employee tmp;
	while(ins >> tmp)
	{
		if(used >= capacity)
		{
			make_bigger();
		}
		data[used] = tmp;
		used++;
	}
}
void Database::sort_title()
{
	bool done = false;
	Book tmp;
	while(!done)
	{
		done = true;
		for(int i=0;i<used-1;i++)
		{
			if(data[i].get_name() > data[i+1].get_name())
			{
				done = false;
				tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
			}	
		}	
	}	
}
void Database::sort_price()
{
	bool done = false;
	Book tmp;
	while(!done)
	{
		done = true;
		for(int i=0;i<used-1;i++)
		{
			if(data[i].get_price() < data[i+1].get_price())
			{
				done = false;
				tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
			}	
		}	
	}	
}
