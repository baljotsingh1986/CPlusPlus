/***************************
 * Author: Baljot Singh
 * Date created:  2/24/2015
 * Program name: testCombat.cpp
 * Description: This function tests the combat between teams with different combinations of characters
 * input: None
 * Output:The output will tell which team wins and top performer.
 ****************************/

#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<cstdlib>
#include <stack>
#include <vector>
#include <algorithm>


//Headers for all classes

#include "Barbarian.h"
#include "ReptilePeople.h"
#include "BlueMen.h"
#include "TheShadow.h"
#include "Goblin.h"
#include "Game.h"
#include "testCombat.h"

//Class to help sort based on overall score
class Sort
{
	public:
		bool operator()(Creature *a, Creature *b)
		{
			return a->getOverall() > b->getOverall();
		}
};

//Starting main function
void testCombat()
{
	srand(time(NULL));

	double life1, life2; //Variable to assign to life of players

	std::string testAgain, fileName; //Variable to ask user test again and for file name

	std::ofstream outFile; //outFile to store data

	std::stack<Creature*> dead; //Container for dead

	std::vector<Creature*> results; //Container for results

	Creature* temp; //temp character

	std::string choice; //To ask user choice

	int count; //For count

	//Starting do-while loop
	do
	{
		//Assign life to 1

		life1 = 1;

		life2 = 1;

		//Asking user for file name to save results
		std::cout << "\nPlease give the name of file to save results for:";
		std::getline(std::cin, fileName);

    		fileName = fileName + ".txt";

    		outFile.open(fileName.c_str(), std::ios::app); //open file in append mode

		Game *team1 = new Game; //team 1

		Game *team2 = new Game; //team 2

		//Giving user options to test different sets of characters
		std::cout << "\nPlease give your choices for characters in team:\n";

		std::cout << "Enter 1, for same 5 characters in both teams. In this case Bluemen\ni.e. 5 Bluemen vs 5 Bluemen.\n"
                  	  << "Enter 2, for same line up of 5 characters in both teams.\ne.g. at 1st position Goblin, second Barbarian"
                  	  << "so on and same line up in opposite team.\n"
                  	  << "Enter 3, for different line up of 5 characters in teams.\ne.g. in one team Goblin at 1st and in other Barbarian at 1st.\n";

		std::cout << "Enter your choice: ";

		std::getline(std::cin, choice);

		if(choice == "1")
            	{
			team1->addFighter(new BlueMen(" blu1 of Team 1 "));

		    	team1->addFighter(new BlueMen(" blu2 of Team 1 "));

		    	team1->addFighter(new BlueMen(" blu3 of Team 1 "));

			team1->addFighter(new BlueMen(" blu4 of Team 1 "));

			team1->addFighter(new BlueMen(" blu5 of Team 1 "));

			team2->addFighter(new BlueMen(" blu1 of Team 2 "));

			team2->addFighter(new BlueMen(" blu2 of Team 2 "));

			team2->addFighter(new BlueMen(" blu3 of Team 2 "));

			team2->addFighter(new BlueMen(" blu4 of Team 2 "));

			team2->addFighter(new BlueMen(" blu5 of Team 2 "));
		}

		else if(choice == "2")
            	{
			team1->addFighter(new Goblin(" Gob of Team 1 "));

			team1->addFighter(new Barbarian(" Barb of Team 1 "));

			team1->addFighter(new ReptilePeople(" Reptile of Team 1 "));

			team1->addFighter(new BlueMen(" Blu of Team 1 "));

			team1->addFighter(new TheShadow(" Shad of Team 1 "));

			team2->addFighter(new Goblin(" Gob of Team 2 "));

			team2->addFighter(new Barbarian(" Barb of Team 2 "));

			team2->addFighter(new ReptilePeople(" Reptile of Team 2 "));

			team2->addFighter(new BlueMen(" Blu of Team 2 "));

			team2->addFighter(new TheShadow(" Shad of Team 2 "));
		}

		else if(choice == "3")
            	{
			team1->addFighter(new Goblin(" Gob of Team 1 "));

                	team1->addFighter(new ReptilePeople(" Reptile of Team 1 "));

                	team1->addFighter(new Barbarian(" Barb of Team 1 "));

                	team1->addFighter(new TheShadow(" Shad of Team 1 "));

                	team1->addFighter(new BlueMen(" Blu of Team 1 "));

                	team2->addFighter(new BlueMen(" Blu of Team 2 "));

                	team2->addFighter(new Barbarian(" Barb of Team 2 "));

			team2->addFighter(new ReptilePeople(" Reptile of Team 2 "));

                	team2->addFighter(new TheShadow(" Shad of Team 2 "));

			team2->addFighter(new Goblin(" Gob of Team 2 "));
		}

		else
		{
			std::cout << "Please enter a valid choice.\n\n";
		}

		count = 0;

        	while(!team1->isEmpty() && !team2->isEmpty())
                {
			count++;

			std::cout << "******FIGHT#" << count << "******\n\n";

			life1 = 1; //Assign life to 1

                    	life2 = 1;

			while(life1 > 0 && life2 > 0)
    			{
				if((rand() % 1000 + 1) > 500)
        			{
					life1 = team1->getCreature()->fight(team2->getCreature());
				}

				else
        			{
            				life2 = team2->getCreature()->fight(team1->getCreature());
        			}

				system("sleep 1"); //To pause screen for 1 second
			}

			if(life1 <= 0)
                	{
				dead.push(team2->removeCreature());

                    		team1->setCreature();

                    		team1->setWin(1);
			}

			else if(life2 <= 0)
                	{
                            	dead.push(team1->removeCreature());

                    		team2->setCreature();

                    		team2->setWin(1);
			}
		}

		while(!team1->isEmpty())
			{
				results.push_back(team1->lastCreatures());
			}

		while(!team2->isEmpty())
			{
				results.push_back(team2->lastCreatures());
			}

		double team1Total, team2Total; //To get total scores for both teams

		team1Total = team1->getPoints() + team1->getWin(); //Team 1 overall

		team2Total = team2->getPoints() + team2->getWin(); //Team 2 overall

		//If team 1 won the tournament
		if(team1Total > team2Total)
		{


			std::cout << "Team1 won the match.\n\n";

			outFile << "Team1 won the match.\n\n";

			std::cout << "Team 1 Points :" << team1->getPoints() << "\n";

			outFile << "Team 1 Points :" << team1->getPoints() << "\n";

			std::cout << "Team 1 Wins   :" << team1->getWin() << "\n";

			outFile << "Team 1 Wins   :" << team1->getWin() << "\n";

			std::cout << "Team 1 overall:" << team1Total << "\n\n";

			outFile << "Team 1 overall:" << team1Total << "\n\n";

            		std::cout << "Team 2 Points :" << team2->getPoints() << "\n";

			outFile << "Team 2 Points :" << team2->getPoints() << "\n";

			std::cout << "Team 2 Wins   :" << team2->getWin() << "\n";

			outFile << "Team 2 Wins   :" << team2->getWin() << "\n";

			std::cout << "Team 2 overall:" << team2Total << "\n\n";

			outFile << "Team 2 overall:" << team2Total << "\n\n";
		}

                //If team 2 won the tournament
		else if(team2Total > team1Total)
                {


			std::cout << "Team2 won the match.\n\n";

			outFile << "Team2 won the match.\n\n";

			std::cout << "Team 2 Points :" << team2->getPoints() << "\n";

			outFile << "Team 2 Points :" << team2->getPoints() << "\n";

			std::cout << "Team 2 Wins   :" << team2->getWin() << "\n";

			outFile << "Team 2 Wins   :" << team2->getWin() << "\n";

			std::cout << "Team 2 overall:" << team2Total << "\n\n";

			outFile << "Team 2 overall:" << team2Total << "\n\n";

			std::cout << "Team 1 Points :" << team1->getPoints() << "\n";

			outFile << "Team 1 Points :" << team1->getPoints() << "\n";

			std::cout << "Team 1 Wins   :" << team1->getWin() << "\n";

			outFile << "Team 1 Wins   :" << team1->getWin() << "\n";

			std::cout << "Team 1 overall:" << team1Total << "\n\n";

			outFile << "Team 1 overall:" << team1Total << "\n\n";
		}

                //If tie
		else
                {
			std::cout << "No won the match.\n\n";

			outFile << "No won the match.\n\n";
                }

                while(!dead.empty())
                {
			temp = dead.top();

			results.push_back(temp);

			dead.pop();
		}

                sort(results.begin(), results.end(), Sort());

                //Tie Breaker
		if(results.size() >= 3)
		{
			if(results[0]->getOverall() == results[1]->getOverall())
			{
				if(results[1]->getOverall() == results[2]->getOverall())
				{
					std::cout << "There is tie for first 3 positions. We will use dice to select winner.\n\n";

					outFile << "There is tie for first 3 positions. We will use dice to select winner.\n\n";

					int tieBreaker = (rand() % 3) + 1;

					if(tieBreaker == 1)
					{
						results[0]->setOverall(0.2);

						results[1]->setOverall(0.1);
					}

					else if(tieBreaker == 2)
					{
						results[2]->setOverall(0.2);

						results[1]->setOverall(0.1);

						sort(results.begin(), results.end(), Sort()); //Sort the results on based on overall score
					}

					else if(tieBreaker == 3)
					{
						results[1]->setOverall(0.2);

						results[0]->setOverall(0.1);

						sort(results.begin(), results.end(), Sort()); //Sort the results on based on overall score
					}
				}

				else
				{
					std::cout << "There is tie for 1st and 2nd position. We will use dice to select winner.\n\n";

					outFile << "There is tie for 1st and 2nd position. We will use dice to select winner.\n\n";

					if(rand() % 2 == 0)
					{
						results[0]->setOverall(0.1);
					}

					else
					{
						results[1]->setOverall(0.1);

						sort(results.begin(), results.end(), Sort()); //Sort the results on based on overall score
					}
				}

			}

			else if(results[1]->getOverall() == results[2]->getOverall())
			{
				std::cout << "There is tie for 2nd and 3rd position. We will use dice to select winner.\n\n";

				outFile << "There is tie for 2nd and 3rd position. We will use dice to select winner.\n\n";

				if(rand() % 2 == 0)
				{
					results[1]->setOverall(0.1);
				}

				else
				{
					results[2]->setOverall(0.1);

					sort(results.begin(), results.end(), Sort()); //Sort the results on based on overall score
				}
			}
		}

                std::cout << "Fighters list with performance score.\n\n";

                for(unsigned int i =0; i < results.size(); i++)
                {
			std::cout << results[i]->getType() << " ";

		    	outFile << results[i]->getType() << " ";

                    	std::cout << results[i]->getName() << "\n";

		    	outFile << results[i]->getName() << "\n";

                    	std::cout << "Total fights  :" << results[i]->getTotalFights() << "\n";

		    	outFile << "Total fights  :" << results[i]->getTotalFights() << "\n";

		    	std::cout << "Total points  :" << results[i]->getPoints() << "\n";

		    	outFile << "Total points  :" << results[i]->getPoints() << "\n";

		    	std::cout << "Total wins    :" << results[i]->getWin() << "\n";

		    	outFile << "Total wins    :" << results[i]->getWin() << "\n";

		    	std::cout << "Overall points:" << results[i]->getOverall() << "\n\n";

		    	outFile << "Overall points:" << results[i]->getOverall() << "\n\n";

			/*if(i == 2)
			{
				break;
			}*/
		}

                for(unsigned int i =0; i < results.size(); i++)
                {
			delete results[i];
                }

                results.clear();

		delete team1;

		delete team2;

		//Asking Use if wants to test again
		do
		{
			std::cout << "Do you want to test again?\n";
    			std::cout << "Enter 'y' for yes and 'n' for no:";
			std::getline(std::cin, testAgain);

			if(testAgain == "y")
			{
				std::cout << "You choose to test again.\n\n";
				std::cout << "Previous test results are saved in file " << fileName << "\n\n";

				system("clear");
			}

			else if(testAgain == "n")
			{
				std::cout << "You choose to exit.\n\n";
				std::cout << "Results are saved in file " << fileName << "\n\n";
			}

			else
			{
				std::cout << "Please Enter y or n.\n\n";
			}
		}while(testAgain != "y" && testAgain != "n");

		outFile.close();  //Closing file

   }while(testAgain == "y");
}
