/***************************
 * Author: Baljot Singh
 * Date created:  3/6/2015
 * Last Modified: 3/11/2015
 * Program name: main.cpp
 * Description: This program is a text based game in which player moves
 *              one place to other to achieve goal
 * input:Player name, choice of different worlds, input for next move of player
 * Output:Current status of player, If player completed the task or not
 ****************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

//Required header files.
#include "Rooms.h"
#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"
#include "Hero.h"
#include "double_validation.h"
#include "integer_validation.h"

//Function to get user input for next move
char getChoice()
{
	char choice;

	std::cout << "Please enter your choice for next move.\n"
              	  << "e to travel towards East.\n"
              	  << "w to travel towards West.\n"
              	  << "n to travel towards North.\n"
              	  << "s to travel towards South.\n"
              	  << "a to attack the opponent.\n"
              	  << "g to grab the item if it is available at current place.\n"
              	  << "Remember you can hold only limited number of items.\nLimit is only for weapons and armors."
		  << "Not for keys.\n\n"
              	  << "d to display the current items you have.\n"
              	  << "r to get rid of an item and leave at current place.\n"
              	  << "c to enter new world for a change.\n"
              	  << "q to quit and try next time\n\n";

	std::cout << "Enter your choice  here:";

	std::cin >> choice;

	std::cin.clear();

	std::cin.ignore(1000, '\n');

	return choice;
}

//Function to start game loop
void gameLoop(Rooms *world, Creature *player, bool &isGame, char &option, const std::chrono::system_clock::time_point &check, const double &time)
{
	int itemNum;

	char removeItem;

	//Do while loop till game continues for world
	do
	{
	   	auto end = std::chrono::system_clock::now(); //end clock

		double duration = std::chrono::duration_cast<std::chrono::seconds>(end - check).count();

		//Check for time
	    	if(duration > time)
        	{
            		std::cout << "Time up. Try next time.\n\n";

            		isGame = true;

            		break;
        	}

        	else
        	{
            		double timer = time - duration;

            		std::cout << "Time Left: " << timer/60 << " minutes.\n\n";
        	}
		
		//Display current status
		std::cout << world->getCurrentInfo() << "\n";

		option = getChoice();

		system("clear");

		//If choice for move or attack or grab some item
		if(option == 'e' || option == 'w' || option == 'n' || option == 's' || option == 'a' || option == 'g')
                {
			isGame = world->startGame(option, player);
		}

		//If user wants to know what user have
                else if(option == 'd')
                {
			player->displayItems();
                }

		//If user wants to remove some item
                else if (option == 'r')
                {
		   	//If payer has no weapon or armor
		   	if(player->getItemNum() == 0)
			{
			   	std::cout << "You don't have any armor or weapon to remove.\n\n";
			}

			//If the Item points to NULL in that location
			//The item can not be left at that location
			//The item will disappear forever
			else if(!world->checkItemHold())
                        {
				//Asking user if user wants to remove item
				std::cout << "This place is full of thieves. This item will vanished,\n"
                                      	  << "if you leave it here.\n\n";

				std::cout << "Do you still want to leave this item here.\n";

				std::cout << "Enter y for yes and n for no:";

				std::cin >> removeItem;

                            	std::cin.clear();

                            	std::cin.ignore(1000, '\n');

                            	if(removeItem == 'y')
                            	{
                                	player->displayItems();

					std::cout << "Please choose the item# you want to leave.\n"
                                		  
                                                  << "Enter item no.(e.g. 1,2,3 as integer) here:";

                               		itemNum = integer_validation(); //Function call to validate input

					//If user enters an invalid number
					if(itemNum > player->getItemNum() || itemNum <= 0)
                                	{
                                    		std::cout << "You don't have any weapon or armor of this number.\n\n";
					}

                                	//Else remove that item
					else
                                	{
                                    		player->removeItem(itemNum);
                                	}
				}

				//If user said not to remove
                            	else
				{
					std::cout << "Looks like a wise decision.\n\n";
				}
			}

			//If Item is not Null for that room
                        else
                        {
				//If there is already an item
				if(world->itemAvailable())
                            	{
					std::cout << "There is some item available here. If you leave your item here\n"
                                                  << "one of them will be vanished.\n";
                            		std::cout << "Do you still want to leave this item here.\n";
                            		std::cout << "Enter y for yes and n for no:";

					std::cin >> removeItem;

                            		std::cin.clear();

                            		std::cin.ignore(1000, '\n');

                            		if(removeItem == 'y')
                            		{
                                		player->displayItems();
                                		std::cout << "Please choose the item# you want to leave.\n\n"
                                			  << "Enter item no.(e.g. 1,2,3 as integer) here:";

						itemNum = integer_validation(); //Function call to validate input

						if(itemNum > player->getItemNum() || itemNum <= 0)
                                		{
                                    			std::cout << "You don't have any weapon or armor of this number.\n\n";
                                		}

                                		else
                                		{
                                    			player->removeItem(itemNum);
                                		}
					}

					else
                            		{
						std::cout << "Looks like a wise decision.\n\n";
					}
				}

				//If item is taken already
				else
				{
					player->displayItems();
                                	std::cout << "Please choose the item# you want to leave. Remember you can collect\n"
                                		  << "it again from the same place if you will need it.\n\n"
                                	          << "Enter item no.(e.g. 1,2,3 as integer) here:";

					itemNum = integer_validation(); //Function call to validate input;

					if(itemNum > player->getItemNum() || itemNum <= 0)
                                	{
                                    		std::cout << "You don't have any weapon or armor of this number.\n\n";
                                	}

                                	else
                                	{
                                    		world->placeItem(player->returnItem(itemNum));
                                	}
				}
			}
		}

		//If wants to change the world
                else if (option == 'c')
                {
			 break;
		}

             	//If user wants to quit
		else if (option == 'q')
                {
			std::cout << "You choose to quit the game. Try again.\n\n";
                        break;
		}

		//If invalid option
                else
                {
			std::cout << "Please enter a valid choice.\n\n";
                }
	}while(!isGame);
}

//Starting main function
int main()
{
	char input; //Variable to ask user to choose between worlds

    	bool gameEnd; //To check game loop if game is ended

    	char choice, timerChoice; //Player's next move and choice for time

    	std::string name; //Name of player

    	double timeNeed; //To get user input for timer

	char playAgain; //To ask user to play again

	//Do while loop if user wants to play again
	do
	{
		gameEnd = false; //Game end false

		//Create three different worlds having 10 rooms each

		Rooms *worldOne = new LevelOne();

    		Rooms *worldTwo = new LevelTwo();

    		Rooms *worldThree = new LevelThree();

    		worldOne->linkRooms();

    		worldTwo->linkRooms();

    		worldThree->linkRooms();

 		std::cout << "This is one player adventurous game. Player will move from one\n"
           		  << "place to other find an exit and collecting items which can be herbs\n"
           		  << "for healing, armor, weapons and 12 keys for exit. But to collect items\nand find exit "
           		  << "sometimes player has to fight with hidden bloody monster,\nif it is present "
           		  << "with player at same place. Game has three worlds,\nkeys can be anywhere in 3 worlds "
            		  << "You can switch between worlds any time, like a\nMATRIX.You might get trapped in time."
                          << "Just kidding it is not that hard. "
                          << "There is timer for game.\nYou will be asked for time you want to complete the game.\n"
                  	  << "If you don't choose to select your own time, default timer is to set 15 minutes.\n\n";

		std::cout << "Give name to your player:";

           	std::getline(std::cin, name);

           	std::cout << "\n";
	
		//If user wants to set own timer or not
        	std::cout << "Do you want to set time? Enter y for yes n for no:";

        	std::cin >> timerChoice;

        	std::cin.clear();

		std::cin.ignore(1000, '\n');

        	if(timerChoice == 'y')
        	{
            		std::cout << "How much time do you need? Enter in minutes:";

            		timeNeed = double_validation(); //Function call to validate user input

            		timeNeed *= 60;
        	}

        	else
        	{
            		timeNeed = 900;
		}

		Creature *fighter = new Hero(name); //A new Hero

           	auto start = std::chrono::system_clock::now(); //Start clock

		//Do while loop if user wants to switch between worlds and game not ended yet
   		do
		{
			//Asking user to choose between different worlds
            		std::cout << "Please choose a world to enter.\n"
                      	          << "Enter 1 for an abandoned dark town.\n"
                      		  << "Enter 2 for a dark jungle.\n"
                      	          << "Enter 3 for a mysterious magical world\n\n"
                      	          << "Enter your choice:";

			std::cin >> input;

            		std::cin.clear();

			std::cin.ignore(1000, '\n');

			//If choice is one World one
			if(input == '1')
            		{
				//Display world info
                		worldOne->worldInfo();

				gameLoop(worldOne, fighter, gameEnd, choice, start, timeNeed);
			}

			else if(input == '2')
            		{
		    		worldTwo->worldInfo();

		    		gameLoop(worldTwo, fighter, gameEnd, choice, start, timeNeed);
			}

            		else if(input == '3')
            		{
                		worldThree->worldInfo();

				gameLoop(worldThree, fighter, gameEnd, choice, start, timeNeed);
			}

			else
			{
                		std::cout << "Enter a valid option to choose world.\n\n";
            		}
		}while(choice != 'q' && gameEnd == false);

		delete worldOne;

		delete worldTwo;

		delete worldThree;

		delete fighter;

		//Asking user to play again
		do
		{
			std::cout << "Do you want to play again?\n";
    			std::cout << "Enter 'y' for yes and 'n' for no:";

			std::cin >> playAgain;

            		std::cin.clear();

			std::cin.ignore(1000, '\n');

			if(playAgain == 'y')
			{
				std::cout << "You choose to play again.\n\n";

				system("clear");
			}

			else if(playAgain == 'n')
			{
				std::cout << "You choose to exit.\n\n";
			}

			else
			{
				std::cout << "Please Enter y or n.\n\n";
			}

		}while(playAgain != 'y' && playAgain != 'n');

	}while(playAgain == 'y');

return 0;
}
