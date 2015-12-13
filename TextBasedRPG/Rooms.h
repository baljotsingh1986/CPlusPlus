/*Rooms.h file */

#ifndef ROOMS_H
#define ROOMS_H

#include "Item.h"
#include "Goblin.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "TheShadow.h"
#include "ReptilePeople.h"
#include "Hero.h"

class Rooms
{
   	private:
	
	protected:
        	//Room
		class room
      		{
			private:
				
				friend class Rooms;

				friend class LevelOne;

				friend class LevelTwo;

				friend class LevelThree;
				
				std::string description;

	 			room *east;

	 			room *west;

	 			room *north;

	 			room *south;

				Item *roomItem;

				Item *originalItem;    //Helps to clear memory

				Creature *vilian;

				bool isVilianDead;

				bool isItemTaken;
				
				bool isVisited;
				
				//Constructor which assigns values to attributes
				room(std::string description, Item *item = NULL, Creature *vilian = NULL)
				{
					this->east = NULL;

					this->west = NULL;

					this->north = NULL;

					this->south = NULL;

					this->description = description;

					this->roomItem = item;

					this->originalItem = item;

					this->vilian = vilian;

					this->isItemTaken = false;

					this->isVilianDead = false;

					this->isVisited = false;
				}

			public:
                		//Destructor
				~room()
                		{
					delete originalItem;
     					
					originalItem = NULL;

					delete vilian;
                        		
					vilian = NULL;
				}
		
		}; room *roomA, *roomB, *roomC, *roomD, *roomE, *roomF, *roomG, *roomH, *roomI, *roomJ, *start; //10 rooms and 1 for current location

	public:
		Rooms();

		virtual void linkRooms()=0; //Pure virtual function to link rooms

		virtual void worldInfo()=0; //Pure virtual function to display world info

		bool startGame(char dir, Creature *player);

		std::string getCurrentInfo();

		bool checkItemHold();

		void placeItem(Item *fidelity);

		bool itemAvailable();
		
		virtual ~Rooms();
};

#endif //ROOMS_H
