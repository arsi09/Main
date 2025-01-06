#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

#ifndef PERSON_H

#define PERSON_H


class Person
{
public:
	Person(string& ssn, string& fn, string& ln, string& add, char& sx);

	string getSocialSecurityNumber();

	string getFirstName();
	string getLastName();
	string getAddress();
	char getSex();
	~Person();
	virtual string toString();

private:
	string socialSecurityNumber;
	string firstName;
	string lastName;
	string address;
	char sex; // M or F

};




#endif // PERSON_H