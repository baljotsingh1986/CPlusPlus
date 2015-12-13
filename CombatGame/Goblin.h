/************************
* Goblin.h file
************************/

#ifndef GOBLIN_H
#define GOBLIN_H

#include "Creature.h"

//class Goblin
class Goblin :public Creature
{
	public:
    		Goblin ();

		Goblin(std::string name);

		double attack();

		double defense();
	private:

	protected:

};
#endif //THESHADOW_H



