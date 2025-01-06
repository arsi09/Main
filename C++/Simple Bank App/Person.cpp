#include"Person.h"
#include<iostream>
#include<string>
#include<sstream>


using namespace std;


Person::Person(string& ssn, string& fn, string& ln, string& add, char& sx) :
socialSecurityNumber{ ssn }, firstName{ fn }, lastName{ ln }, address{ add }
{
	if (ssn.length() != 9)
	{
		cout << "Social Security number is not 9 charchters" << endl;
	}

};

string Person::getSocialSecurityNumber()
{
	return socialSecurityNumber;
}

string Person::getFirstName()
{
	return firstName;
}

string Person::getLastName()
{
	return lastName;
}

string Person::getAddress()
{
	return address;
}

char Person::getSex()
{
	return	sex;
}

string Person::toString()
{
	stringstream ss;
	ss << "Social Security Number "<< setw(10) << "First Name " << setw(10) << "Last Name " << setw(10) << "Address: " << setw(10) << "Sex:" << setw(10) << socialSecurityNumber << endl;
	ss << socialSecurityNumber  << setw(10) << firstName << setw(10) << lastName << setw(10) << address << setw(10) << sex << setw(10) << socialSecurityNumber << endl;
	
	
	return ss.str();
}



Person::~Person()
{
}