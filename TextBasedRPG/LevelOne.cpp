/*LevelOne.cpp implementation of LevelOne.h*/

#include<iostream>

#include "LevelOne.h"

//default constructor
LevelOne::LevelOne():Rooms()
{
    roomA = new room("You are in a subway, which leads to 2 direction, north and east.");

    roomB = new room("You are in dark station, which has 2 exit, north and east", new Item("Key 1", KEY, 0, 0, 0), new Goblin("Hard Head"));

    roomC = new room("You are in a endless tunnel, which only leads to south.", new Item("Herb", HERB, 14, 0, 0), new Goblin("Golum"));

    roomD = new room("You are entered a old shop, old things around. Exit to west and north", new Item("Power Gun", WEAPON, 0, 0.8, 0), new Goblin("Attila"));

    roomE = new room("You are entered a old garage, may be you can find some armor.Exit west or east", new Item("Wooden Armor", ARMOR, 0, 0, 2), new Barbarian("Jack"));

    roomF = new room("You are entered a old house, looks like haunted.Exit to west", new Item("Key 2", KEY, 0, 0, 0), new TheShadow("The invisible"));

    roomG = new room("You are entered a basement, a creepy creature there.Exit to east", new Item("Key 3", KEY, 0, 0, 0), new ReptilePeople("The Brutal"));

    roomH = new room("You are in old museum, may find some good armor. Exit to south", new Item("Diamond armor", ARMOR, 0, 0, 5), new TheShadow("The invisible"));

    roomI = new room("You are in dark closed mental hospital.Exit to north", new Item("Key 4", KEY, 0, 0, 0), new TheShadow("The Bloody"));

    roomJ = new room("Exit");

    start = roomA;
}

void LevelOne::linkRooms()
{
    roomA->north = roomB;

    roomA->east = roomJ;

    roomB->north = roomC;

    roomB->east = roomA;

    roomC->south = roomD;

    roomD->west = roomA;

    roomD->north = roomE;

    roomE->west = roomF;

    roomE->east = roomA;

    roomF->west = roomG;

    roomG->east = roomH;

    roomH->south = roomI;

    roomI->north = roomJ;

    roomJ->east = roomC;
}

//To display world info
void LevelOne::worldInfo()
{
    std::cout << "You are in some abandoned town occupied by\nsome mysterious creatures.\n"
              << "Your mission is to kill all creatures and find 4 keys in this world.\n\n";
}

//Destructor to clear memory
LevelOne::~LevelOne()
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
