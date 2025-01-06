#include "Person.h"
#include"Employee.h"
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

Employee::Employee(string ssn, string fn, string ln, string add, char sx, double sal, int depNo) :
	Person{ ssn, fn, ln, add, sx }, salary{ sal }, departmentNo{ depNo }
{
	
}

double Employee::getSalary()
{
	return salary;
}

int Employee::getDepartmentNo()
{
	return departmentNo;
}

string Employee::toString()
{
	stringstream ss;
	
	ss << "Social Security Number: " << getSocialSecurityNumber() << endl;
	ss << "First Name: " << getFirstName() << endl;
	ss << "Last Name: " << getLastName() << endl;
	ss << "Address: " << getAddress() << endl;
	ss << "sex" << getSex() << endl;
	ss << "Salary: " << salary << endl;
	ss << "Department Number: " << departmentNo << endl;
	return ss.str();
}

bool Employee::operator==(Employee e)
{
	if (Employee::salary == e.salary)
	{
		return true;
	}
	
}

Employee::~Employee()
{
}
