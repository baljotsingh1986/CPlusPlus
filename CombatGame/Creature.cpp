/************************
* Author: Baljot Singh
* Creature.cpp file for Creature class implementation
* Contains constructors and member function definitions
* of Creature.h
************************/
#include<iostream>

#include "Creature.h"

// Default constructor
Creature::Creature()
{
	srand(time(NULL)); //time function to generate random numbers

	this->points = 0;

	this->win = 0;

	this->damage = 0;

	this->totalFights = 0;

	this->overall = 0;
}

//Constructors takes string parameter and assign to name
Creature::Creature(std::string name)
{
	this->name = name;

	this->points = 0;

	this->win = 0;

	this->damage = 0;

	this->totalFights = 0;

	this->overall = 0;
}

//Method to return outcome of roll for 10 sides die
int Creature::roll10Side()
{
	return (rand() % 10) + 1;
}

//Method to return outcome of roll of 6 sides die
int Creature::roll6Side()
{
	return (rand() % 6) + 1;
}

//Function definition of fight
double Creature::fight(Creature *defenseFighter)
{
	double attack, defense, damage; //Variable for attack, defense and damage

	//Telling user about who is attacking whom
	std::cout << "Now " << this->type << " " << this->name << " is attacking " << defenseFighter->type << " " << defenseFighter->name << "\n";

	defense = defenseFighter->defense(); //Getting defense value for defense fighter

	//If defense is 100 means shadow. Shadow is somewhere else
	if(defense == 100)
	{
		std::cout << defenseFighter->name << " dodged the attacker " << this->name << ". No Damage done.\n";

		std::cout << "No damage done to " << defenseFighter->type << " " << defenseFighter->name << " by the attacker " << this->type << " " << this->name << ".\n";

		std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n";

		std::cout << "Life Left for " << this->type << " " << this->name << ":" << this->strength << "\n\n";

		return defenseFighter->strength; //return strength
	}

	attack = this->attack(); //Get attack of attacker

	std::cout << "attack: " << attack << "\n";

    	std::cout << "defense: " << defense << "\n";

	damage = attack - defense - defenseFighter->armor; //Calculating damage

    	//If Goblin is fighting with other creature
	if(this->type == "Goblin" && defenseFighter->type != "Goblin")
    	{
        	//If attack is 12
		if(attack == 12)
        	{
               		//Defense player will be halved his/her attack
			defenseFighter->factor *= 0.5;

			this->points += 2.5; //If goblin cut tendon 2.5 point

			std::cout << this->type << " " << this->name << " severely injured the " << defenseFighter->type << " " << defenseFighter->name << " by cutting tendon.\n\n";
		}

		//If damage is more than 0
		if(damage > 0)
            	{
                	defenseFighter->strength -= damage; //Strength of fighter will reduced

                	defenseFighter->damage += damage; //Accumulate the damage for fighter

                	std::cout << "Damage done to " << defenseFighter->type << " " << defenseFighter->name << " by the attacker "
				  << this->type << " " << this->name << ".: " << damage << "\n";

                	std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n";

                	std::cout << "Life Left for " << this->type << " " << this->name << ":" << this->strength << "\n\n";

                	//If defense fighter is dead
			if(defenseFighter->strength <= 0)
        		{
            			//If there is damage to winner
				if(this->damage > 0)
				{
					if(rand() % 2 == 0)
					{
						this->strength += (0.5)*this->damage; //Recover damage 0.5
					}

					else
					{
						this->strength += (0.25)*this->damage; //Recover damage 0.25
					}
				}

				this->damage = 0; //Set damage of winner to 0 for next fight

				this->points += 2.0; //Goblin will get 2 points per win

				this->win++; //Increment win

				std::cout << defenseFighter->type << " " << defenseFighter->name << " is dead. " << this->type << " " << this->name << " won the fight.\n\n";
			}

			return defenseFighter->strength; //return strength
		}

		//If damage is less than or equal to 0
		else
            	{
			//If attack is 12 there is damage
			if(attack == 12)
			{
                		std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n";

                		std::cout << "Life Left for " << this->type << " " << this->name << ":" << this->strength << "\n\n";

                		return defenseFighter->strength; //return strength
			}

			//If attack is not 12 no damage
			else
			{
				std::cout << "No damage done to " << defenseFighter->type << " " << defenseFighter->name << " by the attacker " << this->name << ".\n";

				std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n";

                		std::cout << "Life Left for " << this->type << " " << this->name << ":" << this->strength << "\n\n";

                		return defenseFighter->strength; //return strength
			}
		}
	}

	//Else if any other fight between any characters
	//If damage is more than 0
	else if(damage > 0)
	{
		defenseFighter->strength -= damage; //New strength after damage

	    	defenseFighter->damage += damage; //Accumulate the damage of fighter

        	std::cout << "Damage done to " << defenseFighter->type << " " << defenseFighter->name << " by the attacker " << this->type << " " << this->name << ".: " << damage << "\n";

        	std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n";

        	std::cout << "Life Left for " << this->type << " " << this->name << ":" << this->strength << "\n\n";

        	//If opponent is dead
		if(defenseFighter->strength <= 0)
        	{
            		//If there was damage to winner recover damage
			if(this->damage > 0)
			{
				if(rand() % 2 == 0)
				{
					this->strength += (0.5)*this->damage;
				}

				else
				{
					this->strength += (0.25)*this->damage;
				}

				//I think tendon injury should also recover but not much
				if(this->factor < 1)
                		{
                    			this->factor += (0.25)*this->factor;
                		}
			}

			this->damage = 0; //Set winner damage to 0 for next fight

			//If barbarian is fighting with barbarian
			if(this->type == "Barbarian" && defenseFighter->type == "Barbarian")
            		{
                		this->points += 1.0; //Barbarian will get 1.0 point

                		this->win++; //increment win
			}

			//If barbarian is fighting with other character but not goblin
			else if(this->type == "Barbarian" && defenseFighter->type != "Goblin")
            		{
                		this->points += 1.5; //Barbarian will get 1.5 point

                		this->win++;
            		}

			//If bluemen vs bluemen
            		else if(this->type == "Bluemen" && defenseFighter->type == "Bluemen")
            		{
                		this->points += 1; //BlueMen will get 1 points

                		this->win++;
			}

            		//If bluemen vs others
			else if(this->type == "Bluemen" && defenseFighter->type != "Bluemen")
            		{
                		this->points += 0.4; //BlueMen will get 0.4 points

                		this->win++;
            		}

			//If reptile vs reptile
            		else if(this->type == "Reptile" && defenseFighter->type == "Reptile")
            		{
                		this->points += 1.0; //Reptile will get 1 points

                		this->win++;
			}

			//If reptile vs others but not bluemen
            		else if(this->type == "Reptile" && defenseFighter->type != "Bluemen")
            		{
                		this->points += 0.5; //Reptile will get 0.5 points

                		this->win++;
            		}

			//Shadow's luck
            		else
            		{
                		this->points += 1.0;

                		this->win++;
			}

			std::cout << defenseFighter->type << " " << defenseFighter->name << " is dead. " << this->type << " " << this->name << " won the fight.\n\n";
		}

		return defenseFighter->strength; //Return strength
	}

	//If actual damage is less than 0
	else
    	{
		std::cout << "No damage done to " << defenseFighter->type << " " << defenseFighter->name << " by the attacker " <<  this->type << " " << this->name << ".\n";

		std::cout << "Life Left for " << defenseFighter->type << " " << defenseFighter->name << ":" << defenseFighter->strength << "\n";

		std::cout << "Life Left for " <<  this->type << " " << this->name << ":" << this->strength << "\n\n";

		return defenseFighter->strength; //Return strength
	}
}

//Method to get points for character
double Creature::getPoints()
{
	return this->points;
}

//Method to get win for a character
double Creature::getWin()
{
	return this->win;
}

//Method to get type of a character
std::string Creature::getType()
{
	return this->type;
}

//Method to get name of a character
std::string Creature::getName()
{
	return this->name;
}

//Method to set overall score for a character
//this will determine the position of characters after tournament
void Creature::setOverall()
{
	//If somebody fought
	if(this->totalFights != 0)
    	{
		//If some character stays alive after 2 fights in tournament will be given strength score
        	if(this->strength > 0 && totalFights >= 2)
		{
			this->points += this->strength/this->origStrength; //Add strength points to points

			this->overall = (this->win/this->totalFights) + this->points; //Calculate win percentage and add to points
		}

		//Else just regular score
		else
		{
			this->overall = (this->win/this->totalFights) + this->points;
		}
    	}

	//If no fight, which is not possible in this game
    	else
    	{
		this->overall = 0;
    	}
}

//Overall to break tie
void Creature::setOverall(double tieBreaker)
{
	this->overall += tieBreaker;
}

//Method to set total fights for a character
void Creature::setTotalFights()
{
	this->totalFights++;
}

//Method to get total fights for a character
double Creature::getTotalFights()
{
	return this->totalFights;
}

//Method to get overall score for a character
double Creature::getOverall()
{
	return this->overall;
}

//Default virtual destructor
Creature::~Creature(){}
