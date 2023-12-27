#include <iostream>
#include <string>
using namespace std;
const int maxProducts = 100;
union Product
{
	int productId;
	char name[50];
	double price;
	int quantity;
};
void addProduct(Product inventory[], int &count)
{
	if (count < maxProducts)
	{
		cout << "enter the ID of the product : ";
		cin >> inventory[count].productId;

		cout << "enter the Name of the product : ";
		cin >> inventory[count].name;

		cout << "enter the Price of the product : ";
		cin >> inventory[count].price;

		cout << "enter the Quatity of the product : ";
		cin >> inventory[count].quantity;
		count++;
	}
	else
		cout << "the inventory is full !!";
}
void displayProductInfo(Product inventory[], int id, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (inventory[i].productId == id)
		{
			cout << "Product ID : " << inventory[i].productId << " Product Name : " << inventory[i].name << " Price : " << inventory[i].price << " Quantity : " << inventory[i].quantity << endl;
		}
		else
			cout << "invalid ID or produt not found!!";
	}
}
void updateQuantity(Product inventory[], int id, int count)
{
	int newQuantity;
	for (int i = 0; i < count; i++)
	{
		if (inventory[i].productId == id)
		{
			cout << "enter the quantity to update : ";
			cin >> newQuantity;
			inventory[i].quantity += newQuantity;
			cout << "quantity updatedd succesfully" << endl;
			return;
		}
		else
			cout << "invalid ID or product not found";
	}
}
void displayAllProducts(Product inventory[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "Product ID : " << inventory[i].productId << " Product Name : " << inventory[i].name << " Price : " << inventory[i].price << " Quantity : " << inventory[i].quantity << endl;
	}
}

int main()
{
	int count = 0;
	Product inventory[maxProducts];
	int choice;
	while (true)
	{
		cout << "1.Add a product to the Inventory" << endl;
		cout << "2.Search a product by ID" << endl;
		cout << "3.update the quantity of the product" << endl;
		cout << "4.dispaly all the products in the inventory" << endl;
		cout << "5.Exit" << endl;
		cout << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addProduct(inventory, count);
			break;
		case 2:
			cout << "enter the ID to search : ";
			int id;
			cin >> id;
			displayProductInfo(inventory, id, count);
			break;
		case 3:
			cout << "enter the ID to update quantity : ";
			int pid;
			cin >> pid;
			updateQuantity(inventory, id, count);
			break;
		case 4:
			displayAllProducts(inventory, count);
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "invalid choice try again!!" << endl;
			break;
		}
	}
	return 0;
}
