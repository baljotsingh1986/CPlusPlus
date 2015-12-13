//function to validate input data type
 /**************************
 * Function: double_validation declared as double
 * Entry: none
 * Exit: Return the value of input from user after validating
 * Purpose: validate the price input from user is type double
 * ************************/

#include <iostream>
#include "double_validation.h"

using namespace std;

 double double_validation()
 {
	 double double_validation; //declaring a variable as int to be validate

	 cin >> double_validation;  //user input

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

 return double_validation; //return user input to main function after validation
 }



