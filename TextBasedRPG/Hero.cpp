/************************
* Author: Baljot Singh
* Hero.cpp file for Hero class implementation
* Contains constructors and member function definitions
* of Hero.h
************************/

#include "Hero.h"

// Default constructor
Hero::Hero ():Creature()
{
	srand(time(NULL)); //time function to generate random numbers

	this->factor = 1.0;
}

//Constructor assigns values to member
Hero::Hero (std::string name):Creature(name)
{
    srand(time(NULL)); //time function to generate random numbers

	this->name = name;

	this->type = "Hero";

	this->strength = 8;

	this->armor = 3;

	this->itemNum = 0;

	this->factor = 1.0;

	this->keyNum = 0;

	this->maxItems = 3;

	std::vector <Item*> others; //Vector to hold items(Weapons and armors)
}

//Attack
double Hero::attack()
{
	double attackHero = 0;

	attackHero = roll6Side() + roll6Side(); //2 six side dice

	return factor*attackHero;
}

//Defense
double Hero::defense()
{
	return roll6Side() + roll6Side(); //1 six side dice
}

//Function to get total number of keys so far
int Hero::getKeyNum()
{
	return keyNum;
}

//Add item to bag
bool Hero::addItem(Item *useFul)
{
	if(useFul->getType() == KEY)
	{
		std::cout << "You found a key.\n";

		keyNum++;

		return true;
	}

	else if(useFul->getType() == HERB)
	{
		std::cout << "You got a herb. It will help you to gain strength,\n\n";

		this->strength += useFul->getHeal();

		return true;
	}

	else if(itemNum >= maxItems)
    	{
        	std::cout << "You can not hold more weapons or armors. You have to remove some item from your bag.\n\n";

        	return false;
    	}

    	else
    	{
        	others.push_back(useFul);

		if(useFul->getType() == WEAPON)
		{
			std::cout << "You got a weapon named " << useFul->getName() << "\n\n";

			this->factor += useFul->getWeapon();
		}

		if(useFul->getType() == ARMOR)
		{
			std::cout << "You got a armor named " << useFul->getName() << "\n\n";

			this->armor += useFul->getShield();
		}

        	itemNum++;

        	return true;
	}
}

//Display Items
void Hero::displayItems()
{
	if(others.empty())
    	{
        	std::cout << "You don't possess any weapon or armor.\n";
    	}

    	else
    	{
        	for(unsigned int i = 0; i < others.size(); i++)
        	{
            		std::cout << "Item#" << i + 1 << "\n";

			std::cout << "Name: " << others[i]->getName() << "\n";

			if(others[i]->getType() == WEAPON)
            		{
                		std::cout << "It is a weapon.\n";
            		}

            		else if(others[i]->getType() == ARMOR)
            		{
                		std::cout << "It is an armor.\n";
            		}
        	}
	}

	std::cout << "Total number of keys you have: " << keyNum << "\n";

	std::cout << "You need " << (12 - keyNum) << " more keys to accomplish the mission.\n\n";
}

//Remove and return item
Item* Hero::returnItem(unsigned int match)
{
	Item *temp;

	for(unsigned int i = 0; i < others.size(); i++)
        {
		if(i == match - 1)
            	{
                	temp = others[i];

			itemNum--;

			if(temp->getType() == WEAPON)
                	{
                    		this->factor -= temp->getWeapon();
                	}

			else if(temp->getType() == WEAPON)
                	{
                    		this->armor -= temp->getShield();
                	}

                	others.erase(others.begin() + i);
		}
	}

        return temp;
}

//Just Remove item
void Hero::removeItem(unsigned int match)
{
	for(unsigned int i = 0; i < others.size(); i++)
        {
		if(i == match - 1)
            	{
			itemNum--;

			if(others[i]->getType() == WEAPON)
                	{
                    		this->factor -= others[i]->getWeapon();
                	}

			else if(others[i]->getType() == WEAPON)
                	{
                    		this->armor -= others[i]->getShield();
                	}

                	others.erase(others.begin() + i);
		}
	}
}

//To get total number of items
int Hero::getItemNum()
{
	return itemNum;
}

Hero::~Hero()
{
    others.clear();
}

