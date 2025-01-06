#include<iostream>
#include<string>
#include<sstream>
#include "Person.h"
#include "Employee.h"

using namespace std;

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department
{
public:
	Department(int num, string nm, Employee* mgr);
	int getNumber();
	string getName();
	Employee* getManager();
	const string toString();
	~Department();

private:
	int number;
	string name;
	Employee* manager;
};

#endif // !DEPARTMENT_H
