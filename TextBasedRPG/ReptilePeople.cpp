/************************
* Author: Baljot Singh
* ReptilePeople.cpp file for ReptilePeople class implementation
* Contains constructors and member function definitions
* of ReptilePeople.h
************************/

#include "ReptilePeople.h"

// Default constructor
ReptilePeople::ReptilePeople ():Creature()
{
	srand(time(NULL)); //time function to generate random numbers

	this->factor = 1.0;
}

//Constructor which assigns value to members
ReptilePeople::ReptilePeople (std::string name):Creature(name)
{
    srand(time(NULL)); //time function to generate random numbers

	this->name = name;

	this->type = "Reptile";

	this->strength = 18;

	this->armor = 7;

	this->factor = 1.0;
}

//Attack method
double ReptilePeople::attack()
{
	double attackRept = 0;

	attackRept = roll6Side() + roll6Side() + roll6Side(); //3 six side dice

	return factor*attackRept; //Return attack multiplying by factor
}

//defense
double ReptilePeople::defense()
{
	return roll6Side(); //1 six side dice
}

