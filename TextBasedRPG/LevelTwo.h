/*LevelTwo.h file */

#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "Rooms.h"

class LevelTwo:public Rooms
{
	private:

	protected:

	public:
		LevelTwo();

		virtual void linkRooms();

		virtual void worldInfo();

		~LevelTwo();
};

#endif //LEVELTWO_H
