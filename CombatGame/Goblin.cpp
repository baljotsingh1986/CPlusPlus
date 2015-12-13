/************************
* Author: Baljot Singh
* Goblin.cpp file for Goblin class implementation
* Contains constructors and member function definitions
* of Goblin.h
************************/

#include "Goblin.h"

// Default constructor
Goblin::Goblin ():Creature()
{
	srand(time(NULL)); //time function to generate random numbers

	this->factor = 1.0;
}

//Constructor assigns values to member
Goblin::Goblin (std::string name):Creature(name)
{
	this->name = name;

	this->type = "Goblin";

    this->origStrength = 8;

	this->strength = 8;

	this->armor = 3;

	this->factor = 1.0;
}
//Overloaded attack function for Goblin vs Others
double Goblin::attack()
{
	double attackGob = 0;

	attackGob = roll6Side() + roll6Side(); //2 six side dice

	return attackGob;
}

//Defense for Goblin
double Goblin::defense()
{
	return roll6Side(); //1 six side dice
}
