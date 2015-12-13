/***************************
 * Author: Baljot Singh
 * Date created:  11/5/2014
 * Program name: stringMix.cpp
 * Description: This program will take c-style string from and
 *              output the string by rearranging the characters of
 *              string.
 * input: A c-style string
 * Output:Same string after randomly rearranging the characters
 ****************************/

 #include <iostream>
 #include <cstring>   //for c-style string
 #include <ctime>     //for time function
 #include <cstdlib>   //for random number function

 using namespace std;

 //function prototypes
 void swapStrings(char word1[], char word2[], int); //function prototype for rearranging the characters

 void rand_int (int arr[], const int &stringLength); //function prototype for creating an array of unique random numbers





 //starting main function
 int main()
 {
	char str1[30]; //Declaring an array str1 as type char for user input of size 30

	char str2[30] = "";  //Declaring an array str2 as type char initializing to empty of size 30

	int str1Length; //Declaring a variable as int to assign to length of string entered by user

	char again;   //char again to ask user if wants to rearrange again

	//Asking user for user input
	cout << "Please enter a word program will randomly rearrange the characters.\n";
	cout << "of your word.\n";
	cout << "You can enter maximum 29 characters.\n";
	cout <<	"Please enter your word: ";

	//User input for 29 characters string, 30 because last index will be used by '\0'
	cin.get(str1, 30);

	str1Length = strlen(str1);   //Assigning string length
	
	//Starting do-while loop
	do{
		//Calling a function which takes users string and empty string
		//and rearrange the characters in empty string
		swapStrings(str1, str2, str1Length);
		
		//Printing to user the rearranged string and original string 
 		cout << "This is word made by randomly rearranging the characters of\n";
 		cout << "your original word: " << str2 << endl;
 		cout << "This is original word entered by you :" << str1 << endl;
		
		//Asking user if wants to rearrange again
		cout << "Do you want to rearrange your characters again?\n";
		cout << "Enter 'Y' for yes and 'N' for no.";

       		cin.clear();  //clear error bit

		//drop first 1000 characters up to and including
		//the first newline (up to length of current stream)
		cin.ignore( 1000, '\n' );
		
		//User input for yes or no
		cin >> again;
		cout << "\n";

	}while(again == 'y' || again == 'Y'); //Ending do while loop

 return 0;
 }

  //starting function to rearrange characters in empty string
 /**************************
 * Function: swapsStrings
 * Entry: Address and length of char array from main function
 * Exit: None
 * Purpose: To rearrange the character of user's string in other empty string
 * ************************/

 void swapStrings( char word1[], char word2[], int stringLength)
 {
	int index = 0; //Declaring a variable to assign to random number
    	
	int arr[stringLength]; //Declaring an array as int size of string length
    	
	//Calling a funtion which create an array of unique random numbers of given size
	rand_int (arr, stringLength);
	
	//for loop to get every character of array
	for (int i = 0; i < stringLength; i++)
	{
		index = arr[i];    //Assigning index to elements of random array
		
		word2[i] = word1[index]; //Assigning elements of second string to character at random
		                         //index in first string
	}
 }

 //starting a function which creates an array of unique random numbers
 /******************************
 * Function: rand_int as void
 * Entry: It will take the address of an array and size
 * Exit: None
 * purpose: It will generate the array of unique random numbers of given size
 ******************************/

 void rand_int (int arr[], const int &stringLength)
 {
     	srand(time(0));   //Calling time function
     
     	int randomNumber; //Declaring a variable as int to assign to random number
     
     	int countRandom = 0; //Declaring a variable as int to track count of random numbers
     
     	bool repeat;  //Declaring a variable bool to repeat do-while loop if the number
                      //generated is already in array
 	
	//For loop to assign random number to each element of array
	for(int i = 0; i < stringLength; i++)
   	{
		countRandom++; //Increment count with each number
		
		//Starting do-while loop to generate random number again if it is already in array
		do
		{
           		repeat = false; //Assigning bool repeat to false
       			
			randomNumber = (rand()%(stringLength));  //Generating random number from 0 to strlength - 1
	 		
			arr[i] = randomNumber;  //Assigning random number to element of array
	 	        
			//For loop to check that the latest number assigned to element is not equal to previous numbers
            		for (int x = 0; x < countRandom - 1; x++)
                	{
				//If any of element equal to latest random number repeat do-while loop again
                    		if(randomNumber == arr[x])
                    		{
                        		repeat = true; //Generate another random number again
                    		}
        		}
	  	}
		while (repeat == true); //Ending do-while loop
	}
 }



