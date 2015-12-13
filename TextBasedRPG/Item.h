/*Item.h file */

#ifndef ITEM_H
#define ITEM_H

enum TYPE {KEY, HERB, ARMOR, WEAPON};

class Item
{
	private:
		std::string itemName;

		int shield;

		int heal;

		double weapon;

		TYPE itemType;

	public:

	    	Item();

		Item(std::string name,TYPE type, int herb, double power, int armor);

		std::string getName();

		int getHeal();

		int getShield();

		double getWeapon();

		TYPE getType();

		~Item();
};

#endif //ITEM_H
