#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
	string title;
	string author;
	int year;

public:
	Book()
	{
		title = "";
		author = "";
		year = 0;
	}
	Book(string title, string author, int year)
	{
		this->title = title;
		this->author = author;
		this->year = year;
	}
	void displayBookInfo()
	{
		cout << "Title : " << title << " Author : " << author << " Year : " << year << endl;
	}
};
int main()
{
	Book book1;
	Book book2("grandTheft", "sumadeeep", 2002);
	book1.displayBookInfo();
	book2.displayBookInfo();
	return 0;
}
