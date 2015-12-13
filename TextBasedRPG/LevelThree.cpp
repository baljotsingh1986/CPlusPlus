/*LevelThree.cpp implementation of LevelThree.h*/

#include<iostream>

#include "LevelThree.h"


//default constructor
LevelThree::LevelThree():Rooms()
{
    roomA = new room("A room with lot of beautiful things around. Don't touch anything it can be trap. Exit to south", new Item("Key 9", KEY, 0, 0, 0));

    roomB = new room("You found a key-man, may be he has a key you are looking for. Exit to north and south", new Item("Key 10", KEY, 0, 0, 0));

    roomC = new room("A place with mysterious creature. Exit to east", new Item("Herb", HERB, 4, 0, 0), new TheShadow("The Hidden Being"));

    roomD = new room("Delicious things to eat around. But be careful, can be poisonous. Exit west", new Item("Herb", HERB, 6, 0, 0));

    roomE = new room("Looks like water. How can you cross. It can be illusion. Exit to east", new Item("Key 11", KEY, 0, 0, 0), new BlueMen("Dread Man"));

    roomF = new room("Waterfalls around. Exit to north", new Item("Silverlight", WEAPON, 0, 1, 0),  new ReptilePeople("Ancient Mutant"));

    roomG = new room("Beautiful flowers around. Exit to west", new Item("Key 12", KEY, 0, 0, 0),  new ReptilePeople("Dark Face"));

    roomH = new room("Beautiful girls are dancing and lot of wine. Don't forget about your mission. Keep walking. Exit to east and west.");

    roomI = new room("A beautiful grassland. Exit to west");

    roomJ = new room("Suddenly you are in dark in dark room full of corpses. Warned you it is a magical world.\nCollect your keys and leave soon. Exit to east.");

    start = roomA;
}

//Link rooms
void LevelThree::linkRooms()
{
    roomA->south = roomC;

    roomB->north = roomD;

    roomB->south = roomI;

    roomC->east = roomB;

    roomD->west = roomE;

    roomE->east = roomF;

    roomF->north = roomG;

    roomG->west = roomH;

    roomH->east = roomJ;

    roomH->west = roomI;

    roomI->west = roomA;

    roomJ->east = roomF;
}

//World info
void LevelThree::worldInfo()
{
    std::cout << "You are in magical world mysterious things can happen. Don't get trapped\n"
              << "Collect your 4 keys and leave this place.\n\n";
}

//Destructor to clear memory
LevelThree::~LevelThree()
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


