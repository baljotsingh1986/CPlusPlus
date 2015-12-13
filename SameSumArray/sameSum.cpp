/************************
 * Author: Baljot Singh
 * Date created:  11/16/2014
 * Program name: sameSum.cpp
 * Description: This program will return true if the sum of rows, columns
 *              and major diagonals of square matrix is same otherwise false
 * input: Arrays size and values for square matrix
 * Output:True if the sum of rows, columnsand major diagonals of square
 *        matrix is same otherwise false
 ****************************/

 #include <iostream>
 #include <cstdlib>
 #include <cstring>

 using namespace std;

 //function prototypes

 bool sameSum(int array_integer[][10], int size_array); //function prototype for checking sum

 void row_array(int arr[], int); //Function prototype for user input validation for matrix

 int arrSize_validation(); //function prototype for user input validation for size of square

 //starting main function
 int main()
 {
	int arr[10][10]; //Declaring a 2d array as type int of size 10 by 10

	int squareSize; //Declaring a variable to ask user for size of square

	bool sumIsSame; //Declaring a variable as bool

	//Asking user for number of integers
	cout << "You can enter maximum 100 integers i.e. you can have square of maximum size 10\n";
	cout <<	"Please give the size of square matrix you want to make: ";

	//Calling the function which validates that number of integers user wants to input
	//is valid data type and between 0 and 11. Assigning the return value to squareSize
	squareSize = arrSize_validation();

	//Calling a function which returns the true if sum is same otherwisw false
	sumIsSame = sameSum(arr, squareSize);

	//Printing if sum of rows, columns and major diagonals is same  
	if(sumIsSame)
	{
	   	cout << "The sum of rows, columns and major diagonals is same\n";
	}
	else
    	{
        	cout << "The sum of rows, columns and major diagonals is not  same\n";
    	}

 return 0;
 }

 //starting function to to know if sum is same
 /**************************
 * Function: sameSum declared as bool
 * Entry: Address and size of array from main function
 * Exit: Return true if sum is same otherwise false
 * Purpose: To know if sum is same or not
 * ************************/

 bool sameSum( int arr_integer[][10], int size_array)
 {
    	int rowArray[12]; //Declaring an array to get elements from user input

    	int diagonal1Sum = 0; //Declaring a variable as int to get sum of first diagonal

    	int diagonal2Sum = 0; //Declaring a variable to get sum of other diagonal
     
     	int rowSum = 0;//Declaring a variable to get sum row

     	int columnSum = 0;  //Declaring a variable to get sum column
  
     	int diagonalIndex = 0; //Assigning a variable to 0 to get diagonal index

	//nested for loops to assign user input to square array
	for ( int i = 0; i < size_array; i++)
	{
	   	cout << "Please input " << size_array << " values for row#" << (i + 1) << ": " ;
		
		//Calling a function which gets user input in single row and validates
		//and assign that input to rowArray
		row_array(rowArray, size_array);

		//For loop to assign element of rowArray to square array 
		for (int j = 0; j < size_array; j++)
		{
		    	arr_integer[i][j] = rowArray[j];
       		}
    	}	
	
	//For loop to print square matrix
    	for ( int i = 0; i < size_array; i++)
	{
	    	for (int j = 0; j < size_array; j++)
        	{
            		cout << arr_integer[i][j] << " ";
        	}
		cout << endl;
    	}

    	//for loop to get sum of first diagonal
	for( int i = 0; i < size_array; i++)
    	{
        	diagonal1Sum += arr_integer[i][i];
    	}
    	
        //For loop to get sum of second diagonal
	for( int i = size_array - 1; i >= 0; i--)
    	{
        	diagonal2Sum += arr_integer[diagonalIndex][i];
        	diagonalIndex++;
    	}	

    	//If diagonal sum is not same return false
	if(diagonal1Sum != diagonal2Sum)
    	{
        	return false;
    	}	
    	
	//if diagonal sum is same
	if(diagonal1Sum == diagonal2Sum)
    	{
	   	//nested for loops to get each row sum
        	for( int i = 0; i < size_array; i++)
        	{
            		rowSum = 0;
            		for (int j = 0; j < size_array; j++)
            		{
                		rowSum += arr_integer[i][j];
            		}
            		
			//If any of row sum not equal to diagonal sum return false
			if(rowSum != diagonal1Sum)
            		{
                		return false;
                		break;
            		}
        	}	
    	}
    
	//If each row sum was equal to diagonal sum 
	if(diagonal1Sum == rowSum)
    	{
	   	//nested for loops to get each column sum
        	for( int i = 0; i < size_array; i++)
        	{
            		columnSum = 0;
            		for (int j = 0; j < size_array; j++)
            		{
                		columnSum += arr_integer[j][i];
            		}	
            		
			//If any of column sum not equal to diagonal
			if(columnSum != diagonal1Sum)
            		{
                		return false;
                		break;
            		}
        	}
    	}
    	
	//At last if diagonal sum was equal to column sum
	if(diagonal1Sum == columnSum)
    	{
        	return true;
    	}
    	
	//Other wise return false
	else
    	{
        	return false;
    	}
 }//End of function

 //starting function to get user input
 /**************************
 * Function: row_array declared as void
 * Entry: Address and size of array from main function
 * Exit: None
 * Purpose: To get user input for integers in single row separated by whitespaces
 *          and validate it and assign the elemnts of user input to array.
 * ************************/

void row_array(int arr[], int rowSize)
{
    	bool printError; //A bool variable if there is error in input

	bool repeat; //Declaring a variable repeat as bool

	//Starting do-while loop till input is not correct
	do
    	{
	   	char rowInput[100] = ""; //Declaring a char array to get user input

		int elementCount = 0; //Declaring to count how many integers in input

		repeat = false; //Assigning repeat to false assuming input will be correct

		printError = false; //Assigning to false assuming input will be correct

		int digits = 0; //Declaring and initializing a variable as int

		int element; //Declaring a variable as int to extract integers from input

		int index = 0; //Declaring a variable as int

		char temp[10] = ""; //Declaring and initializing a char array to get integer part from input

		cin.getline(rowInput, 99); //Getting user input
		cout << endl;

		//For loop to go through all row of user input
		for (unsigned int k = 0;k < strlen(rowInput); k++ )
    		{
			//If space continue do nothing
			if(isspace(rowInput[k]))
	    		{
		    		continue;
	    		}

			//If not digit print error message and break for loop
			if(!isdigit(rowInput[k]))
	    		{
		    		printError = true;
                   		break;
	    		}

	    		if(isdigit(rowInput[k]))
	    		{
		    		temp[digits] = rowInput[k]; //Assing digits to char temp

				digits++; //Increment the digits

				//If after digit there is space or end of row input
				if(rowInput[k + 1] == ' ' || rowInput[k+1] == '\0' )
                    		{
					elementCount++; //increment elementcount to track number of integers in user's input

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

		} //Ending for loop

		//If number of integers in user input is not equal to size or printError is true
		if(elementCount != rowSize || printError == true)
                {
                    cout << "Please enter integers only separated by white spaces.\n";
                    cout << "Please enter exact data equal to matrix size.\n\n";
                    cout << "You declared square matrix size = " << rowSize << ". But You entered "
                         << elementCount << " values for row.\n";
                    cout <<  "Enter row values again: ";
                    
		    repeat = true;
                }
	 }while(repeat == true); //Ending do-while loop
 }//End of function

 //starting function to validate input for size of array
 /**************************
 * Function: arrSize_validation declared as int
 * Entry: none
 * Exit: Return the value of input from user after validating
 * Purpose: Validate that the input from user is integer and in
 *          range of maximum declared size of array
 * ************************/

 int arrSize_validation()
 {
	int size_validation; //declaring a variable as int to be validate

	//starting do while loop to check if input is not valid
	do
	{
		cin >> size_validation;  //user input

		//while loop to check data type
		while(cin.get() != '\n')
	       	{
	          	cout << "The number you entered is "
		             <<  "not an integer.\n";
		       	cout << "Please enter a valid number again:";

                 	cin.clear();  //clear error bit

			//drop first 1000 characters up to and including
			//the first newline (up to length of current stream)
			cin.ignore( 1000, '\n' );

			cin >> size_validation;
	       	}

		//if user input is out of range of array size
		if (size_validation <= 0 || size_validation > 10)
		{
			cout << "The number should be between 0 and 11."
                             << " Please enter again: ";
	       	}
	}while (size_validation <= 0 || size_validation > 10);

 return size_validation;  //return user input to main function after validation
 }//End of function
