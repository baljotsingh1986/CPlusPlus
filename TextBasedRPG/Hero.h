/************************
* Hero.h file
************************/

#ifndef HERO_H
#define HERO_H

#include <vector>

#include "Creature.h"

#include "Item.h"

//class Hero
class Hero :public Creature
{
	public:
		Hero ();

		Hero(std::string name);

        	int getKeyNum(); //To get total number of geys

		bool addItem(Item *useFul); //To add item in player's bag

		void displayItems(); //To display Item;

        	Item* returnItem(unsigned int match); //To remove and return item

		void removeItem(unsigned int match); //To remove and return item

         	int getItemNum(); //Total items user has

		double attack(); //Attack function

		double defense(); //Defense function

		~Hero();

	private:

	    int maxItems; //Maximum number of items that palyer can carry

	    int itemNum; //Items user has

	    int keyNum; //Keys user has

	    std::vector <Item*> others; //Vector to hold items(Weapons and armors)
	protected:
};
#endif //HERO_H



