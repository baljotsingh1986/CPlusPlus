/************************
* Author: Baljot Singh
* TheShadow.cpp file for TheShadow class implementation
* Contains constructors and member function definitions
* of TheShadow.h
************************/

#include "TheShadow.h"

// Default constructor
TheShadow::TheShadow ():Creature()
{
	srand(time(NULL)); //time function to generate random numbers

	this->factor = 1.0;
}

//Constructor which assign values to members
TheShadow::TheShadow (std::string name):Creature(name)
{
    srand(time(NULL)); //time function to generate random numbers

	this->name = name;

	this->type = "Shadow";

	this->strength = 12;

	this->armor = 0;

	this->factor = 1.0;
}

//Attack function
double TheShadow::attack()
{
	double attackShad = 0;

	attackShad = roll10Side() + roll10Side(); //roll 2 ten side dice

	return factor*attackShad;
}

//Defense function for shadow
double TheShadow::defense()
{
	//50% chance shadow will disappear
	if((rand() % 1000 + 1) > 500)
	{
		return 100;
	}

	else
	{
		return roll6Side();
	}
}
