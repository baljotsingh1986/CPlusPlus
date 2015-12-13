/************************
* Items.cpp file for Items class implementation
* Contains constructors and member function definitions
* of Items.h
************************/

#include "Items.h"

using namespace std;

Items::Items(){} //default constructor

//constructor which takes two strings and two double as parameter
Items::Items(string itemName, string itemUnit, double itemPrice, double itemQuantity)
{
	name = itemName;  //Set name

	unit = itemUnit;  //Set unit

	price = itemPrice; //Set price

	quantity = itemQuantity; //Set quantity
}

//Method to set unit
void Items::setUnit(string unit_item)
{
	unit = unit_item;
}

//Method to set price
void Items::setPrice(double unit_price)
{
	price = unit_price;
}

//Method to set quantiy
void Items::setQuantity(int unit_quantity)
{
	quantity = unit_quantity;
}

//Method to get name
string Items::getName()
{
	return name;
}

//Method to get unit
string Items::getUnit()
{
	return unit;
}

//Method to get quantity
double Items::getQuantity()
{
	return quantity;
}

//Method to get price
double Items::getPrice()
{
	return price;
}

