/*LevelThree.h file */

#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "Rooms.h"

class LevelThree:public Rooms
{
	private:

	protected:

	public:
		LevelThree();

		virtual void linkRooms();

		virtual void worldInfo();

		~LevelThree();
};

#endif //LEVELTHREE_H
