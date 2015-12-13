/************************
* Author: Baljot Singh
* Barbarian.cpp file for Barbarian class implementation
* Contains constructors and member function definitions
* of Barbarian.h
************************/

#include "Barbarian.h"

// Default constructor
Barbarian::Barbarian ():Creature()
{
	srand(time(NULL)); //time function to generate random numbers

	this->factor = 1.0;
}

//Constructor to assign values to members
Barbarian::Barbarian (std::string name):Creature(name)
{
    srand(time(NULL)); //time function to generate random numbers

	this->name = name;

	this->type = "Barbarian";

	this->strength = 12;

	this->armor = 0;

	this->factor = 1.0;
}


//Attack function rolls 2 six side dice
double Barbarian::attack()
{
	double attackBarb = 0;

	attackBarb = roll6Side() + roll6Side(); //Method from class Creature

	return factor*attackBarb; //Multiply by factor
}

//Defense function rolls 2 six side dice
double Barbarian::defense()
{
	return roll6Side() + roll6Side();
}
