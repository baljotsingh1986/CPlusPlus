/***************************
 * Author: Baljot Singh
 * Date created:  11/6/2014
 * Program name: wordShift.cpp
 * Description: This program will take c-style string from and
 *              output the string by rearranging the characters of
 *              string according to command from user.
 * input: A c-style string and commands from user
 * Output:Shuffling the characters of string according to commands
 *        from user
 ****************************/

 #include <iostream>
 #include <cstring>   //for c-style string
 #include <string>
 #include <cstdlib>   //For atoi

 using namespace std;

 //function prototypes

 void getCommand(string &command, char &firstLetter, int &manipulator, char str1Array[]); //function prototype to get user command

 void shiftToLeft(char word1[], const int&, const int&); //function prototype for left shift

 void shiftToRight(char word1[], const int&, const int&); //function prototype for right shift

 void reverseString(char word1[], const int&); //function prototype for reversing the string

 //starting main function
 int main()
 {
	char str1[30]; //Declaring an array str1 as type char for user input of size 30

	int str1Length; //Declaring a variable as int to assign to length of string entered by user

	char first;   //char first to get first character of command

	string command; //A variable as type string to assign to user's command

	int shiftFactor; //A variable declared as int to assign to integer part of command

	//Asking user to input c-style string, which will be manipulated
	cout << "Please enter a word you want to manipulate. You can eneter various commands\n";
	cout << "to manipulate your word. You can right shift, left shift the characters in\n";
	cout << "your word and you can also reverse all characters.\n";
	cout << "You can enter maximum 29 characters.\n";
	cout <<	"Please enter your word: ";

	//User input for 29 characters string, 30 because last index will be used by '\0'
	cin.get(str1, 30);

	cout << endl;

	cin.clear();  //clear error bit

	//drop first 1000 characters up to and including
	//the first newline (up to length of current stream)
	cin.ignore( 1000, '\n' );

	str1Length = strlen(str1);   //Assigning string length
	
	cout << "Enter commands to manipulate the word you entered.\n";

	//Starting do-while loop
	do{
		//Calling a function which will get and validate user's command
		//and the variable are passed by reference from main function
		//to assign them corresponding values
		getCommand(command, first, shiftFactor, str1);

		//If length is 1, invalid command 
		if(command.length() == 1)
                {

			//Printing user the latest manipulated string
			cout << "Invalid command. No manipulation is done. "
			     << "Please enter valid command.\n";
			cout << "Your word is: " << str1 << endl << endl;
                }

		//if command is "rev"
		else if(command == "rev")
		{
			//Calling a function which reverses the string
			reverseString(str1, str1Length);

			//Printing the reversed string
			cout << "Now reversed. Your new word is: " << str1 << endl;
			cout << "Enter command again if you want to manipulate above word.\n\n";
		}

		//If command is Lx or lx
		else if(first == 'L')
		{
			//Calling a function which shifts the string to left
			shiftToLeft(str1, str1Length, shiftFactor);

			//Printing the left shifted string
			cout << "Now characters shifted to left by " << shiftFactor
			     << " spaces.\n";
			cout << "Your new word is: " << str1 << endl;
                 	cout << "Enter command again if you want to manipulate above word.\n\n";
		}

		//If command is Rx or rx
		else if(first == 'R')
		{
			//Calling a function which shifts the string to right
			shiftToRight(str1, str1Length, shiftFactor);

			//Printing the right shifted string
			cout << "Now characters shifted to right by " << shiftFactor
			     << " spaces.\n";
			cout << "Your new word is: " << str1 << endl;
                	cout << "Enter command again if you want to manipulate above word.\n\n";
		}
		
		//If command is "quit"
		else if(command == "quit")
		{
			cout << "You choose to exit. Exiting program.\n";
		}

		//If invalid command
		else
		{
			//Printing to user the latest manipulation to string
			cout << "Invalid command. No manipulation is done. "
			     << "Please enter valid command.\n";
			cout << "Your word is: " << str1 << endl << endl;

		}
	}while(command != "quit"); //Ending do while loop

 return 0;
 }

 //starting a function which takes user command and validates it and extract integer
 //part of it
 /******************************
 * Function: getCommand as void
 * Entry: It will take the addresses of char first, stringLength, shiftFactor string command
 *        to assign them values. It also takes string str1.
 * Exit: None
 * purpose: It validates the user command and extract integer part of it and assign values to
 *          to corresponding variables in main function
 ******************************/

 void getCommand(string &user_command, char &firstLetter, int &manipulator, char str1Array[])
 {
 	bool repeat; //Declaring a bool repeat to repeat again if command is not valid

	bool extractManipulator; //Declaring a bool to extract integer part if it is for shifting

	//Starting do while loop
	do
	{
 		repeat = false;  //Initializing bool repeat to false assuming user will enter valid command

		extractManipulator = false; //Initializing bool extractManipulator to false

		char temp[10] = ""; //Declaring an array type char to get integer part of command

		//Giving user instructions to enter command
		cout << "Enter Lx to shift the characters to left x spaces, where x is some integer.\n";
		cout << "Enter Rx to shift the characters to right x spaces, where x is some integer.\n";
		cout << "Enter rev to reverse your word.\n";
		cout << "Enter quit to exit.\n";
		cout << "Enter command: ";

		//Getting user input for command
		getline(cin, user_command);

		cout << endl;

		//Assigning first letter of command to char firsLetter, so char first in main function will have this letter
	 	firstLetter = user_command.at(0);

		//If command is "rev", no need to repeat
	 	if(user_command == "rev")
	 	{
		 	repeat = false;
	 	}

		//If command is "rev", no need to repeat
	 	else if(user_command == "quit")
	 	{
			repeat = false;
	 	}

		else
		{
		 	//For loop to check that after first letter other characters are integers
			for(unsigned int i = 1; i < user_command.length(); i++)
		 	{
				//If not digits
				if(!(isdigit(user_command.at(i))))
			 	{
					extractManipulator = false; //No need to extract integer part

					repeat = true;  //Invalid command repeat again

					cout << "Invalid command. No manipulation is done. "
					     << "Please enter valid command.\n";
						
					//Printing the string if after first alphabet all characters are not digits
					cout << "Your word is: " << str1Array << endl << endl;
					break;  //Break for loop
			 	}

				//If all are digits after first alphabet
			 	else
			 	{
					//Assign every digit to char temp
			 	    	temp[i - 1] = user_command.at(i);

					repeat = false;  //No repeat

					extractManipulator = true; //Need to extract integer part
				}
		 	}
	 	}

		//Extracting the integer part from command
		if(extractManipulator == true)
		{
			manipulator = atoi(temp); //Extracting integers from c-style string using atoi
		}
	}while(repeat == true); //Ending do-while loop
 }

 //starting function to reverse string
 /**************************
 * Function: reverseStrings
 * Entry: Address and length of char str1 from main function
 * Exit: None
 * Purpose: To reverse the character of user's string
 * ************************/

 void reverseString( char word1[], const int &stringLength)
 {
	int index; //Declaring a variable to index as int

	//for loop to get every character of array
	for (int i = 0; i < stringLength/2; i++)
	{
		index = stringLength - i - 1;    //Assigning index

		char temp = word1[i]; //Assigning char temp to ith element

		word1[i] = word1[index];  //Assigning ith element to element at index

		word1[index] = temp; //Assigning element at index to char temp
	}
 }

 //starting function to shift character to left
 /**************************
 * Function: shiftToLeft as void
 * Entry: Address and length of char str1 and shiftFactor from main function
 * Exit: None
 * Purpose: To shift the character of user's string to left
 * ************************/

 void shiftToLeft(char word1[], const int &wordLength, const int &leftShiftFactor)
 {
	//For loop to go through shift factor
 	for( int count = 0; count < leftShiftFactor; count++)
	{
		char first = word1[0];  //Declaring a char first and assign it to first element of string

		//For loop to shift the character one time
		for(int i = 0; i < wordLength - 1; i++)
	 	{
			word1[i] = word1[i + 1];    //Shifting characters one by one
		}

		word1[wordLength - 1] = first; //Assigning first character to last element
	}

 }

 //starting function to shift character to right
 /**************************
 * Function: shiftToRight as void
 * Entry: Address and length of char str1 and shiftFactor from main function
 * Exit: None
 * Purpose: To shift the character of user's string to right
 * ************************/

 void shiftToRight(char word1[], const int &wordLength, const int &rightShiftFactor)
 {
	 //For loop to go through shift factor
 	for( int count = 0; count < rightShiftFactor; count++)
	{
		char last = word1[wordLength - 1];  //Declaring a char last and assign it to last element of string

		//For loop to shift the character one time
		for(int i = wordLength - 1; i >= 1; i--)
	 	{
			word1[i] = word1[i - 1];    //Shifting characters one by one
		}

		word1[0] = last; //Assigning last character to first element
	}
 }



