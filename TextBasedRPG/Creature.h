/************************
* Creature.h file
* This is abstract class all creature classes inherit
* from this class
************************/

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include<ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Item.h"

//Creature abstract class
class Creature
{
	private:

	protected:

	    	double strength; //Strength of character which can change during fight

		int armor; //Armor of character

		double factor; //Factor will be used for attack modifier

		std::string name; //Name of character

		std::string type; //Type of character

		//Method to return outcome of roll for 10 side die
        	int roll10Side();

		//Method to return outcome of roll for 6 side die
        	int roll6Side();
	public:

   		Creature(); //Default constructor

		Creature(std::string); //Constructor which assign values to the members

   		std::string getName(); //Method to get name of character

   		double getStrength();

		std::string getType(); //Method to get type of character

   		virtual double attack()=0; //Pure virtual function for attack

		virtual double defense()=0; //Pure virtual function for defense

		bool fight(Creature *defenseFighter); //Method to engage fight between two characters

		virtual int getKeyNum(); //Virtual function to get number of keys Hero has

		virtual bool addItem(Item *useFul){return false;} //Virtual function to add Item to Hero

		virtual void displayItems(){} //virtual function to display item for hero

        	virtual Item* returnItem(unsigned int match); //virtual function to return and remove item for hero

        	virtual void removeItem(unsigned int match){} //virtual function to remove item for hero

        	virtual int getItemNum(); //Virtual function to get item number

     		virtual ~Creature(); //virtual destructor
};

#endif // CREATURE_H
