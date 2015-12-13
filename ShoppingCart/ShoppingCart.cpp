/************************
* Author: Baljot Singh
* ShoppingCart.cpp file for ShoppingCart class implementation
* Contains constructors and member function definitions
* of ShoppingCart.h
************************/

#include <iostream>
#include "ShoppingCart.h"
#include "Items.h"
#include "double_validation.h"

using namespace std;

class Items;

//Method to clear vector
void ShoppingCart::clearVector()
{
	cart.clear();
}
	 	
//function to add items to vector cart
void ShoppingCart:: addItem(Items shopCart)
{
	shopCart.getName();  //Getting name

	shopCart.getUnit();  //Getting name

	shopCart.getQuantity(); //Getting quantity

	shopCart.getPrice();    //Getting price

	cart.push_back(shopCart);  //Add shopCart Items to vector
}

//function to list items
void ShoppingCart::listItems()
{
	double priceTotal = 0; //A variable as double

	cout << fixed << showpoint << setprecision(2);

	//for loop
	for(unsigned int i = 0; i < cart.size(); i++)
	{
		cout << "item#" << (i+1) << endl;
		     		
		//Get name
		cout << "Name               :" << cart[i].getName() << endl;

		//Get unit
		cout << "Unit               :" << cart[i].getUnit() << endl;

		//Get price
		cout << "Per unit price     :" << cart[i].getPrice() << endl;

		//Get quantity
		cout << "Quantity           :" << cart[i].getQuantity() << endl;

		//Get total price for Item
		cout << "Total cost for item:" << cart[i].getQuantity()* cart[i].getPrice() << endl << endl;

		//Get price and quantity and calculate total price
		priceTotal += cart[i].getQuantity()*cart[i].getPrice();

	}

	//Get total price for shopping list
	cout << "Total price of all items   :" << priceTotal << endl << endl;

}

//function to edit item
void ShoppingCart:: editItem(string name_item, fstream &dataFile)
{
	//Variables to get user input for new values

	string newUnit;
			
	double newPrice;
			
	double newQuantity;

	bool isGood = false; //bool to check if name entered is in list

	//for loop
	for(unsigned int i = 0; i < cart.size(); i++)
	{
		if(cart[i].getName() == name_item)
		{
			//Get new unit
			 cout << "Please enter new unit:";
			getline(cin, newUnit);

			//Get new price
			 cout << "Please enter new price:";
					
			newPrice = double_validation(); //Function to validate input

			//Get new quantity
			 cout << "Please enter new quantity:";
					
			newQuantity = double_validation(); //Function to validate input
					
			//Assign new values for the item
					
			cart[i].setUnit(newUnit);

			cart[i].setPrice(newPrice);

			cart[i].setQuantity(newQuantity);

			isGood = true; //If item is in list

			break; //break for loop
		}

	}

	if(isGood == false)
	{
		cout << "The item you entered is not in list.\n\n";

	}

	else
	{
		cout << "Your shopping list is updated and saved as list.txt\n\n";
	}

	//Updating the list.txt
	for(unsigned int i = 0; i < cart.size(); i++)
	{
		dataFile << cart[i].getName() << "\n";

		dataFile << cart[i].getUnit() << "\n";

		dataFile << cart[i].getPrice() << "\n";

		dataFile << cart[i].getQuantity() << "\n";
	}

}

//function to remove item
void ShoppingCart::removeItem(string name_item, fstream &dataFile)
{
	bool isGood = false;

	//for loop
	for(unsigned int i = 0; i < cart.size(); i++)
	{
		//If item is found
		if(cart[i].getName() == name_item)
		{
			//Remove Item
			cart.erase(cart.begin() + i);

			isGood = true;
					
			break;
		}
	}

	if(isGood == false)
	{
		cout << "The item you entered is not in list.\n\n";
	}

	else
	{
		cout << "Your shopping list is updated and saved as list.txt\n\n";
	}

	//Updating the list.txt
	for(unsigned int i = 0; i < cart.size(); i++)
	{
		dataFile << cart[i].getName() << "\n";

		dataFile << cart[i].getUnit() << "\n";

		dataFile << cart[i].getPrice() << "\n";

		dataFile << cart[i].getQuantity() << "\n";
	}
}
