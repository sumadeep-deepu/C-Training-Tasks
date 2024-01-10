#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
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
	Book(string title, string author, int year) : title(title)
	{
		if (!isValidAuthor(author))
		{
			throw invalid_argument("author should not contain speacial characters");
		}
		this->author = author;

		if (year < 0 || year > 2024)
		{
			throw year;
		}
		this->year = year;
	}
	bool isValidAuthor(string &author)
	{
		for (char ch : author)
		{
			if (!isalnum(ch) && ch != ' ' && ch != '-')
			{
				return false;
			}
		}
		return true;
	}
	void displayBookInfo()
	{
		cout << "Title  : " << title << " Author : " << author << " Year : " << year << endl;
	}
};
int main()
{
	try
	{

		Book b1;
		b1.displayBookInfo();
		Book b2("GTA", "RoddyRich", 2021);
		b2.displayBookInfo();
		Book b3("HOW", "#rad", 2001);
		b3.displayBookInfo();
	}
	catch (int e)
	{
		cerr << "year should not be negative and greater than current year" << endl;
	}
	catch (invalid_argument e)
	{
		cerr << "Error : " << e.what() << endl;
	}
	return 0;
}
