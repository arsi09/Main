#include<iostream>
#include<string>
#include<sstream>
#include "Person.h"

using namespace std;

#ifndef EMPLOYEE_H

#define EMPLOYEE_H



class Employee : public Person  
{
public:
	Employee(string ssn, string fn, string ln, string add, char sx, double sal, int depNo);
	double getSalary();
	int getDepartmentNo();
	string toString();
	~Employee();
	bool operator==(Employee);
	
private:
	double salary;
	int departmentNo;
	

};

#endif // EMPLOYEE_H
