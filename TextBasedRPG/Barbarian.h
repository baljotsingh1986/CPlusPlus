/************************
* Barbarian.h file
************************/

#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Creature.h"

//class Barbarian
class Barbarian :public Creature
{
	public:
    		Barbarian (); //Default constructor

		Barbarian (std::string name); //Constructor assigns value to members

        	double attack(); //Attack function

		double defense(); //Method to get defense value
	private:

	protected:
};
#endif //BARBARIAN_H
