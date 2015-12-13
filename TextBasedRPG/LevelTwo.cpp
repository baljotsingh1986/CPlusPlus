/*LevelTwo.cpp implementation of LevelTwo.h*/

#include<iostream>

#include "LevelTwo.h"

//default constructor
LevelTwo::LevelTwo():Rooms()
{
    roomA = new room("You are in marshy land, which leads to 2 direction, east and south.", new Item("Key 5", KEY, 0, 0, 0), new ReptilePeople("The Killer"));

    roomB = new room("Dense trees, even sunlight can't reach. 2 exits, north and west", new Item("Key 6", KEY, 0, 0, 0), new BlueMen("Invincible"));

    roomC = new room("A cave, which only leads to south.", new Item("Herb", HERB, 5, 0, 0), new Goblin("The Tiny"));

    roomD = new room("A dark and bloody river. South direction leads across river", new Item("Samurai sword", WEAPON, 0, 0.4, 0), new ReptilePeople("Sharp Teeth"));

    roomE = new room("You fell into a pit, encountered a weird creature.Exit west or east", new Item("Steal Armor", ARMOR, 0, 0, 4), new Barbarian("The weird"));

    roomF = new room("Land of dead. Exit to east", new Item("Key 7", KEY, 0, 0, 0), new TheShadow("The Dead"));

    roomG = new room("Mysterious sounds coming. Exit to west", new Item("Key 8", KEY, 0, 0, 0), new BlueMen("Immortal"));

    roomH = new room("Vast land, nothing around. Exit to east");

    roomI = new room("An endless trail going from east to west, hidden exit to south and north");

    roomJ = new room("Suddenly beautiful trees and garden. Exit to east", new Item("Herb", HERB, 4, 0, 0));

    start = roomA;
}

//Link rooms
void LevelTwo::linkRooms()
{
    roomA->south = roomB;

    roomA->east = roomJ;

    roomB->north = roomC;

    roomB->west = roomA;

    roomC->south = roomD;

    roomD->south = roomE;

    roomE->east = roomF;

    roomE->west = roomC;

    roomF->east = roomG;

    roomG->west = roomH;

    roomH->east = roomI;

    roomI->south = roomA;

    roomI->north = roomJ;

    roomJ->east = roomE;
}

//Display world info
void LevelTwo::worldInfo()
{
    std::cout << "You are in dark jungle which is full of bloody creature. Hopefully you are\n"
              << "equipped with armors, weapons and herbs, otherwise go back and collect.\n"
              << "weapons. You have to collect 4 keys from here\n";
}

//Destructor to clear memory
LevelTwo::~LevelTwo()
{
	delete roomA;

	delete roomB;

	delete roomC;

	delete roomD;

	delete roomE;

	delete roomF;

	delete roomG;

	delete roomH;

	delete roomI;

	delete roomJ;
}

