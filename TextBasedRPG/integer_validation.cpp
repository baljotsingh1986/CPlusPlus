//function to validate input data type
 /**************************
 * Function: integer_validation declared as int
 * Entry: none
 * Exit: Return the value of input from user after validating
 * Purpose: validate input from user as type int
 * ************************/

 #include <iostream>
 #include "integer_validation.h"

 using namespace std;

 int integer_validation()
 {
	 int int_validation; //declaring a variable as int to be validate

	 cin >> int_validation;  //user input
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

		 	cin >> int_validation;
	 	}

		//if user input is negative
		if (int_validation <= 0)
		{
			cout << "The number entered cannot be zero or negative."
                             << " Please enter again: ";
	       	}
	}while (int_validation <= 0);

 	return int_validation; //return user input to main function after validation
 }
