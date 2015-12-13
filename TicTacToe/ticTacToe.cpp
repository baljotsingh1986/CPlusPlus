/************************
 * Author: Baljot Singh
 * Date created:  11/15/2014
 * Program name: ticTacToe.cpp
 * Description: This program is a tic-tac-toe game. Both players will choose
 *              their position turn by turn. At the end program will tell whether somebody
 *              won or it was a tie. This program will take command line argument for number
 *              of times players wants to play the game.
 * input: Position input and command line argument
 * Output: Program will print if any player one or it was a tie
 ****************************/

 #include <iostream>
 #include <cstdlib>
 #include <cstring>

 using namespace std;

 //function prototypes

  void gameStart( char arr_tictac[][3], int & player0WinTotal, int &playerXWinTotal, char turn); //function prototype for playing game

 void row_array(int arr[]); //function prototype to get and validate input for position

 void printBoard(char arr[][3]); //function prototype to print board

 bool isPlayer0Win(char arr0_win[][3]); //function prototype to check if player 0 won

 bool isPlayerXWin(char arrX_win[][3]); //function prototype to check if player 0 won

 bool isGameOver(char arr_game_over[][3]); //function prototype to check if all position are filled

 //starting main function
 int main(int argc, char *argv[])
 {
	char arr[3][3]; //Declaring a 2d array as type char of size 3 by 3 for board

	int Win0Total = 0; //Declaring a variable as int to get player 0 total wins

	int WinXTotal = 0; //Declaring a variable as int to get player 0 total wins

	char start = '1'; //Declaring a variable as char to decide turn of players

	int playTimes;   //Declaring a variable to assign to command line input

	int totalGames = 0; //Declaring a variable to count total games played

	bool extractInteger = false; //variable bool If command argument argument is valid 

	char temp; //Char temp to keep track of players turn

	//Giving players instruction
	cout << "This is 2 players tic tac toe game. One player will be player X and other will\n";
	cout <<	"be player 0. Each player will be asked for position in board on player's turn\n";
	cout << "e.g. if player X enters 0 0 the first position will be replaced be x.\n";
	cout << "If player 0 enters 0 1 the second position in first row will be replaced\n";
	cout <<	"by 0 and so on. You can also give command line argument if you want to play\n";
	cout << "more than 1 game e.g. if you give './ticTacToe 4' you can play 4 games.\n\n";
	
	//If there is command line argument
	if(argc == 2)
    	{
	   	//for loop to check if the command line is valid 
		for(int j = 0; argv[1][j] != '\0'; j++)
        	{
		   	//if not digit exit the program and ask to re-run
			if(!(isdigit(argv[1][j])))
            		{
				cout << "The command is given in command line is not correct.\n";
                		cout << "Please enter only one integer in command without any spaces\n";
                		cout << "Please re-run the program\n";
                		exit(0);
            		}
			
			//Extract integer
			else
            		{
                		extractInteger = true;
            		}
        	}
    	}
    	
	//Extract integer
	if(extractInteger == true)
    	{
		playTimes = atoi(argv[1]); //converting user command to integer
		
		//If command line argument is 0
		if (playTimes <= 0)
		{
   		   cout << "You chose to play  " << playTimes << " game. Either you have entered\n";
		   cout << "0 or very big number in command line argument. Exiting the program.\n";
		   exit(0); 
        	}
		
		cout << "You chose to play series of " << playTimes << " games.\n\n";	
		
		//Starting do-while loop to play the games numbers of times user chose
		do
        	{
			temp = start; //Assigning temp to start
			
			totalGames++; //Increment game total
            		
			//Making board
            		for ( int i = 0; i < 3; i++)
            		{
				for (int j = 0; j < 3; j++)
                		{
					arr[i][j] = '.';
                		}
            		}	

            		//Calling a function which prints the board
            		printBoard(arr);

            		//Calling a function to start game
            		gameStart( arr, Win0Total, WinXTotal, start);
			
			//Swaping players turn 
            		if(temp == '1')
            		{
                		start = '2';
            		}

            		if(temp == '2')
            		{
                		start = '1';
            		}
			
			if(totalGames <  playTimes)
			{
				cout << "Restarting new game.\n\n";	
			}

		}while(totalGames < playTimes);//Endind do-whilr loop 
		
		//Printing result to user
   		if(Win0Total == WinXTotal)
		{
			cout << "It was a tie. Player 0 won " << Win0Total << " and\n";
			cout << "player X won " << WinXTotal << " out of total " << totalGames
		     	     << " games\n";
		}
		
		else if(Win0Total > WinXTotal)
		{
			cout << "Player 0 won the series. Player 0 won " << Win0Total << " and\n";
			cout << "player X won " << WinXTotal << " out of total " << totalGames
		             << " games\n";
		}	

		else if(Win0Total < WinXTotal)
		{
			cout << "Player X won the series. Player 0 won " << Win0Total << " and\n";
			cout << "player X won " << WinXTotal << " out of total " << totalGames
		             << " games\n";
		}
    	}
	
	//If number of command arguments more than two exit the program after flaging it 
    	else if(argc > 2)
    	{
        	cout << "Please enter only one command argument.\n";
        	cout << "Please re-run the program.\n";
        	exit(0);
    	}
	
	//If no command argument
    	else
    	{
        	cout << "You chose to play only one game.\n\n";
    		//Making board
		for ( int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
    			{
				arr[i][j] = '.';
        		}
		}

		//Calling a function which prints the board
		printBoard(arr);

		//Calling a function to start game
		gameStart( arr, Win0Total, WinXTotal, start);
	}

 return 0;
 }

 //starting function to play game
 /**************************
 * Function: gameStart declared as void
 * Entry: Address of array from main function
 * Exit: None
 * Purpose: To play game between 2 players turn by turn and give
 *          results at the end
 * ************************/

 void gameStart( char arr_tictac[][3], int & player0WinTotal, int &playerXWinTotal, char turn)
 {
	int inputArray [4]; //Declaring an array as int to get user input for position

	int row, column; //Declaring to variables as int to assign user input for position

	char gameFinished = 'N'; //Declaring and initializing a variable to know game is over or not

	//Starting do-while until the game is not over
	do
	{
		//If game is not over
		if(gameFinished == 'N')
		{
			//if turn = 1. Its player X turn
			if (turn == '1')
			{
				turn = '2'; //Assigning turn to 2

				//Asking player X for input
				cout << "Player X. Its your turn now. "
				     << "Give your input.\n";

				//Starting do-while loop to tell player if position is already filled
				do
				{
					row_array(inputArray); //Calling a function to get players input

					row = inputArray[0];  //Assigning first input to row

					column = inputArray[1]; //Assigning second position to column

					//If the position user selects not filled
					if(arr_tictac[row][column] == '.')
					{
						arr_tictac[row][column] = 'x'; //Assign that position to x

						printBoard(arr_tictac); //Function to print board

						isPlayerXWin(arr_tictac); //Function to check if player X has won

						isGameOver(arr_tictac); //Function to check if game is over

						break; //Break do-while loop
					}

					//If position chosen is already filled
					else
					{
						printBoard(arr_tictac);
						cout << "This position is already filled. Please choose another.\n\n";
					}

				}
				while(arr_tictac[row][column] != '.'); //Ending do-while if the position choose is not filled

				//If player X has won the game
				if(isPlayerXWin(arr_tictac))
				{
					gameFinished = 'Y'; //Game finished yes

					playerXWinTotal++; //Increment the total games player X won

					cout << "Player X has won the game.\n\n";
				}

				//Otherwise if all positions are filled game over
				else if(isGameOver(arr_tictac))
				{
					gameFinished = 'Y'; //Game over yes
					cout << "Game is over. It is tie.\n\n";
				}
			}
		}

		//If game is not over
		if(gameFinished == 'N')
		{
			//if turn = 2. Its player 0 turn
			if (turn == '2')
			{
				turn = '1'; //Assigning turn to 2

				//Asking player X for input
				cout << "Player 0. Its your turn now. "
				     << "Give your input.\n";

				//Starting do-while loop to tell player if position is already filled
				do
				{
					row_array(inputArray);//Calling a function to get players input

					row = inputArray[0];  //Assigning first input to row

					column = inputArray[1]; //Assigning second input to column

					//If the position user selects not filled
					if(arr_tictac[row][column] == '.')
					{
						arr_tictac[row][column] = '0'; //Assign that position to x

						printBoard(arr_tictac); //Calling function to print board

						isPlayer0Win(arr_tictac); //Calling function to check if player 0 has won

						isGameOver(arr_tictac); //Calling function to check if game is over

						break; //break do-while loop
					}

					//If the position is already filled
					else
					{
						printBoard(arr_tictac);
						cout << "This position is already filled. Please choose another.\n\n";
					}
				}
				while(arr_tictac[row][column] != '.'); //Ending do-while if the position choose is not filled

				//If player 0 has won the game
				if(isPlayer0Win(arr_tictac))
				{
					gameFinished = 'Y'; //Game finished yes

					player0WinTotal++; //Increment total wins for player 0
					cout << "Player 0 has won the game.\n\n";
				}

				//Otherwise if game is over
				else if(isGameOver(arr_tictac))
				{
					gameFinished = 'Y'; //Game finished yes

					cout << "Game is over.\n\n";
				}
			}
		}
	}while(gameFinished == 'N'); //End do-while loop when game is finished
 }

 //starting function to get user input
 /**************************
 * Function: row_array declared as void
 * Entry: Address of array from gameStart function
 * Exit: None
 * Purpose: To get user input for integers in single row separated by whitespaces
 *          and validate it.
 * ************************/

 void row_array(int arr[])
 {
	 bool printError; //A bool variable if there is error in input

	 bool repeat; //Declaring a variable repeat as bool

	 //Starting do-while loop till input is not correct
	 do
    	 {
		char cordinateInput[10] = ""; //Declaring a char array to get user input

		int elementCount = 0; //Declaring to count how many integers in input

		repeat = false; //Assigning repeat to false assuming input will be correct

		printError = false; //Assigning to false assuming input will be correct

		int digits = 0; //Declaring and initializing a variable as int

		int element; //Declaring a variable as int to extract integers from input

		int index = 0; //Declaring a variable as int

		char temp[3] = ""; //Declaring and initializing a char array to get integer part from input

		cin.getline(cordinateInput, 9); //Getting user input
		cout << endl;

		//For loop to go through all row of user input
		for (unsigned int k = 0;k < strlen(cordinateInput); k++ )
    		{
			//If space continue do nothing
			if(isspace(cordinateInput[k]))
	    		{
		    		continue;
	    		}

			//If not digit print error message and break for loop
			if(!isdigit(cordinateInput[k]))
	    		{
		    		printError = true;
                   		break;
	    		}

	    		if(isdigit(cordinateInput[k]))
	    		{
		    		temp[digits] = cordinateInput[k]; //Assing digits to char temp

				digits++; //Increment the digits

				//If after digit there is space or end of row input
				if(cordinateInput[k + 1] == ' ' || cordinateInput[k+1] == '\0' )
                    		{
					elementCount++; //increment elementcount to track number of input in user's input

					element = atoi(temp); //Convert that digits to integers

					arr[index] = element; //Assign element to integer array

					index++; //increment index

					//Empty the temp char to get next integer in row
			    		for(unsigned int i = 0; i < strlen(temp); i++)
			    		{
						temp[i] = ' ';
			    		}
			    			digits = 0; //Assign digits to 0
				}
			}

			//If any part of the user input less than 0 or greater than 2
			if(element < 0 || element > 2)
            		{
                		printError = true;
                		break;
			}
		} //Ending for loop

		//If number of integers in user input is not 2 or printError is true
		if(elementCount != 2 || printError == true)
                {
                    cout << "Please enter integers only separated by white spaces.\n";
                    cout << "Please enter 0, 1 and 2 only e.g. 0 0, 0 1 or 1 2.\n\n";
                    cout << "You can enter 2 integers only at a time.\n";
                    cout <<  "Enter your position again: ";

		    repeat = true;
                }
	 }while(repeat == true); //Ending do-while loop
 }//Ending Function


 //starting function to print array of tic-tac-toe
 /**************************
 * Function: printBoars declared as void
 * Entry: Address of array from gameStart function
 * Exit: None
 * Purpose: To print array of tic-tac-toe
 * ************************/

 void printBoard(char arr[][3])
 {
	//Nested for loops to print array
	cout << "  0 1 2" << endl;
    	for ( int i = 0; i < 3; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 3; j++)
    		{
			cout << arr[i][j] << " ";
        	}
        	cout << endl;
	}
 }

 //starting function to check if player 0 has won
 /**************************
 * Function: isPlayer0Win declared as bool
 * Entry: Address of array from gameStart function
 * Exit: Return true if player 0 has won otherwise false
 * Purpose: To check if player 0 has won
 * ************************/

 bool isPlayer0Win(char arr0_win[][3])
 {
    	 int diagonalIndex = 0; //Declaring and initializing a variable as int to get diagonal index
	 
	 string string0Win = ""; //Declaring and initializing a string

	 //For loop to add first major diagonal
	 for( int i = 0; i < 3; i++)
	 {
		 string0Win += arr0_win[i][i];
	 }

	 //If all the elements are 0
	 if(string0Win == "000")
	 {
		 return true; //return true player 0 has won
	 }

	 //otherwise for loop to add second major diagonal
	 else
	 {
		 string0Win = ""; //Initialize string as empty

		 for( int i = 2; i >= 0; i--)
    		 {
			 string0Win += arr0_win[diagonalIndex][i];
			 diagonalIndex++;
    		 }

		 //If all the elements are 0
		 if(string0Win == "000")
	 	 {
			 return true; //return true player 0 has won
	 	 }
	 }

	 //otherwise nested for loops to add rows one by one
	 if(string0Win != "000")
	 {
		 for( int i = 0; i < 3; i++)
        	 {
			 string0Win = "";

            	 	 for (int j = 0; j < 3; j++)
            		 {
				 string0Win += arr0_win[i][j];
			 }

			 //If any row has all 0
            		 if(string0Win == "000")
            		 {
               			 return true; //return true player 0 has won
                		 break; //break for loop
           		 }
        	}
    	}

	//otherwise nested for loops to add columns one by one
	if(string0Win != "000")
    	{
		for( int i = 0; i < 3; i++)
        	{
			string0Win = "";

			for (int j = 0; j < 3; j++)
            		{
				string0Win += arr0_win[j][i];
          		}

			//If any column has all 0
			if(string0Win == "000")
			{
				return true; //return true player 0 has won
                		break; //break for loop
            		}
        	}
	}

	//At last if not three 0 in columns rows or diagonals
	if(string0Win != "000")
    	{
        	return false; //return false player 0 has not won yet
	}
 } //Ending player0Win function

 //starting function to check if player X has won
 /**************************
 * Function: isPlayerXWin declared as bool
 * Entry: Address of array from gameStart function
 * Exit: Return true if player X has won otherwise false
 * Purpose: To check if player X has won
 * ************************/

 bool isPlayerXWin(char arrX_win[][3])
 {
    	 int diagonalIndex = 0; //Initializing variable as int 

	 string stringXWin = ""; //Declaring and initializing a string

	 //For loop to add first major diagonal
	 for( int i = 0; i < 3; i++)
	 {
		 stringXWin += arrX_win[i][i];
	 }

	 //If all the elements are x
	 if(stringXWin == "xxx")
	 {
		 return true; //return true player x has won
	 }

	 //otherwise for loop to add second major diagonal
	 else
	 {
		 stringXWin = ""; //Initialize string as empty

		 for( int i = 2; i >= 0; i--)
    		 {
			 stringXWin += arrX_win[diagonalIndex][i];
			 diagonalIndex++;
    		 }

		 //If all the elements are x
		 if(stringXWin == "xxx")
	 	 {
			 return true; //return true player x has won
	 	 }
	 }

	 //otherwise nested for loops to add rows one by one
	 if(stringXWin != "xxx")
	 {
		 for( int i = 0; i < 3; i++)
        	 {
			 stringXWin = "";

            	 	 for (int j = 0; j < 3; j++)
            		 {
				 stringXWin += arrX_win[i][j];
			 }

			 //If any row has all x
            		 if(stringXWin == "xxx")
            		 {
               			 return true; //return true player x has won
                		 break; //break for loop
           		 }
        	}
    	}

	//otherwise nested for loops to add columns one by one
	if(stringXWin != "xxx")
    	{
		for( int i = 0; i < 3; i++)
        	{
			stringXWin = "";

			for (int j = 0; j < 3; j++)
            		{
				stringXWin += arrX_win[j][i];
          		}

			//If any column has all x
			if(stringXWin == "xxx")
			{
				return true; //return true player x has won
                		break; //break for loop
            		}
        	}
	}

	//At last if not three x in any straight line for columns, rows or diagonals
	if(stringXWin != "xxx")
    	{
        	return false; //return false player x has not won yet
	}
 } //Ending playerXWin function

 //starting function to check if game is over
 /**************************
 * Function: isGameOver declared as bool
 * Entry: Address of array from gameStart function
 * Exit: Return true if all board is filled
 * Purpose: To check if all postions are filled with x or 0
 *          and return true that game is over
 * ************************/

 bool isGameOver(char arr_game_over[][3])
 {
	 bool gameOver = true; //Declaring and initializing a bool

	 //nested for loops to check every element in array
	 for( int i = 0; i < 3; i++)
	 {
		 for (int j = 0; j < 3; j++)
            	 {
			 //If any space not filled
			 if(arr_game_over[i][j] == '.')
			 {
				 gameOver = false; //game is not over
                		 break; //break for loop
           		 }
		 }
	 }

	 //if game is not over return false
	 if(gameOver == false)
	 {
		 return false;
	 }

	 //otherwise return true
	 else
	 {
		 return true;
	 }
 }

