/************************
* Author: Baljot Singh
* Game.cpp file for Game class implementation
* Contains constructors and member function definitions
* of Game.h
************************/

#include "Game.h"
/*Constructor*/
Game::Game()
{
	std::list <Creature*> teams;  

	winNum = 0;

	points = 0;
}


//Method to add fighter
void Game::addFighter(Creature *fighter)
{
	teams.push_back(fighter);
}


//Method to get points of a team
double Game::getPoints()
{
	return points;
}


//Method to get number of wins by a team
double Game::getWin()
{
	return winNum;
}

//Method to set number of wins
void Game::setWin(int winNum)
{
	this->winNum += winNum;
}

//Method to set points
void Game::setPoints(double points)
{
	this->points += points;
}

//Method to get creature
Creature* Game::getCreature()
{
	return teams.front();
}

//Method to shuffle character
void Game::setCreature()
{
	Creature *temp = teams.front(); //Take the head character

    	temp->setTotalFights(); //Set total fights for head character

    	teams.pop_front(); //Remove from front of line

    	teams.push_back(temp); //Add at back of line
}

//Method to remove the character after it lost
Creature* Game::removeCreature()
{
	Creature *temp = teams.front(); //Take the head character

    	temp->setTotalFights(); //Set total fights for head character

    	this->points += temp->getPoints(); //Add characters points to team's point

    	temp->setOverall(); //Set overall score for character

    	teams.pop_front(); //Remove character from line

    	return temp; //return character to add into loser pile
}

//Method to remove characters from team after tournament is finished
Creature* Game::lastCreatures()
{
	Creature *temp = teams.front(); //Take the head character

        temp->setOverall(); //Set overall score for character

        this->points += temp->getPoints();  //Add characters points to team's point

    	teams.pop_front(); //Remove character from line

    	return temp; //return character to add into results
}

//Mehod to check if team is empty
bool Game::isEmpty()
{
	return teams.empty();
}

//Constructor
Game::~Game()
{
	//By chance if team is not empty, but it is not possible....
	if(!teams.empty())
        {
		for(std::list<Creature*>::iterator it = teams.begin(); it != teams.end(); ++it)
                {
			delete *it;
                }
        }

        teams.clear();
}
