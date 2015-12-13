/***************************
 * Author: Baljot Singh
 * Date created:  1/15/2015
 * Program name: gameOfLife.cpp
 * Description: This program is very simple implementation of c++ for game of life Conway.
 * 		The actual grid is 22 by 80 but for display to user the grid is 19 by 77.
 * 		This is because to consider edge condition and to disappear the live or dead cells
 * 		at edges like ghost.
 * input: Option for different pattern(simple oscillator, glider, Gosper's glider gun and user defined). Location
 * 	  where user wants to start a particular pattern.
 * Output:the output will show the particular pattern as selected by user
 ****************************/


#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>



const int ROW = 22; //Declaring number of rows as global constant

const int CLM = 80; //Declaring number of columns as global constant

//Function prototypes

void copyArray(int array1[ROW][CLM], int array2[ROW][CLM]); //Function prototype to copy one array to another

void nextGeneration(int nextGen[ROW][CLM]); //Function prototype to update next generation

void printGeneration(int lifeArray[ROW][CLM]); //Function prototype to display the generation

int inputX_validation(); //Function prototype for input validation for x-coordinate

int inputY_validation(); //Function prototype for input validation for y-coordinate

int inputGunY_validation(); //Function prototype for input validation for y-coordinate for glider gun

int inputGunX_validation(); //Function prototype for input validation for x-coordinate for glider gun

//Starting main function
int main()
{
	int startLife[ROW][CLM]; //Declaring an array for game of life grid

	int xCord, yCord; //Declaring two variable as int to get user input for location
			  //to start pattern

	char again; //If user wants to play game again with new pattern

	char select; //For user to give options which pattern user wants to add

	int numIteration; // To ask user how many evolution user wants to see

	std::string option; //To ask user if user wants to see preset patterns or make new pattern

	char contEvolution; //To ask user if wants continue evolution for same pattern

	int numEvolutions, count; //Variable to count number of generation

  	//Instruction for user
	std::cout << "\nJohn Conway's Game of Life.\n"
       	          << "The rules of the \"Game of Life\" are as follows:\n"
                  << "1.If a live cell has 0 or 1 neighbor. It dies of loneliness.\n"
                  << "2.If a live cell has more than 3 neighbor. It dies of overcrowding.\n"
                  << "3.If an empty cell has exactly 3 neighbor. Birth of new cell at empty space.\n"
		  << "Display board is of size 19 by 77. 'o' represents live cell and '.' represents dead cell.\n"
                  << "You will have option to start different patterns(fixed oscillator, glider and\n"
                  << "glider gun). You can also make your own configuration if you want.\n"
		  << "You can choose how many generations you want to run and if you want\n"
                  << "to continue same generation or start new pattern.\n\n";

	//do-while loop to ask user if user wants to play again.
	do
	{
		contEvolution = 'y';  //Initializing contEvolution as y

		numEvolutions = 0; //Initializing number of evolution as 0

		count = 0;  //Initializing count as 0

		//nested for loop to initialize all cells as dead
		for(int j = 0; j < ROW; j++)
        	{
			for (int i = 0; i < CLM; i++)
            		{
				startLife[j][i] = 0;
            		}
        	}

		//Asking user for option which pattern user wants to run
        	std::cout << "Please enter 1 if you want to run fix oscillator, glider and glider gun.\n"
			  << "Please enter 2 if you want to make your own configuration.\n";

		//Asking user to Enter option
		std::cout << "Enter your option:";
            	std::cin >> option;

		std::cout << "\n";

		//If Option 1 preset patterns
		if(option == "1")
            	{
			//Asking user if user wants to add fix osciillator also
			std::cout << "Do you want to add fix oscillator?\n";
			std::cout << "Please enter 'y' for yes or 'n' for no:";
			std::cin >> select;

			std::cout << "\n";

			if(select == 'y')
			{
				//Asking user for location to start
				std::cout << "Please enter location in form of coordinates where you want to start pattern for fix oscillator.\n";

				//User input for x-coordinate
				std::cout << "Please enter x-coordinate:";

				xCord = inputX_validation(); //Calling a function which validates x-coordinate

				//User input for y-coordinate
		        	std::cout << "Please enter y-coordinate:";

				yCord = inputY_validation(); //Calling a function which validates y-coordinate

				//Configuration for fix oscillator
				startLife[xCord + 1][yCord]=
				startLife[xCord + 1][yCord + 1]=
				startLife[xCord + 1][yCord + 2] = 1;

				std::cout << "\n";
			}

			//Asking user if user wants to add glider also
			std::cout << "Do you want to add glider?\n";
			std::cout << "Please enter 'y' for yes or 'n' for no:";
			std::cin >> select;

			std::cout << "\n";

			if(select == 'y')
			{
				//Asking user for location to start for glider
				std::cout << "Please enter location in form of coordinates where you want to start pattern for glider.\n";

				//User input for x-coordinate
				std::cout << "Please enter x-coordinate:";

				xCord = inputX_validation(); //Calling a function which validates x-coordinate

				//User input for y-coordinate
		        	std::cout << "Please enter y-coordinate:";

				yCord = inputY_validation(); //Calling a function which validates y-coordinate

				//Configuration for glider

				startLife[xCord + 1][yCord] =
		    		startLife[xCord + 2][yCord + 1] =
		    		startLife[xCord + 2][yCord + 2] =
		    		startLife[xCord + 1][yCord + 2] =
		    		startLife[xCord][yCord + 2] = 1;

				std::cout << "\n";
			}

			//Asking user if user wants to add glider gun also
			std::cout << "Do you want to add glider gun?\n";
			std::cout << "Please enter 'y' for yes or 'n' for no:";
			std::cin >> select;

			std::cout << "\n";

			if(select == 'y')
			{
				std::cout << "Please enter location in form of coordinates where you want to start pattern for glider gun.\n";

		    		std::cout << "Please enter x-coordinate:";

		    		xCord = inputGunX_validation(); //Calling a function to validate input for x-coordinate for glider gun

		    		std::cout << "Please enter y-coordinate:";

		    		yCord = inputGunY_validation();  //Calling a function to validate input for y-coordinate for glider gun

				//Configuration for Gosper's glider gun
		    		startLife[xCord + 5][yCord +1]=
		    		startLife[xCord + 5][yCord +2]=
		    		startLife[xCord + 6][yCord +1]=
		    		startLife[xCord + 6][yCord +2]=1;

		    		startLife[xCord + 3][yCord +35]=
		    		startLife[xCord + 3][yCord +36]=
		    		startLife[xCord + 4][yCord +35]=
		    		startLife[xCord + 4][yCord +36]=1;

		    		startLife[xCord + 3][yCord + 13]=
	            		startLife[xCord + 3][yCord + 14]=
		    		startLife[xCord + 4][yCord + 12]=
		    		startLife[xCord + 5][yCord + 11]=
		    		startLife[xCord + 6][yCord + 11]=
		    		startLife[xCord + 7][yCord + 11]=
		    		startLife[xCord + 8][yCord + 12]=
		    		startLife[xCord + 9][yCord + 13]=
		    		startLife[xCord + 9][yCord + 14]=1;

		    		startLife[xCord + 6][yCord + 15]=
		    		startLife[xCord + 4][yCord + 16]=
		    		startLife[xCord + 8][yCord + 16]=
		    		startLife[xCord + 5][yCord + 17]=
		    		startLife[xCord + 6][yCord + 17]=
		    		startLife[xCord + 7][yCord + 17]=
		    		startLife[xCord + 6][yCord + 18]=1;

		    		startLife[xCord + 3][yCord + 21]=
		    		startLife[xCord + 3][yCord + 22]=
		    		startLife[xCord + 4][yCord + 21]=
		    		startLife[xCord + 4][yCord + 22]=
		    		startLife[xCord + 5][yCord + 21]=
		    		startLife[xCord + 5][yCord + 22]=
		    		startLife[xCord + 2][yCord + 23]=
		    		startLife[xCord + 6][yCord + 23]=1;

		    		startLife[xCord + 1][yCord + 25]=
	            		startLife[xCord + 2][yCord + 25]=
		    		startLife[xCord + 6][yCord + 25]=
		    		startLife[xCord + 7][yCord + 25]= 1;

				std::cout << "\n";
			}

			//Asking user for number of generation
			std::cout << "How many generations you want to see? e.g. 12,25,100: ";
                	std::cin >> numIteration;

			system("clear"); //Clear screen

			//do-while loop to iterate over number of generation
			do
                	{
				std::cout << "\nGeneration " << numEvolutions + 1
                    			  << ":\n";

                    		printGeneration(startLife); //Calling function to display game of life

				nextGeneration(startLife); //Update next generation

				numEvolutions++; //Increment number of evolutions

				count++;   //Increment count

				system("sleep .5"); //To pause screen for 1/2 second
			 
			 if(numIteration != count)
			 {
				 system("clear");
			 }

			 //Asking user if wants to continue evolution
			 else
			 {
				 std::cout << "Do you want to continue evolution?\n";
				 std::cout << "Enter 'y' for yes or 'n' for no:";
				 std::cin >> contEvolution;

				 if(contEvolution == 'y')
				 {
					 std::cout << "How many more evolutions:";
		    			 std::cin >> numIteration;
					 
					 count = 0; //Assign count to 0

					 system("clear");
				 }
			  }

                	}while(contEvolution == 'y');
            }

	    //If Option 2 user defined
	    else if(option == "2")
	    {
		    int cellCount = 1;
		    char nextLiveCell;

		    do
		    {
			    //Asking user for location to start
			    std::cout << "Please enter location in form of coordinates where you want live cells.\n";

		    	    //User input for x-coordinate
		    	    std::cout << "Please enter x-coordinate for cell#" << cellCount << " :";

		            xCord = inputX_validation(); //Calling a function which validates x-coordinate

		            //User input for y-coordinate
		            std::cout << "Please enter y-coordinate for cell#" << cellCount << " :";

			    yCord = inputY_validation(); //Calling a function which validates y-coordinate

			    //Making location entered by user as live cell
		       	    startLife[xCord][yCord] = 1;

			    cellCount++;

			    std::cout << "\n";

			    std::cout << "Do you want make another cell alive?\n";
			    std::cout << "Enter 'y' for yes or 'n' for no:";
			    std::cin >> nextLiveCell;

			    std::cout << "\n";

		    }while(nextLiveCell == 'y');

		    //Asking user for number of generation
	            std::cout << "How many generations:";
                    std::cin >> numIteration;

		    system("clear"); //Clear screen

		    //do-while loop to iterate over number of generation
		    do
                    {
			    std::cout << "\nGeneration " << numEvolutions + 1
                    			  << ":\n";

			    printGeneration(startLife); //Calling function to display game of life

			    nextGeneration(startLife); //Update next generation

			    numEvolutions++; //Increment number of evolutions

			    count++;

			    system("sleep .5"); //To pause screen for 1/2 second

			    if(numIteration != count)
			    {
				    system("clear");
			    }

			    //Asking user if wants to continue evolution
			    else
			    {
				    std::cout << "Do you want to continue evolution?\n";
				    std::cout << "Enter 'y' for yes or 'n' no:";
				    std::cin >> contEvolution;

				    if(contEvolution == 'y')
				    {
					     std::cout << "How many more evolutions:";
		    			     std::cin >> numIteration;
					    
					     count = 0;

					     system("clear");
				    }
			    }
		    }while(contEvolution == 'y');
            }

	    //If invalid option
	    else
	    {
		    std::cout << "Please enter a valid option 1 or 2.\n\n";
	    }

	    std::cout << "\n";

	    //Asking user if wants to restart again or quit
	    std::cout << "Do you want to play again?\n";
	    std::cout << "Enter 'y' for yes or 'q' for quit:";
	    std::cin >> again;
	
	    std::cout << "\n";
	    
	}while(again == 'y');

return 0;
}

//starting function to copy arrays
/**************************
 * Function: copyArray as void
 * Entry: Passing 2 arrays from function nextGeneration
 * Exit: none
 * purpose: Copy elements of one 2d array to other
* ************************/

void copyArray(int array1[ROW][CLM], int array2[ROW][CLM])
{
	for(int i = 0; i < ROW; i++)
  	{
		for(int j = 0; j < CLM; j++)
		{
			array2[i][j] = array1[i][j];
		}
	}
}

//starting function to update generation
/**************************
 * Function: nextGeneration as void
 * Entry: Passing one 2d array from main function
 * Exit: none
 * purpose: To update next generation of game of life
* ************************/
void nextGeneration(int nextGen[ROW][CLM])
{
	int tempArray[ROW][CLM]; //Declaring a temp array

	copyArray(nextGen, tempArray); //Copy original array to temp array for backup

	//Nested for loop leaving the edges
	for(int j = 1; j < ROW - 1; j++)
 	{
		for(int i = 1; i < CLM - 1; i++)
		{
			int lifeCount = 0; //Initialize a variable to 0

		        //Counting all 8 neighbors of a cell for live cells
			lifeCount = nextGen[j-1][i] +  //Upper middle
				    nextGen[j-1][i-1] + //Upper left
				    nextGen[j][i-1] +   //Left
				    nextGen[j+1][i-1] + //Lower left
				    nextGen[j+1][i] +   //Lower middle
				    nextGen[j+1][i+1] + //Lower right
				    nextGen[j][i+1] +   //Right
				    nextGen[j-1][i+1];  //Upper right

			//If less than 2 or more than 3 neighbors alive
			if(lifeCount < 2 || lifeCount > 3)
			{
				tempArray[j][i] = 0;
			}

			//If exact 2 neighbors alive no change
			if(lifeCount == 2)
			{
				tempArray[j][i] = nextGen[j][i];
			}

			//If exact 3 neighbors alive either new cell born if empty space
			//or cell will stay alive
        		if(lifeCount == 3)
			{
				tempArray[j][i] = 1;
			}
		}
 	}

	//Copies the changes back to original array
	copyArray(tempArray, nextGen);
}


//starting function to print generation
/**************************
 * Function: printGeneration as void
 * Entry: Passing one 2d array from main function
 * Exit: none
 * purpose: To update print generation of game of life
* ************************/
void printGeneration(int lifeArray[ROW][CLM])
{
	//Nested for loop leaving 2 last rows and columns to make them ghosts
	for(int j = 1; j < ROW - 3; j++)
 	{
		for(int i = 1; i < CLM - 3; i++)
		{
			//If there is life
			if(lifeArray[j][i] == 1)
			{
				std::cout << 'o';
			}

			//Else
			else
			{
				std::cout << '.';
			}
		}
		std::cout << std::endl;
 	}
}

//starting function to validate input for x-coordinate
 /**************************
 * Function: inputX_validation declared as int
 * Entry: none
 * Exit: Return the value of input from user after validating
 * purpose: validate the input from user
 *****************************/

 int inputX_validation()
 {
 	int var_validation; //declaring a variable as int to be validate

	//do-while loop to check input is within array range
	do
	{
		std :: cin >> var_validation;  //user input

		//while loop to check data type
		while(std :: cin.get() != '\n')
       		{
			std :: cout << "The number you entered for is not valid. "
		     	            << "Please enter a valid number again:";

                	std :: cin.clear();  //clear error bit

			//drop first 1000 characters up to and including
			//the first newline (up to length of current stream)
			std :: cin.ignore( 1000, '\n' );

			std :: cin >> var_validation;
		}

		//If input is outside range of array
		if(var_validation <= 0 || var_validation >= 17)
		{
			std::cout << "The display is only 19 by 77. So for glider please enter x-coordinate from 1 to 16.\n";
			std::cout << "Please enter again:";
		}

	}while(var_validation <= 0 || var_validation >= 17);

 return var_validation;  //return user input to main function after validation
 }

//starting function to validate input for y-coordinate
 /**************************
 * Function: inputY_validation declared as int
 * Entry: none
 * Exit: Return the value of input from user after validating
 * purpose: validate the input from user
 *****************************/

 int inputY_validation()
 {
 	int var_validation; //declaring a variable as int to be validate

	//do-while loop to check input is within array range
	do
	{
		std :: cin >> var_validation;  //user input

		//while loop to check data type
		while(std :: cin.get() != '\n')
       		{
			std :: cout << "The number you entered for is not valid. "
		     	            << "Please enter a valid number again:";

                	std :: cin.clear();  //clear error bit

			//drop first 1000 characters up to and including
			//the first newline (up to length of current stream)
			std :: cin.ignore( 1000, '\n' );

			std :: cin >> var_validation;
		}

		//If input is outside range
		if(var_validation <= 0 || var_validation >= 75)
		{
			std::cout << "The display is only 19 by 77. So for glider please enter y-coordinate from 1 to 74.\n";
			std::cout << "Please enter again:";
		}

	}while(var_validation <= 0 || var_validation >= 75);

 return var_validation;  //return user input to main function after validation
 }

//starting function to validate input for x-coordinate for glider gun pattern
 /**************************
 * Function: inputGunX_validation declared as int
 * Entry: none
 * Exit: Return the value of input from user after validating
 * purpose: validate the input from user
 *****************************/

 int inputGunX_validation()
 {
 	int var_validation; //declaring a variable as int to be validate


	do
	{
		std :: cin >> var_validation;  //user input

		//while loop to check data type
		while(std :: cin.get() != '\n')
       		{
			std :: cout << "The number you entered for is not valid. "
		     	            << "Please enter a valid number again:";

                	std :: cin.clear();  //clear error bit

			//drop first 1000 characters up to and including
			//the first newline (up to length of current stream)
			std :: cin.ignore( 1000, '\n' );

			std :: cin >> var_validation;
		}

		if(var_validation <= 0 || var_validation >= 10)
		{
			std::cout << "The display is only 19 by 77. So for glider gun please enter x-coordinate from 1 to 9.\n";
			std::cout << "Please enter again:";
		}

	}while(var_validation <= 0 || var_validation >= 10);

 return var_validation;  //return user input to main function after validation
 }

//starting function to validate input for y-coordinate for glider gun pattern
 /**************************
 * Function: inputGunY_validation declared as int
 * Entry: none
 * Exit: Return the value of input from user after validating
 * purpose: validate the input from user
 *****************************/

 int inputGunY_validation()
 {
 	int var_validation; //declaring a variable as int to be validate


	do
	{
		std :: cin >> var_validation;  //user input

		//while loop to check data type
		while(std :: cin.get() != '\n')
       		{
			std :: cout << "The number you entered for is not valid. "
		     	            << "Please enter a valid number again:";

                	std :: cin.clear();  //clear error bit

			//drop first 1000 characters up to and including
			//the first newline (up to length of current stream)
			std :: cin.ignore( 1000, '\n' );

			std :: cin >> var_validation;
		}

		if(var_validation <= 0 || var_validation >= 41)
		{
			std::cout << "The display is only 19 by 77. So for glider gun please enter y-coordinate from 1 to 40.\n";
			std::cout << "Please enter again:";
		}

	}while(var_validation <= 0 || var_validation >= 41);

 return var_validation;  //return user input to main function after validation
 }
