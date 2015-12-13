/************************
 * Author: Baljot Singh
 * Date created:  11/20/2014
 * Program name: findMode.cpp
 * Description: This program will return the mode of data set entered by user
 * input: Data set of integers
 * Output:Mode of data set. If no integers repeats then will tell user
 *        there is no number which occurs twice, so data set is mode of itself.
 ****************************/

 #include <iostream>
 #include <vector>
 #include <string>
 #include <cstring>
 #include <cstdlib>


 using namespace std;

 //function prototypes

 void userInput(int &elementCount, vector <int> &fillVector); //Function prototype for getting user input and add it into vector

 vector <int> modeVector(vector <int> &); //Function prototype for finding mode

 //Starting main function
 int main()
 {
	vector <int> numbers; //Declaring a vector to get user input
	
	vector <int> modeOfSet; //Declaring a vector to assign to the returned mode vector
	
	int count = 1; //For counting the integers entered by user for data set

	//Giving instruction to user
	cout << "You can enter the list of integers. You will get mode of the list\n\n";

	userInput(count, numbers);  //Function to get user input and fill vector

	modeOfSet = modeVector(numbers); //Function which returns mode

    	//If no number in set appeared twice or more
	if(modeOfSet.empty())
    	{
		//Displaying the data set which was entered by user
		cout << " The data set you entered is:" << endl << "{";
        	for (unsigned int i = 0; i < numbers.size() - 1; i++)
        	{
			cout << numbers[i] << ",";
        	}
		cout << numbers[numbers.size() - 1] << "}" << endl;

        	cout << "There is no number which appeared twice or more in your\n";
		cout << "given data set. We can say all data set is mode of itself.\n";
	}

    	//If there are numbers in data set which appeared twice or more
	else
    	{
		//Displaying the data set whcih was enetered by user
		cout << " The data set you entered is:" << endl << "{";
        	for (unsigned int i = 0; i < numbers.size() - 1; i++)
        	{
            		cout << numbers[i] << ",";
        	}
		cout << numbers[numbers.size() - 1] << "}" << endl;

        	//Displaying the mode of data set
		cout << " The mode of data is:" << endl << "{";
        	for (unsigned int j = 0; j < modeOfSet.size() - 1; j++)
        	{
            		cout << modeOfSet[j] << ",";
        	}
		cout << modeOfSet[modeOfSet.size() - 1] << "}" << endl;
    	}

 return 0;
 }

 //starting function to get mode of data set
 /**************************
 * Function: modeVector declared as vector <int>
 * Entry: Address of vector from main function
 * Exit: Return vector of mode of set
 * Purpose: To get mode of data set
 * ************************/

 vector <int> modeVector(vector <int> &modeNumbers)
 {
	vector <int> mode; //Declaring a vector mode to get mode of data
     	
	int modeNum; //Declaring a variable as int to assign to mode number
     	
	int counter; //Variable counter to count how many times a number appeared in set
     	
	bool isMode; //bool to check if there is mode
     	
	int temp = 2; //variable temp to keep track of count of previous mode

    	// nested for loops to get the one number from set and compare it to all numbers next to it
	for (unsigned int i = 0; i < modeNumbers.size(); i++)
	{
		isMode = false;  //Assuming there is no mode
	    	
		counter = 0; //Assigning counter to 0
	    	
		modeNum = modeNumbers[i]; //Assigning modeNum to ith element

	    	//for loop to compare the above assumed mode to next elements
		for (unsigned int j = i ; j < modeNumbers.size(); j++)
        	{
			//If there is mode
			if (modeNum == modeNumbers[j])
            		{
                		counter++; //Increment counter
			}
        	}
        	
		//There is mode if counter is greater than or equal to 2
		if(counter >= 2)
        	{
            		isMode = true;
        	}

		//If there is mode
        	if(isMode == true)
        	{
            		//If counter is equal to previous counter
			if(counter == temp)
            		{
                		//Add that mode to vector
				mode.push_back(modeNum);
            		}
            		
			//If current count is greater than previous count
			else if(counter > temp)
            		{
                		temp = counter; //Assign counter to temp
                		
				mode.clear(); //Clear all the previously assumed modes
                		
				mode.push_back(modeNum); //Add mode to vector
            		}
        	}
    }
    return mode;
 }//End of modeVector function 

 //starting function to get user input
 /**************************
 * Function: userInput declared as void
 * Entry: Address of vector from main and address of count
 * Exit: None
 * Purpose: To get user input in form of string and convert it to integer 
 *           and then fill vector and stop when user chooses to stop.
 * ************************/

 void userInput(int &elementCount, vector <int> &fillVector)
 {
	 bool printError; //A bool variable if there is error in input

	 bool repeat; //Declaring a variable repeat as bool

	 int integer; //Declaring a variable to assign to the user input after after converting it to integer

	 string getInput; //String to get user input

	 //Starting do-while loop till input is not correct
	 do
        {
		getInput = ""; //Initializing getInput to empty

		repeat = false; //Assigning repeat to false assuming input will be correct

		printError = false; //Assigning to false assuming input will be correct

		int digits = 0; //Declaring and initializing a variable as int

		char temp[10] = ""; //Declaring and initializing a char array to get integer part from input

		//Asking User for input
		cout << "Enter 'Stop', if you have finished entering data.\n";
        	cout << "Or enter your integer#" << elementCount << ": ";
        	
		getline(cin, getInput); //Getting user input

		char *valuesInput = new char [getInput.length() + 1]; //dynamically allocating a char array

		strcpy(valuesInput, getInput.c_str()); //Copy user string for input to cstring
		cout << endl;

		//If user chooses to stop without entering any data
		if(getInput == "Stop" && elementCount == 1)
        	{
            		cout << "You entered 'Stop'. But you didn't enter any data. Please enter some data.\n\n";
            		repeat = true;
        	}

        	//If user choose to stop after entering data
		else if(getInput == "Stop")
        	{
            		cout << "You finished entering data. Lets find mode of data.\n\n";
        	}
		
		//If user press enters without entering anything
        	else if(getInput.length() == 0)
        	{
            		cout << "No input.\n";
            
            		repeat = true;
        	}

        	//If user enters a number for data set
		else
        	{
			//For loop to go through all row of user input
            		for (unsigned int k = 0;k < strlen(valuesInput); k++ )
            		{
                		//If there is digit or negative sign
				if(isdigit(valuesInput[k]) || valuesInput[k] == '-')
                		{
                    			temp[digits] = valuesInput[k]; //Assigning digits to char temp
					
					digits++; //Increment the digits

                    			//Fixing the range for highest entered number
					if(strlen(temp) >= 10)
                    			{
						cout << "Very big number. Out of range.\n";
                        			printError = true;
                        			break;
                    			}

                    			//End of all characters of user input
                    			else if(valuesInput[k+1] == '\0')
                    			{
						integer = atoi(temp); //Convert that digits to integers
						
						fillVector.push_back(integer); //Add the user input to vector
                        			
						elementCount++; //increment elementcount to track number of integers in user's input
                    			}

                    			//Otherwise if the next character is not digit
					else if(!(isdigit(valuesInput[k+1])))
                    			{
                        			printError = true;
                        			break;
                    			}
				}
				
				//If first character is not digit or negative sign print error message and break for loop
				else
            			{
                			printError = true;
                			break;
            			}
			
			} //Ending for loop
		
			//If not a valid integer
			if(printError == true)
        		{
				cout << "Number you entered is not valid. Please enter one integers only at a\n";
            			cout << "time without any white space.\n\n";
            			repeat = true;
        		}
		}//End of else statement

		delete [] valuesInput; //deallocating char array
	
	}while(repeat == true || getInput != "Stop"); //Ending do-while loop

 }//Ending userInput function
