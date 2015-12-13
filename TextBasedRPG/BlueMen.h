/************************
* BlueMen.h file
************************/

#ifndef BLUEMEN_H
#define BLUEMEN_H

#include "Creature.h"

//class BlueMen
class BlueMen :public Creature
{
	public:
    		BlueMen ();

		BlueMen(std::string name);

		double attack();

		double defense();
	private:

	protected:
};
#endif //BLUEMEN_H


