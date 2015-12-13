/*LevelOne.h file */

#ifndef LEVELONE_H
#define LEVELONE_H

#include "Rooms.h"

class LevelOne:public Rooms
{
	private:

	protected:

	public:
		LevelOne();
		
		virtual void linkRooms();

		virtual void worldInfo();

        	~LevelOne();
};

#endif //LEVELONE_H
