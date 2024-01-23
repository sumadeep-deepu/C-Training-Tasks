#include <iostream>
using namespace std;
struct Node
{
	Node *prev;
	int data;
	Node *next;
};
void insertNode(Node *&head)
{
	int value;
	cout << "enetr the value to insert : ";
	cin >> value;
	Node *newNode = new Node;
	newNode->prev = nullptr;
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
		newNode->prev = currentNode;
	}
	cout << "one node is inserted at end of the list " << endl;
}
void displayListForward(Node *&head)
{
	if (!head)
	{
		cout << "the list is empty" << endl;
		return;
	}
	Node *currentNode = head;
	cout << "the elements are displayed in the forward manner : " << endl;
	while (currentNode)
	{
		cout << currentNode->data << "\t";
		currentNode = currentNode->next;
	}
	cout << endl;
}
void displayListBackward(Node *&head)
{
	if (!head)
	{
		cout << "the list is empty" << endl;
		return;
	}
	Node *currentNode = head;
	cout << "the elements are displayed in the backward manner : " << endl;
	while (currentNode->next)
	{
		currentNode = currentNode->next;
	}
	while (currentNode)
	{
		cout << currentNode->data << endl;
		currentNode = currentNode->prev;
	}
	cout << endl;
}
void searchValue(Node *&head)
{
	if (!head)
	{
		cout << "the list is empty" << endl;
		return;
	}
	int value;
	cout << "enter a value to search : ";
	cin >> value;
	Node *currentNode = head;
	while (currentNode)
	{
		if (currentNode->data == value)
		{
			cout << "the value " << value << " is present in the list" << endl;
			return;
		}
		currentNode = currentNode->next;
	}
	cout << "the value " << value << " is not present in the list";
}
void deleteNode(Node *&head)
{
	if (!head)
	{
		cout << "The List is Empty!!!" << endl;
		return;
	}

	int value;
	cout << "Enter Value to delete: ";
	cin >> value;

	Node *currentNode = head;

	while (currentNode && currentNode->data != value)
	{
		currentNode = currentNode->next;
	}

	if (currentNode)
	{
		if (currentNode->prev)
		{
			currentNode->prev->next = currentNode->next;
		}
		else
		{
			head = currentNode->next;
		}

		if (currentNode->next)
		{
			currentNode->next->prev = currentNode->prev;
		}

		delete currentNode;
		cout << "The node with Value: " << value << " is deleted" << endl;
	}
	else
	{
		cout << "the  Value is not present in the list!!!" << endl;
	}
}
int main()
{
	Node *head = nullptr;
	int choice;
	while (true)
	{
		cout << "1.Add A Value To List" << endl
			 << "2.Display From Forward" << endl
			 << "3.Display From Backward" << endl
			 << "4.Search a Value" << endl
			 << "5.Delete a Node" << endl
			 << "6.Exit" << endl;
		cout << "Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			insertNode(head);
			break;
		case 2:
			displayListForward(head);
			break;
		case 3:
			displayListBackward(head);
			break;
		case 4:
			searchValue(head);
			break;
		case 5:
			deleteNode(head);
			break;
		case 6:
			cout << "exiting the program!!!" << endl;
			return 0;
		default:
			cout << "Invalid Choice!!!" << endl;
		}
	}
	return 0;
}
