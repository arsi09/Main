#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Employee.h"
#include "Department.h"
#include"Person.h"

/*STUDENT PROVIDE THE NECESSARY LIBRARIES*/

using namespace std;

vector<Employee*> employeeList;
vector<Department*> departmentList;

void readEmployeeData(string filePath);   
void readDepartmentData(string filePath);  
void displayEmployeeData();     //already implemented for you
void displayDepartmentData();  //already implemented for you
Employee* getEmployeeWithMaxSalary();  
void searchBySalary();  
double getDepartmentManagerSalary(int deptNumber);   
double getTotalDepartmentSalaries(string deptName);  
void releaseMemoryResources();  

int main()   //already implemented for you
{	

	readEmployeeData("EmployeesData.txt");
	displayEmployeeData();
	cout << endl << endl;

	cout << "Employee with Maximum Salary:\n";
	cout << getEmployeeWithMaxSalary()->toString() << endl;
	cout << endl << endl;	

	cout << "Search By Salary:\n";
	//You MUST use the overloaded operator in the Employee class
	searchBySalary();
	cout << endl << endl;

	readDepartmentData("DepartmentData.txt");
	displayDepartmentData();
	cout << endl << endl;

	cout << "Get Salary of Department's Manager:\n";	
	int deptNumber;
	cout << "Enter department number: ";
	cin >> deptNumber;
	cout << "\nManager's salary of department " << deptNumber << " = "
		<< fixed << setprecision(2) << "$" << getDepartmentManagerSalary(deptNumber);
	cout << endl << endl;

	cout << "Get Department Salaries:\n";
	string deptName;
	cout << "Enter department name: ";
	cin >> deptName;
	cout << "\nTotal salaries in department: " << deptName << " = "
		<< fixed<<setprecision(2) <<"$"<<getTotalDepartmentSalaries(deptName) << endl;
	
	releaseMemoryResources();
	cout << endl << endl;
	cout << "All memory resources have been released\n";
	return 0;
}

void readEmployeeData(string filePath)
{

	// read in the data from the file and store it in the employeeList vector
	ifstream file("EmployeesData.txt", ios::in);
	if (!file)
	{
		cout << "File not found\n";
		exit(EXIT_FAILURE);
	}
	
	string socialSecurityNumber;
	string firstName;
	string lastName;
	string address;
	char sex;
	double salary;
	int departmentNumber;

	while (file >> socialSecurityNumber >> firstName >> lastName >> address >> sex >> salary >> departmentNumber) // read in data from the file 
	{
		Employee* emp = new Employee { socialSecurityNumber, firstName, lastName, address, sex, salary, departmentNumber };
		employeeList.push_back(emp);

	}

}


void readDepartmentData(string filePath)
{
	// read in the data from the file and store it in the departmentList vector
	ifstream Dep("DepartmentData.txt", ios::in);
	if (!Dep)
	{
		cout << "File not found\n";
		exit(EXIT_FAILURE);
	}

	int departmentNumber;
	string departmentName;
	string managerSSNStr;

	while (Dep >> departmentNumber >> departmentName >> managerSSNStr) // read in data from the file   
	{
	
        Employee* manager = nullptr;
        for (Employee* emp : employeeList) {
        if (emp->getSocialSecurityNumber() == managerSSNStr) {
        manager = emp;
        break;
        }
        }
        Department* dept = new Department { departmentNumber, departmentName, manager };
        departmentList.push_back(dept);
		
	}

}

void displayEmployeeData()
{
	cout << "Employee Data: \n\n";
	cout <<left<< setw(13)<<"SSN"
		<< setw(10) << "F_Name"
		<< setw(10) << "L_Name"
		<< setw(25) << "Address"
		<< setw(5) << "Sex"
		<< setw(10) << "Salary"		
		<< setw(10) << "Dept. No"<<endl;
	cout << "---------------------------------------------------------------------------------\n";
	for (Employee* emp : employeeList)
	//for (size_t i{ 0 }; i < employeeList.size(); i++) //another way
	{
		cout << emp->toString() << endl;
		//cout << employeeList[i]->toString() << endl;  //another way
	}

}

void displayDepartmentData()
{
	cout << "Department Data: \n\n";
	cout << left << setw(7) << "Dept#"
		<< setw(20) << "Dept. Name"
		<< setw(20) << "Mgr SSN"<<endl;
	cout << "-------------------------------------\n";
	for (Department* dept : departmentList)		
	{
		cout << dept->toString() << endl;		
	}

}

Employee* getEmployeeWithMaxSalary()  
{
	Employee* maxSalary = employeeList[0];
	for (Employee* emp : employeeList)
	{
		if (emp->getSalary() > maxSalary->getSalary())
		{
			maxSalary = emp;
		}
	}
	return maxSalary;

}

void searchBySalary()
{
	double salary;
	cout << "Enter salary: ";
	cin >> salary;
	cout << "Employees with salary " << salary << " are: \n";

	for (Employee* emp : employeeList)
	{
		if (emp->getSalary() == salary)
		{
			cout << emp->toString() << endl;
		}
		else
		{
			cout << "No employee with salary " << salary << " found" << endl;
		}

	}
}


double getDepartmentManagerSalary(int deptNumber)
{
	
	for (Department* dept : departmentList)
	{
		if (dept->getNumber() == deptNumber)
		{
			return dept->getManager()->getSalary();
		}
	}
	return 0.0;
}
double getTotalDepartmentSalaries(string deptName)
{
	double totalSalaries{ 0.0 };
	for (Department* dept : departmentList)
	{
		if (dept->getName() == deptName)
		{
			for (Employee* emp : employeeList)
			{
				if (emp->getDepartmentNo() == dept->getNumber())
				{
					totalSalaries += emp->getSalary();
				}
			}
		}
	}
	return totalSalaries;

}

void releaseMemoryResources()
{
	for (Employee* emp : employeeList)
	{
		delete emp;
	}
	for (Department* dept : departmentList)
	{
		delete dept;
	}

}
