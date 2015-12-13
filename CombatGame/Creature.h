/************************
* Creature.h file
* This is abstract class all creature classes inherit
* from this class
************************/

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include<ctime>
#include <cstdlib>

//Creature abstract class
class Creature
{
	private:

	protected:
		double origStrength; //Original strength of character

		double strength; //Strength of character which can change during fight

		double points; //Points gained by character

		double win; //Number of wins for a character

		double totalFights; //Total fights fought by a character

		double overall; //Overall score of character

		int armor; //Armor of character

		double factor; //Factor will be used for attack modifier

		double damage; //Damage for character

		std::string name; //Name of character

		std::string type; //Type of character

		//Method to return outcome of roll for 10 side die
        	int roll10Side();

		//Method to return outcome of roll for 6 side die
        	int roll6Side();
	public:

   		Creature(); //Default constructor

		Creature(std::string); //Constructor which assign values to the members

        	void setOverall(); //Method to set overall score of character

		void setOverall(double tieBreaker); //To break tie

        	void setTotalFights(); //Method set total fights fought by character

   		virtual std::string getName(); //Method to get name of character

		double getPoints(); //Method to get point of character

		double getOverall(); //Method to get overall score of character

		double getTotalFights(); //Method to get total fights of character

		double getWin(); //Method to get number of wins of character

		std::string getType(); //Method to get type of character

   		virtual double attack()=0; //Pure virtual function for attack

		virtual double defense()=0; //Pure virtual function for defense

		double fight(Creature *defenseFighter); //Method to engage fight between two characters

		virtual ~Creature(); //virtual destructor
};

#endif // CREATURE_H
