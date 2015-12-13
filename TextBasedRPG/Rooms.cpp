/*Rooms.cpp implementation of Rooms.h*/

#include<iostream>

#include "Rooms.h"

//default constructor
Rooms::Rooms()
{

}

//To display current info
std::string Rooms::getCurrentInfo()
{
	std::string info = start->description;

	//If a vilian is there and not dead
	if(start->vilian != NULL && start->isVilianDead == false)
    	{
        	info += "\nIt looks like some monster is hiding at this place. You have to fight\n";
	}

	//If vilian was present and now dead
    	else if(start->vilian != NULL && start->isVilianDead == true)
    	{
        	info += "\nThere was a bloody monster. But you already killed it, don't you remember?\n";
	}

	//If there was never a monster
    	else if(start->vilian == NULL)
    	{
        	info += "\nThere is no monster at this place. You are lucky\n";
	}

	//If there is item and not taken yet
    	if(start->roomItem != NULL && start->isItemTaken == false)
    	{
        	info += "\nThere is some item available here, it may be useful for you.\n";
	}

	//If there was item and already taken
    	else if(start->roomItem != NULL && start->isItemTaken == true)
    	{
        	info += "\nThere was some item available here, but you already took it.\n";
    	}

	//If there was never a item
    	else if(start->roomItem == NULL)
        {
		info += "\nNothing to grab here.\n";
	}

	return info;
}

//Function to start game
bool Rooms::startGame(char dir, Creature *player)
{
    bool isDead;

	if(dir == 'e')
        {
		if(start->east != NULL)
                {
			start = start->east;
                }

                else
                {
			std::cout << "There is no exit east direction.\n\n";
                }
            }

	else if(dir == 'w')
        {
		if(start->west != NULL)
                {
			start = start->west;
                }

                else
                {
			std::cout << "There is no exit west direction.\n\n";
                }
	}

	else if(dir == 'n')
        {
		if(start->north != NULL)
                {
			start = start->north;
                }

                else
                {
			std::cout << "There is no exit north direction.\n\n";
                }
	}

	else if(dir == 's')
        {
		if(start->south != NULL)
                {
			start = start->south;
                }

		else
                {
			std::cout << "There is no exit south direction.\n\n";
                }
	}

	else if(dir == 'a')
        {
		if(start->vilian == NULL)
                {
			return false;
		}

                else if(start->vilian != NULL && start->isVilianDead == true)
                {
			return false;
                }

		else
                {
			isDead = player->fight(start->vilian);

			if(start->vilian->getStrength() <= 0)
                	{
                    		start->isVilianDead = true;
                	}

			return isDead;
                }
	}

	else if(dir == 'g')
        {
		if(start->roomItem == NULL)
                {
			return false;
		}

                else if(start->roomItem != NULL && start->isItemTaken == true)
                {
			return false;
                }

                else if(start->vilian != NULL && start->isVilianDead == false)
                {
			std::cout << "You must have to defeat the monster to grab this item.\n";

                    	return false;
		}

		else if(start->vilian != NULL && start->isVilianDead == true)
		{
			if(player->addItem(start->roomItem))
            		{
                		start->isItemTaken = true;
            		}

			return false;
		}

		else if(start->vilian == NULL)
		{
			if(player->addItem(start->roomItem))
            		{
                		start->isItemTaken = true;
            		}

            		return false;
        	}
	}

        //If current room is exit
	if(start->description == "Exit")
	{
		std::cout << "It looks like a exit.\n";
		std::cout << "East direction goes back to town.\n\n";

		if(player->getKeyNum() != 12)
                {
			std::cout << "But you don't have keys to open it.\n";

			return false;
		}

                else if(player->getKeyNum() == 12)
		{
			std::cout << "wow! You accomplished an impossible mission.\n\n";

			return true;
		}
	}

	return false;
}

//bool to check if a room can hold item or not
bool Rooms::checkItemHold()
{
	//If roomItem points to NULL it can not hold item
	if(start->roomItem == NULL)
    	{
        	return false;
	}

	else
	{
		return true;
	}
}

//To place item in room
void Rooms::placeItem(Item *fidelity)
{
	//If roomItem points to NULL it can not hold item
	if(start->roomItem == NULL)
    	{
        	std::cout << "Weapon or armor can not left here. Go somewhere else.\n\n";
	}

	else
    	{
        	start->roomItem = fidelity;

        	start->isItemTaken = false;
	}
}

//To check if item is available in room
bool Rooms::itemAvailable()
{
	if(start->isItemTaken)
    	{
		return false;
	}

	else
    	{
        	return true;
    	}
}

//Destructor to clear memory
Rooms::~Rooms()
{}
