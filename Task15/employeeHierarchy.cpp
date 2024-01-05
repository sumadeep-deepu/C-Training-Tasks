#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
	string name;
	int empId;
	double salary;

public:
	Employee(string name, int empId, double salary)
	{
		this->name = name;
		this->empId = empId;
		this->salary = salary;
	}

	void displayInfo() const
	{
		cout << "Name : " << name << "\tEmployee Id : " << empId << "\tSalary : " << salary;
	}
};
class Manager : public Employee
{
private:
	int noOfProjects;

public:
	Manager(string name, int empId, double salary, int projects) : Employee(name, empId, salary), noOfProjects(projects) {}

	void displayInfo() const
	{
		Employee::displayInfo();
		cout << "\tNumber Of Projects: " << noOfProjects << endl;
	}
};
class TeamLead : public Employee
{
private:
	string projectName;

public:
	TeamLead(string name, int empId, double salary, string projectName) : Employee(name, empId, salary), projectName(projectName) {}
	void displayInfo() const
	{
		Employee::displayInfo();
		cout << "\tProject Name: " << projectName << endl;
	}
};
class Developer : public Employee
{
private:
	string domain;

public:
	Developer(string name, int empId, double salary, string domain) : Employee(name, empId, salary), domain(domain) {}
	void displayInfo() const
	{
		Employee::displayInfo();
		cout << "\t Domain : " << domain << endl;
	}
};
int main()
{
	Manager m1("ube", 101, 220000, 4);
	TeamLead t1("charan", 102, 50000, "KMB");
	Developer d1("sumadeep", 103, 30000, "C++");

	m1.displayInfo();
	t1.displayInfo();
	d1.displayInfo();
	return 0;
}
