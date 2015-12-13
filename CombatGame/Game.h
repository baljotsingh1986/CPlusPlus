/************************
* Game.h file
* This class helps in creating teams. Shuffling characters
* in each team and remove character when character lost the fight.
************************/

#ifndef GAME_H
#define GAME_H

#include<list>

#include "Creature.h"
#include "Barbarian.h"
#include "ReptilePeople.h"
#include "BlueMen.h"
#include "TheShadow.h"
#include "Goblin.h"

//Game class
class Game
{
	private:
		std::list <Creature*> teams; //List to hold characters

        	int winNum; //To count number of wins by a team

		double points; //To count total points of a team

	protected:

	public:

   		Game(); //Default constructor

		void addFighter(Creature *fighter); //Method to add fighter

   		double getPoints(); //Method to get points

   		double getWin(); //Method to get number of wins

		void setPoints(double points); //Method to set points

		void setWin(int winNum); //Method to set wins

		Creature* getCreature();  //Method to get character from line to fight

		Creature* lastCreatures(); //Method to get last creatures in team after tournament is finished

		void setCreature(); //Method to shuffle creature if character win

		Creature* removeCreature(); //Method to remove character from line when it lost

		bool isEmpty(); //To check if line is empty i.e. all characters are dead in a team

		~Game(); //Destructor
};

#endif // GAME_H
