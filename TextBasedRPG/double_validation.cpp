//function to validate input data type
 /**************************
 * Function: double_validation declared as double
 * Entry: none
 * Exit: Return the value of input from user after validating
 * Purpose: validate input from user as type double
 * ************************/

 #include <iostream>
 #include "double_validation.h"

 using namespace std;

 double double_validation()
 {
	 double double_validation; //declaring a variable as int to be validate

	 cin >> double_validation;  //user input
	do
	{
	 	//while loop to check data type
	 	while(cin.get() != '\n')
	 	{
			cout << "\nThe number you entered is "
		      	      <<  "not an number.\n";
		 	cout << "Please enter a valid number again:";

                 	cin.clear();  //clear error bit

		 	//drop first 1000 characters up to and including
		 	//the first newline (up to length of current stream)
		 	cin.ignore( 1000, '\n' );

		 	cin >> double_validation;
	 	}

		//if user input is negative
		if (double_validation <= 0)
		{
			cout << "The number entered cannot be zero or negative."
                             << " Please enter again: ";
	       	}
	}while (double_validation <= 0);

 	return double_validation; //return user input to main function after validation
 }



