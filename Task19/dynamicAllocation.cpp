#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
	string name;
	int age;

public:
	Student() : name(""), age(0) {}
	Student(string name, int age) : name(name), age(age) {}
	string getName()
	{
		return name;
	}
	void display()
	{
		cout << "Name : " << name << "  Age : " << age << endl;
	}
};
class StudentList
{
private:
	Student *students;
	int noOfStudents;
	int count;

public:
	StudentList(int size) : noOfStudents(size), count(0)
	{
		students = new Student[size];
	}
	void addStudent()
	{
		if (count < noOfStudents)
		{
			string name;
			int age;
			cout << "enter student name : ";
			cin >> name;
			cout << "enter students age : ";
			cin >> age;
			Student st(name, age);
			students[count] = st;
			cout << "One student added to the list" << endl;
			count++;
		}
		else
		{
			cout << "reached maximum no of studnets" << endl;
		}
	}
	void displayStudents()
	{
		cout << "displaying all students : " << endl;
		for (int i = 0; i < count; i++)
		{
			students[i].display();
		}
	}
	void deleteStudent()
	{
		string name;
		cout << "enter the name to delete : ";
		cin >> name;
		for (int i = 0; i < count; i++)
		{
			if (students[i].getName() == name)
			{
				students[i].display();
				cout << " is deleted " << endl;
				for (int j = i; j < count - 1; j++)
				{
					students[j] = students[j + 1];
				}
				count--;
				return;
			}
		}
		cout << "no matching name found ! try again" << endl;
	}
	~StudentList()
	{
		delete students;
	}
};
int main()
{
	int noOfStudents;
	cout << "enter Maximum number of students : ";
	cin >> noOfStudents;
	StudentList list(noOfStudents);
	while (true)
	{
		int choice;
		cout << "1.Add student \n2.display all students\n3.delete a student by name\n4.exit" << endl;
		cout << "enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			list.addStudent();
			break;
		case 2:
			list.displayStudents();
			break;
		case 3:
			list.deleteStudent();
			break;
		case 4:
			cout << "exiting the program" << endl;
			return 0;
			break;
		default:
			cout << "invalid choice try again!!" << endl;
		}
	}
	return 0;
}
