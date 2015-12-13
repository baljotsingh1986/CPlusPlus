/************************
* Author: Baljot Singh
* BlueMen.cpp file for BlueMen class implementation
* Contains constructors and member function definitions
* of BlueMen.h
************************/

#include "BlueMen.h"

// Default constructor
BlueMen::BlueMen ():Creature()
{
	srand(time(NULL)); //time function to generate random numbers

	this->factor = 1.0;
}

//Constructor to assign value to members
BlueMen::BlueMen (std::string name):Creature(name)
{
    	srand(time(NULL)); //time function to generate random numbers

	this->name = name;

	this->type = "Bluemen";

	this->strength = 12;

	this->armor = 3;

	this->factor = 1.0;
}

//Attack value roll 2 ten side dice
double BlueMen::attack()
{
	double attackMen = 0;

	attackMen = roll10Side() + roll10Side(); //Roll 10 side die from class Creature

	return factor*attackMen; //Return attack multiply by factor
}

//Defense value roll 3 six side dice
double BlueMen::defense()
{
	return roll6Side() + roll6Side() + roll6Side();
}

