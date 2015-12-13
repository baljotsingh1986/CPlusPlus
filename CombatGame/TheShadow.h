/************************
* TheShadow.h file
************************/

#ifndef THESHADOW_H
#define THESHADOW_H

#include "Creature.h"

//class TheShadow
class TheShadow :public Creature
{
	public:
    		TheShadow ();

		TheShadow(std::string name);

		double attack();

		double defense();
	private:

	protected:
};
#endif //THESHADOW_H



