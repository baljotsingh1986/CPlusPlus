/***************************
 * Author: Baljot Singh
 * Date created:  2/22/2015
 * Program name: main.cpp
 * Description: This program is a text based implementation of fantasy combat
 *              two player game. User can create two teams by choosing from 5
 *              characters and give them name. Output will tell top 3 performer
 *              and winner team.
 * input: Name of character, choice for character
 * Output:The output will tell which team won and top 3 performer.
 ****************************/

#include <iostream>
#include <string>
#include<stdio.h>
#include<cstdlib>
#include <stack>
#include <vector>
#include <algorithm>

//Headers for class
#include "Game.h"
#include "testCombat.h"

//Function prototype for input validation
int integer_validation();

//Class to help sort the results based on overall score for characters
class Sort
{
	public:
    		bool operator()(Creature *a, Creature *b)
		{
			return a->getOverall() > b->getOverall();
		}
};

//Starting main function
int main()
{
	srand(time(NULL));

	std::string test;

	//do while loop to ask user if wants to test tournament
	do
	{
		std::cout << "Do you want to test all sets of combat?\n";
		std::cout << "There will be 5 charaters in each team with different sets and result can be\nsaved to file\n";
    		std::cout << "Enter 'y' for yes and 'n' for no:";
		std::getline(std::cin, test);

		if(test == "y")
		{
			std::cout << "You choose to test.\n\n";
		}

		else if(test == "n")
		{
			std::cout << "You didn't choose to test.\n\n";
		}

		else
		{
			std::cout << "Please Enter y or n.\n\n";
		}
	}while(test != "y" && test != "n");

	//If user say yes
	if(test == "y")
	{
		testCombat();  //Function to test tournament
	}

	int fighters;  //To ask number of fighters

	std::string player; //To choose character type

    	double life1, life2; //Variable to assign to life of players

	std::string playAgain; //Variable to ask user play again

    	std::string name; //Name of character

    	std::stack<Creature*> dead; //Container for losers

    	std::vector<Creature*> results; //Container for all creatures to get results after tournament

    	Creature* temp; //A temp creature

	//Starting do-while loop
	do
	{
		Game *team1 = new Game; //Team 1

    		Game *team2 = new Game; //Team 2

		//Asking user for fighters in each team
		std::cout << "\nThis is two team fantasy combat game.\n\n"
                          << "How many players do you want in each team: ";

		fighters = integer_validation(); //Function for input validation

		int count = 0;

		//Asking Player 1 to add fighters in team 1
		std::cout << "Player 1 please add " << fighters << " fighters to your team.\n";

		//While count less than fighters
		while(count < fighters)
        	{
			count++; //Increment count

			//Asking player 1 to choose character

			std::cout << "\nPlayer 1 please add fighter#" << count << " to your team.\n\n";

			std::cout  << "You can choose from following characters by choosing number 1,2,3,4,5.\n"
              		           << "1.Goblin, is small but can cause severe damage to opponent.\n"
              	  	  	   << "2.Barbarian, is good at attack and defend.\n"
              		  	   << "3.Reptile People, are toughest one but slow. Very hard to beat\n"
              		  	   << "4.Blue Men, are efficient at attacking opponent.\n"
              		  	   << "5.The shadow, very good at defense, has special power to defend.\n\n";

			std::cout << "Player 1 enter your choice here:";

			std::getline(std::cin, player);

			std::cout << "\n";

			//If player is Goblin
			if(player == "1")
                	{
				std::cout << "Player 1 you choose Goblin.\n";
                    		std::cout << "Please give name you want to give to Goblin:";

				std::getline(std::cin, name);

				name = name + " of Team 1 ";  //To know the team of character

				team1->addFighter(new Goblin(name)); //Dynamically allocate particular character in this case Goblin
			       					     //call method to add character to team 1
			}

			//If player is Barbarian
                	else if(player == "2")
                	{
				std::cout << "Player 1 you choose Barbarian.\n";

                    		std::cout << "Please give name you want to give to Barbarian:";

				std::getline(std::cin, name);

				name = name + " of Team 1 ";

				team1->addFighter(new Barbarian(name));
			}

			//If player is Reptile People
                	else if(player == "3")
                	{
				std::cout << "Player 1 you choose Reptile People.\n";
				std::cout << "Please give name you want to give to Reptile People:";

				std::getline(std::cin, name);

				name = name + " of Team 1 ";

                 		team1->addFighter(new ReptilePeople(name));
			}

			//If player is Blue Men
                	else if(player == "4")
                	{
				std::cout << "Player 1 you choose Blue Men.\n";
				std::cout << "Please give name you want to give to Blue Men:";

				std::getline(std::cin, name);

				name = name + " of Team 1 ";

                    		team1->addFighter(new BlueMen(name));
			}

			//If player is shadow
                	else if(player == "5")
                	{
				std::cout << "Player 1 you choose The Shadow.\n";
				std::cout << "Please give name you want to give to The Shadow:";

				std::getline(std::cin, name);

				name = name + " of Team 1 ";

                    		team1->addFighter(new TheShadow(name));
			}

			else
            		{
                		std::cout << "Please choose correct number.\n\n";

				count--;
			}
		}

		count = 0;

		//Asking player 2 to choose character
       		std::cout << "\nPlayer 2 please add " << fighters << " fighters to your team.\n";

		//While count less than fighters
		while(count < fighters)
        	{
			//Asking player 2 to choose character

			count++; //Increment count

			std::cout << "\nPlayer 2 please add fighter#" << count << " to your team.\n\n";

			std::cout  << "You can choose from following characters by choosing number 1,2,3,4,5.\n"
              		  	   << "1.Goblin, is small but can cause severe damage to opponent.\n"
              	  	  	   << "2.Barbarian, is good at attack and defend.\n"
              		  	   << "3.Reptile People, are toughest one but slow. Very hard to beat\n"
              		  	   << "4.Blue Men, are efficient at attacking opponent.\n"
              		  	   << "5.The shadow, very good at defense, has special power to defend.\n\n";

            		std::cout << "Player 2 enter your choice here:";
			std::getline(std::cin, player);

			std::cout << "\n";

			//If player is Gobin
			if(player == "1")
                	{
				std::cout << "Player 2 you choose Goblin.\n";
                    		std::cout << "Please give name you want to give to Goblin:";

				std::getline(std::cin, name);

				name = name + " of Team 2 ";

				team2->addFighter(new Goblin(name));
			}

			//If player is Barbarian
                	else if(player == "2")
                	{
				std::cout << "Player 2 you choose Barbarian.\n";
				std::cout << "Please give name you want to give to Barbarian:";

				std::getline(std::cin, name);

				name = name + " of Team 2 ";

				team2->addFighter(new Barbarian(name));
			}


			//If player is Reptile People
                	else if(player == "3")
                	{
				std::cout << "Player 2 you choose Reptile People.\n";
				std::cout << "Please give name you want to give to Reptile People:";

				std::getline(std::cin, name);

				name = name + " of Team 2 ";

                    		team2->addFighter(new ReptilePeople(name));
			}

			//If player is Blue Men
                	else if(player == "4")
                	{
				std::cout << "Player 2 you choose Blue Men.\n";
				std::cout << "Please give name you want to give to Blue Men:";

				std::getline(std::cin, name);

				name = name + " of Team 2 ";

				team2->addFighter(new BlueMen(name));
			}

			//If player is shadow
                	else if(player == "5")
                	{
				std::cout << "Player 2 you choose The Shadow.\n";
				std::cout << "Please give name you want to give to The Shadow:";

				std::getline(std::cin, name);

				name = name + " of Team 2 ";

				team2->addFighter(new TheShadow(name));
			}

			else
            		{
                		std::cout << "Please choose correct number.\n\n";

				count--;
			}
		}

		count = 0; //Assign count tp 0

        	//While if any of team is not empty
		while(!team1->isEmpty() && !team2->isEmpty())
                {
			count++; //Increment count

                    	std::cout << "******FIGHT#" << count << "******\n\n";

			//Assign both life to 1

			life1 = 1;

                    	life2 = 1;

			//While any of character is alive
			while(life1 > 0 && life2 > 0)
    			{
				//Flip coin to fight

				if((rand() % 1000 + 1) > 500)
        			{
					//getCreature() method from Game class to get character from each team
					//Fight method from Creature class to engage fight between two characters
					//Team 1 character is attacking and team 2 character is defending
					life2 = team1->getCreature()->fight(team2->getCreature());
				}

				else
        			{
					//Team 2 character is attacking and team 1 character is defending
            				life1 = team2->getCreature()->fight(team1->getCreature());
        			}

				system("sleep 1"); //To pause screen for 1 second
			}

			//If team 2 character is dead
			if(life2 <= 0)
                	{
				dead.push(team2->removeCreature()); //Remove the character from team team2 and add to loser

                    		team1->setCreature(); //Shuffle character of team 1

                    		team1->setWin(1); //Increment team 1 win
			}

			//If team 1 character is dead
			else if(life1 <= 0)
                	{
                            	dead.push(team1->removeCreature()); //Remove the character from team team1 and add to loser

                    		team2->setCreature(); //Shuffle character of team 2

                    		team2->setWin(1); //Increment team 2 win
			}
		} //End while loop when one of team is dead

		//If characters are left in team 1
		while(!team1->isEmpty())
		{
			results.push_back(team1->lastCreatures()); //remove from team 1 and add to results
		}

		//If characters are left in team 2
		while(!team2->isEmpty())
		{
			results.push_back(team2->lastCreatures()); //remove from team 2 and add to results
		}

		double team1Total, team2Total; //To get total scores for both teams

		team1Total = team1->getPoints() + team1->getWin(); //Team 1 overall

		team2Total = team2->getPoints() + team2->getWin(); //Team 2 overall

		//If team 1 won the tournament
		if(team1Total > team2Total)
		{
			//Displaying results

			std::cout << "Team1 won the match.\n\n";

			std::cout << "Team 1 Points :" << team1->getPoints() << "\n";
			std::cout << "Team 1 Wins   :" << team1->getWin() << "\n";
			std::cout << "Team 1 overall:" << team1Total << "\n\n";

            		std::cout << "Team 2 Points :" << team2->getPoints() << "\n";
            		std::cout << "Team 2 Wins   :" << team2->getWin() << "\n";
            		std::cout << "Team 2 overall:" << team2Total << "\n\n";
		}

                //If team 2 won the tournament
		else if(team2->getWin() > team1->getWin())
                {
			std::cout << "Team2 won the match.\n\n";
			std::cout << "Team 1 Points :" << team1->getPoints() << "\n";
			std::cout << "Team 1 Wins   :" << team1->getWin() << "\n";
			std::cout << "Team 1 overall:" << team1->getPoints() + team1->getWin() << "\n\n";

            		std::cout << "Team 2 Points :" << team2->getPoints() << "\n";
            		std::cout << "Team 2 Wins   :" << team2->getWin() << "\n";
           		std::cout << "Team 2 overall:" << team2->getPoints() + team2->getWin() << "\n\n";
                }

                //If its a tie
		else
                {
			std::cout << "No won the match.\n\n";
                }

                //Add all dead characters to results
		while(!dead.empty())
                {
			temp = dead.top();

			results.push_back(temp);

			dead.pop();
                }

                sort(results.begin(), results.end(), Sort()); //Sort the results on based on overall score

		//Tie Breaker
		if(results.size() >= 3)
		{
			if(results[0]->getOverall() == results[1]->getOverall())
			{
				if(results[1]->getOverall() == results[2]->getOverall())
				{
					std::cout << "There is tie for first 3 positions. We will use dice to select winner.\n\n";

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

                std::cout << "Top three fighters.\n";

                //Display the top fighters
		for(unsigned int i =0; i < results.size(); i++)
                {
			std::cout << results[i]->getType() << " ";

			std::cout << results[i]->getName() << "\n";

                    	std::cout << "Total fights  :" << results[i]->getTotalFights() << "\n";

			std::cout << "Total points  :" << results[i]->getPoints() << "\n";

			std::cout << "Total wins    :" << results[i]->getWin() << "\n";

			std::cout << "Overall points:" << results[i]->getOverall() << "\n\n";

			if(i == 2)
			{
				break;
			}
		}

		//Delete dynamically allocated objects
		for(unsigned int i =0; i < results.size(); i++)
                {
			delete results[i];
                }

                results.clear(); //Clear results vector

		//Asking user to play again
		do
		{
			std::cout << "Do you want to play again?\n";
    			std::cout << "Enter 'y' for yes and 'n' for no:";
			std::getline(std::cin, playAgain);

			if(playAgain == "y")
			{
				std::cout << "You choose to play again.\n\n";

				system("clear");
			}

			else if(playAgain == "n")
			{
				std::cout << "You choose to exit.\n\n";
			}

			else
			{
				std::cout << "Please Enter y or n.\n\n";
			}

		}while(playAgain != "y" && playAgain != "n");

		delete team1; //Delete team 1
		delete team2; //delete team 2

	}while(playAgain == "y");

return 0;
} //End of main function

 //starting function to validate input data type
 /**************************
 * Function: integer_validation declared as int
 * Entry: none
 * Exit: Return the value of input from user after validating
 * Purpose: validate the input from user for integers
 * ************************/

 int integer_validation()
 {
	 int integer_validation; //declaring a variable as int to be validate

	//starting do while loop to check if input is not valid
	do
	{
		std::cin >> integer_validation;  //user input

	 	//while loop to check data type
	 	while(std::cin.get() != '\n')
	 	{
			std::cout << "The number you entered is "
		             <<  "not an integer.\n";
		 	std::cout << "Please enter a valid number again:";

                 	std::cin.clear();  //clear error bit

		 	//drop first 1000 characters up to and including
		 	//the first newline (up to length of current stream)
		 	std::cin.ignore( 1000, '\n' );

		 	std::cin >> integer_validation;
	 	}

		//if user input is negative or 0
		if (integer_validation <= 0)
		{
			std::cout << "The numbers for fighters should be greater than 0.\n"
                             << " Please enter again: ";
	       	}
	}while (integer_validation <= 0);

	std::cout << std::endl;

 return integer_validation; //return user input to main function after validation
 }
