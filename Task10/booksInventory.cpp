#include <iostream>
#include <string>
const int max_books = 15;
using namespace std;
struct Books
{
	int bookId;
	string title;
	string author;
	string genere;
	float price;
};
void addBooks(Books inventory[], int &count)
{
	if (count < max_books)
	{
		cout << "enter the BookId : ";
		cin >> inventory[count].bookId;
		cout << "enter the title : ";
		cin >> inventory[count].title;
		cout << "enter the author name : ";
		cin >> inventory[count].author;
		cout << "enter the genere : ";
		cin >> inventory[count].genere;
		cout << "enter the price of the book : ";
		cin >> inventory[count].price;
		count++;
	}
	else
	{
		cout << "the inventory is full" << endl;
	}
}
void displayBookInfo(const Books inventory[], int id, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (inventory[i].bookId == id)
		{
			cout << "Book ID : " << inventory[i].bookId << " Title : " << inventory[i].title << " Author : " << inventory[i].author << " Genere : " << inventory[i].genere << " Price : " << inventory[i].price << endl;
			return;
		}
	}
	cout << "invalid id or book not found ! try again" << endl;
}
void calculateInventoryValue(const Books inventory[], int count)
{
	int finalValue;
	for (int i = 0; i < count; i++)
	{
		finalValue += inventory[i].price;
	}
	cout << "the total value of the books in the inventory is : " << finalValue << endl;
}
void displayAllBooks(const Books inventory[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "Book ID : " << inventory[i].bookId << " Title : " << inventory[i].title << " Author : " << inventory[i].author << " Genere : " << inventory[i].genere << " Price : " << inventory[i].price << endl;
	}
}
int main()
{
	Books inventory[max_books];
	int count = 0;
	int choice;
	while (true)
	{
		cout << "1. Add a book" << endl;
		cout << "2.Search book by ID" << endl;
		cout << "3.Calculate total Inventory Value" << endl;
		cout << "4.Display All books Information" << endl;
		cout << "5.Exit" << endl;
		cout << endl;
		cout << "enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addBooks(inventory, count);
			break;
		case 2:
		{
			cout << "enter the id to search : ";
			int id;
			cin >> id;
			displayBookInfo(inventory, id, count);
		}
		break;
		case 3:
			calculateInventoryValue(inventory, count);
			break;
		case 4:
			displayAllBooks(inventory, count);
			break;
		case 5:
			cout << "exiting!!!" << endl;
			return 0;
			break;
		default:
			cout << "Invalid Choice try again";
			break;
		}
	}
	return 0;
}
