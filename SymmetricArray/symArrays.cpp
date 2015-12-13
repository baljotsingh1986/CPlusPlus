/************************
 * Author: Baljot Singh
 * Date created:  11/16/2014
 * Program name: symArrays.cpp
 * Description: This program will take command line argument for the size
 *              of 3 int arrays and then take the elements for each array as
 *              input in program and output if arrays are symmetric or not
 * input: Command line argument for size of 3 int arrays and array element input
 * Output: Program will print if arrays are symmetric or not
 ****************************/

 #include <iostream>
 #include <cstdlib>
 #include <cstring>

 using namespace std;

 //function prototypes

 void row_array(int arr[], const int &arrSize); //function prototype to get and validate input for position

 void printArray(int arr[], const int &sizeOfArray); //function prototype to print board

 bool isArrSym(int arr[], const int &size_array); //function prototype to check if player 0 won

 //starting main function
 int main(int argc, char *argv[])
 {
	int *arr1; //Declaring a pointer to int array 1

	int *arr2; //Declaring a pointer to int array 2

	int *arr3; //Declaring a pointer to int array 3

	int sizeArray1; //Declaring a variable as int to get size of array 1

	int sizeArray2; //Declaring a variable as int to get size of array 2

	int sizeArray3; //Declaring a variable as int to get size of array

	bool extractInteger = false; //variable as bool to make decision for extracting integer from command line argument

	//Giving instruction
	cout << "You need to give command line arguments e.g. './symArrays 4 5 4' where 4,5 and 4 are\n";
	cout << "sizes of 3 int arrays. You will input the values for each array in program. Output will\n";
	cout << "be if array is symmetric or not.\n\n";

	//If there are 4 command line arguments
	if(argc == 4)
    	{
	   	//nested for loop to check if the command line is valid
		for(int i = 1; i < argc; i++)
		{
			for(int j = 0; argv[i][j] != '\0'; j++)
        		{
		   		//if not digit exit the program and ask to re-run
				if(!(isdigit(argv[i][j])))
            			{
					cout << "The command is given in command line is not correct.\n";
                			cout << "Please enter three integers in command with spaces\n";
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
    	}

	//Extract integer
	if(extractInteger == true)
    	{
		sizeArray1 = atoi(argv[1]); //converting user command to integer

		sizeArray2 = atoi(argv[2]); //converting user command to integer

		sizeArray3 = atoi(argv[3]); //converting user command to integer

		//If any of command line argument is 0
		if (sizeArray1 <= 0 || sizeArray2 <= 0 || sizeArray3 <= 0)
		{
			cout << "You entered at least one of the array size either 0."
		             << " or very large number. Exiting the program.\n";
		   	exit(0);
        	}

		arr1 = new int [sizeArray1]; //dynamically allocating array 1

		arr2 = new int [sizeArray2]; //dynamically allocating array 2

		arr3 = new int [sizeArray3]; //dynamically allocating array 3

		//Calling function to get user input for 3 arrays

		cout << "Please give " << sizeArray1 << " values for first array.\n\n";
		row_array(arr1, sizeArray1);

		cout << "Please give " << sizeArray2 << " values for second array.\n\n";
		row_array(arr2, sizeArray2);

		cout << "Please give " << sizeArray3 << " values for third array.\n\n";
		row_array(arr3, sizeArray3);

		//Calling function to check if first array is symmetric or not
		isArrSym(arr1, sizeArray1);

		if(isArrSym(arr1, sizeArray1))
	 	{
			printArray(arr1, sizeArray1);

			cout << "First array is symmetrical.\n\n";
		}

		else
		{
			printArray(arr1, sizeArray1);

			cout << "First array is not symmetrical.\n\n";
		}

		//Calling function to check if second array is symmetric or not
		isArrSym(arr2, sizeArray2);

		if(isArrSym(arr2, sizeArray2))
		{
			printArray(arr2, sizeArray2);

			cout << "Second array is symmetrical.\n\n";
		}

		else
		{
			printArray(arr2, sizeArray2);

			cout << "Second array is not symmetrical.\n\n";
		}

		//Calling function to check if third array is symmetric or not
		isArrSym(arr3, sizeArray3);

		if(isArrSym(arr3, sizeArray3))
		{
			printArray(arr3, sizeArray3);

			cout << "Third array is symmetrical.\n\n";
		}

		else
		{
			printArray(arr3, sizeArray3);

			cout << "Third array is not symmetrical.\n\n";
		}


	}

	//If number of command arguments not equal to 4 exit the program after flaging it
    	else if(argc != 4)
    	{
        	cout << "Please enter size of exact three arrays in command arguments.\n";
        	cout << ".Not less not more. Please re-run the program.\n";
        	exit(0);
    	}

	//Deallocating arrays
	delete [] arr1;

	delete [] arr2;

	delete [] arr3;
 return 0;
 }

 //starting function to get user input
 /**************************
 * Function: row_array declared as void
 * Entry: Address of size and array from main function
 * Exit: None
 * Purpose: To get user input for integers in single row separated by whitespaces
 *          and validate it.
 * ************************/

 void row_array(int arr[], const int &arrSize)
 {
	 bool printError; //A bool variable if there is error in input

	 bool repeat; //Declaring a variable repeat as bool

	 string getInput; //Declaring a variable as string to get user input

	 //Starting do-while loop till input is not correct
	 do
    	 {
		getInput = ""; //Initializing getInput to empty

		int elementCount = 0; //Declaring to count how many integers in input

		repeat = false; //Assigning repeat to false assuming input will be correct

		printError = false; //Assigning to false assuming input will be correct

		int digits = 0; //Declaring and initializing a variable as int

		int element; //Declaring a variable as int to extract integers from input

		int index = 0; //Declaring a variable as int

		char temp[10] = ""; //Declaring and initializing a char array to get integer part from input

		getline(cin, getInput); //Getting user input

		char *valuesInput = new char [getInput.length() + 1]; //dynamically allocating a char array

		strcpy(valuesInput, getInput.c_str()); //Copy user string for input to cstring
		cout << endl;

		//For loop to go through all row of user input
		for (unsigned int k = 0;k < strlen(valuesInput); k++ )
    		{
			//If space continue do nothing
			if(isspace(valuesInput[k]))
	    		{
		    		continue;
	    		}

			//If not digit print error message and break for loop
			if(!isdigit(valuesInput[k]))
	    		{
		    		printError = true;
                   		break;
	    		}

	    		if(isdigit(valuesInput[k]))
	    		{
		    		temp[digits] = valuesInput[k]; //Assigning digits to char temp

				digits++; //Increment the digits

				//If after digit there is space or end of row input
				if(valuesInput[k + 1] == ' ' || valuesInput[k+1] == '\0' )
                		{
					elementCount++; //increment elementcount to track number of input in user's input

                    			element = atoi(temp); //Convert that digits to integers
					
					//condition to check the elements in user input are less than or equal to size
                    			if(elementCount <= arrSize)
                    			{
                        			arr[index] = element; //Assign element to integer array

                        			index++; //increment index

                        			//Empty the temp char to get next integer in row
			    			for(unsigned int i = 0; i < strlen(temp); i++)
			    			{
							temp[i] = ' ';
			    			}
			    			digits = 0; //Assign digits to 0
                    			}
					
					//if elements are greater than size 	
                    			else
                    			{
                        			printError = true;
                        			break;
                    			}
				}
			}

		} //Ending for loop

		//If number of integers in user input is not equal to size or printError is true
		if(elementCount != arrSize || printError == true)
                {
                    cout << "Please enter integers only separated by white spaces.\n";
                    cout << "Please enter exact data equal to matrix size.\n\n";
                    cout << "You declared square matrix size = " << arrSize << ". But You entered "
                         << elementCount << " values for row.\n";
                    cout <<  "Enter row values again: ";

		    repeat = true;
                }

	delete [] valuesInput; //deallocating char array

	}while(repeat == true); //Ending do-while loop
 }//Ending Function


 //starting function to print array
 /**************************
 * Function: printArray declared as void
 * Entry: Address and size of array from main function
 * Exit: None
 * Purpose: To print array
 * ************************/

 void printArray(int arr[], const int &sizeOfArray )
 {
	//for loops to print array
    	for ( int i = 0; i < sizeOfArray; i++)
	{
		cout << arr[i] << " ";
        }

	cout << endl;
 }

 //starting function to check if array is symmetric
 /**************************
 * Function: isArrSym declared as bool
 * Entry: Address and size of array from main function
 * Exit: Return true if array is symmetric or false if not
 * Purpose: To check if array is symmetric
 * ************************/

 bool isArrSym(int arr[], const int &size_array)
 {
     	 bool arraySymmetric = true; //Declaring and initializing a bool

	 //for loops to check every element in array
	 for( int i = 0; i < size_array/2; i++)
	 {	      
	     	//if elements are not equal
		if(arr[i] != arr[size_array - 1 - i])
		{
			arraySymmetric = false; //Arrays are not symmetric
                	break; //break for loop
           	}
	}

	//if array is not symmetric
	if(arraySymmetric == false)
	{
		return false;
	}

	//otherwise return true
	else
	{
		return true;
	}
 }
