#include"Department.h"
#include"Employee.h"
#include"Person.h"

#include<iostream>

using namespace std;

Department::Department(int num, string nm, Employee* mgr) :
	number{ num }, name{ nm }, manager{ mgr }
{
}

int Department::getNumber()
{
	return number;
}

string Department::getName()
{
	return name;
}

Employee* Department::getManager()
{
	return manager;
}

const string Department::toString()
{
	stringstream ss;
	ss << "Department Number: " << number << endl;
	ss << "Department Name: " << name << endl;
	ss << "Manager Social Security: " << manager->getSocialSecurityNumber() << endl;
	return ss.str();
}

Department::~Department()
{
}