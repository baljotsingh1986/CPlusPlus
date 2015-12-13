/************************
* Author: Baljot Singh
* Creature.cpp file for Creature class implementation
* Contains constructors and member function definitions
* of Creature.h
************************/
#include<iostream>

#include "Creature.h"

// Default constructor
Creature::Creature()
{
	srand(time(NULL)); //time function to generate random numbers
}

//Constructors takes string parameter and assign to name
Creature::Creature(std::string name)
{
    	srand(time(NULL)); //time function to generate random numbers

	this->name = name;
}

//Method to return outcome of roll for 10 sides die
int Creature::roll10Side()
{
	return (rand() % 10) + 1;
}

//Method to return outcome of roll of 6 sides die
int Creature::roll6Side()
{
	return (rand() % 6) + 1;
}

//Function definition of fight
bool Creature::fight(Creature *defenseFighter)
{
	double attack, defense, damage; //Variable for attack, defense and damage

	//Telling user about who is attacking whom
	std::cout << "Now " << this->type << " " << this->name << " is attacking " << defenseFighter->type << " " << defenseFighter->name << "\n";

	defense = defenseFighter->defense(); //Getting defense value for defense fighter

	//If defense is 100 means shadow. Shadow is somewhere else
	if(defense == 100)
	{
		std::cout << defenseFighter->name << " dodged the attacker " << this->name << ". No Damage done.\n";

		std::cout << "No damage done to " << defenseFighter->type << " " << defenseFighter->name << " by the attacker " << this->type << " " << this->name << ".\n";

		std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n";

		std::cout << "Life Left for " << this->type << " " << this->name << ":" << this->strength << "\n\n";
	}

	attack = this->attack(); //Get attack of attacker

	std::cout << "attack: " << attack << "\n";

    	std::cout << "defense: " << defense << "\n";

	damage = attack - defense - defenseFighter->armor; //Calculating damage

	//If damage is more than 0
	if(damage > 0)
	{
		defenseFighter->strength -= damage;

        	std::cout << "Damage done to " << defenseFighter->type << " " << defenseFighter->name << " by the attacker " << this->type << " " << this->name << ".: " << damage << "\n";

        	std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n";

        	std::cout << "Life Left for " << this->type << " " << this->name << ":" << this->strength << "\n\n";

        	//If opponent is dead
		if(defenseFighter->strength <= 0)
		{
			std::cout << defenseFighter->type << " " << defenseFighter->name << " is dead. " << this->type << " " << this->name << " won the fight.\n\n";

			return false;
		}
	}

	//If actual damage is less than 0
	else
    	{
		std::cout << "No damage done to " << defenseFighter->type << " " << defenseFighter->name << " by the attacker " <<  this->type << " " << this->name << ".\n";

		std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n";

		std::cout << "Life Left for " <<  this->type << " " << this->name << ":" << this->strength << "\n\n";
	}

	//Now monster attacked back
	std::cout << "The bloody monster attacks back.\n\n";

	//Telling user about who is attacking whom
	std::cout << "Now " << defenseFighter->type << " " << defenseFighter->name << " is attacking " << this->type << " " << this->name << "\n";

	defense = this->defense(); //Getting defense value for defense fighter

	attack = defenseFighter->attack(); //Get attack of attacker

	std::cout << "attack: " << attack << "\n";

    	std::cout << "defense: " << defense << "\n";

	damage = attack - defense - this->armor; //Calculating damage

	//If damage is more than 0
	if(damage > 0)
	{
		this->strength -= damage;

        	std::cout << "Damage done to " << this->type << " " << this->name << " by the attacker " << defenseFighter->type << " " << defenseFighter->name << ".: " << damage << "\n";

        	std::cout << "Life Left for " << this->type << " " << this->name << ":" << this->strength << "\n";

        	std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n\n";

        	//If opponent is dead
		if(this->strength <= 0)
		{
			std::cout << this->type << " " << this->name << " is dead. " << defenseFighter->type << " " << defenseFighter->name << " won the fight.\n\n";

			return true;
		}
	}

	//If actual damage is less than 0
	else
    	{
		std::cout << "No damage done to " << this->type << " " << this->name << " by the attacker " <<  defenseFighter->type << " " << defenseFighter->name << ".\n";

		std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n";

		std::cout << "Life Left for " <<  this->type << " " << this->name << ":" << this->strength << "\n\n";
	}

	return false;
}


int Creature::getKeyNum()
{
    return 0;
}

Item* Creature::returnItem(unsigned int match)
{
    return NULL;
}

int Creature::getItemNum()
{
    return 0;
}

//Method to get type of a character
std::string Creature::getType()
{
	return this->type;
}

double Creature::getStrength()
{
    return this->strength;
}

//Method to get name of a character
std::string Creature::getName()
{
	return this->name;
}

//Default virtual destructor
Creature::~Creature(){}
