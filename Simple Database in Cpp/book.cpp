#include <iostream>
#include "employee.h"
using namespace std;

Employee::Employee()
{
	id_number = 0;
	salary = 0;
	year_started = 0;
}
Employee::Employee(std::string new_name, int new_id, std::string new_address, double new_salary, int new_years_worked)
{
	name = new_name;
	id_number = new_id;
	address = new_address;
	salary = new_salary;
	year_started = new_years_worked;
}
void Employee::output(ostream& outs)
{
	if(outs == cout)
	{
		outs << "Name: " << name << endl;
		outs << "ID number: " << id_number << endl;
		outs << "Address: " << address << endl;
		outs << "Salary: " << salary << endl;
		outs << "Years worked at company: " << year_started << endl;  
	}
	else{
		outs << name << endl;
		outs << id_number << endl;
		outs << address << endl;
		outs << salary << endl;
		outs << year_started << endl;
	}
}
void Employee::input(istream& ins)
{
		if (ins == cin)
        {
                if(ins.peek() == '\n')ins.ignore();
                cout << "Name: ";
                getline(ins,name);
                cout << "Enter Id Number ";
                ins >> id_number;
                cout << "Enter address: ";
                if(ins.peek() == '\n')ins.ignore();
                getline(ins,address);
                cout << "Enter salary: ";
                ins >> salary;
                cout << "Enter the number of years the employee has worked for the company: ";
                ins >> year_started;
        }
        else{
        		if(ins.peek() == '\n')ins.ignore();
                getline(ins,name);
                if(ins.peek() == '\n')ins.ignore();
                ins >> id_number;
                if(ins.peek() == '\n')ins.ignore();
                getline(ins,address);
                ins >> salary;
                ins >> year_started;
        }

}
ostream& operator <<(ostream& outs, Employee& tmp)
{
	tmp.output(outs);
	return outs;
}
istream& operator >>(istream& ins, Employee& tmp)
{
	tmp.input(ins);
	return ins;
}
