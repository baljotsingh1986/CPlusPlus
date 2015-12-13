/************************
* ReptilePeople.h file
************************/

#ifndef REPTILEPEOPLE_H
#define REPTILEPEOPLE_H

#include "Creature.h"

//class Reptile People
class ReptilePeople :public Creature
{
	public:
    		ReptilePeople ();

		ReptilePeople(std::string name);

		double attack();

		double defense();
	private:

	protected:
};
#endif //REPTILEPEOPLE_H

