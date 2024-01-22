#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
void insertNode(Node *&head)
{
	int value;
	cout << "enter a value to insert : ";
	cin >> value;
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if (!head)
	{
		head = newNode;
	}
	else
	{
		Node *currentNode = head;
		while (currentNode->next)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	cout << "one node is inserted at end" << endl;
}
void displayElements(Node *&head)
{
	if (!head)
	{
		cout << "the list is empty!!" << endl;
		return;
	}
	else
	{
		Node *currentNode = head;
		cout << "the integers in the list are : ";
		while (currentNode)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << endl;
	}
}
void searchElements(Node *head)
{
	if (!head)
	{
		cout << "the list is empty" << endl;
		return;
	}
	else
	{
		int value;
		cout << "enter a value to search : ";
		cin >> value;
		Node *currentNode = head;
		while (currentNode)
		{
			if (currentNode->data == value)
			{
				cout << "the value " << value << "is present in the list" << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "the value " << value << " not present in the list" << endl;
	}
}
void deleteElement(Node *&head)
{
	if (!head)
	{
		cout << "The List is Empty!!" << endl;
		return;
	}
	int value;
	cout << "Enter Value to delete: ";
	cin >> value;
	Node *currentNode = head;
	Node *prev = nullptr;
	while (currentNode && currentNode->data != value)
	{
		prev = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode)
	{
		if (prev)
		{
			prev->next = currentNode->next;
		}
		else
		{
			head = currentNode->next;
		}
		delete currentNode;
		cout << "The node with Value: " << value << " is deleted" << endl;
	}
	else
	{
		cout << "No such Value present in list!!!" << endl;
	}
}

int main()
{
	Node *head = nullptr;
	int choice;
	while (true)
	{
		cout << "1.Insert a Value To List" << endl
			 << "2.Display elements " << endl
			 << "3.Search element in the list" << endl
			 << "4.Delete element from the list" << endl
			 << "5.Exit" << endl;
		cout << "Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			insertNode(head);
			break;
		case 2:
			displayElements(head);
			break;
		case 3:
			searchElements(head);
			break;
		case 4:
			deleteElement(head);
			break;
		case 5:
			cout << "exiting the program!!!" << endl;
			return 0;
		default:
			cout << "Invalid Choice!!" << endl;
		}
	}
	return 0;
}
