/***************************
 * Author: Baljot Singh
 * Date created:  10/31/2014
 * Program name: binaryConversion.cpp
 * Description: This program will give user options to convert
 *              binary and decimal number.
 * input: Number in binary form or decimal
 * Output:binary number or decimal number
 ****************************/

 #include <iostream>
 #include <string>


 using namespace std;

 //function prototypes
 int binaryToDecimal (string, int, int base = 1); //function prototype to convert binary to decimal
 						  //default argument for parameter base
 string decimalToBinary (int); //function prototype to convert decimal to binary
 						  


 //starting main function
 int main()
 {
	int option; //Declaring a variable option for given options
	
	int choose; //Declaring a variable choose for input from user to choose from options
	
	char onesOrZeros; //Declaring a variable char which will assigned to every character
	                 //of the binary string entered by user to check if those are '1'
			 //or '0'
	
	char isBinaryForm; //Declaring variable isBinaryForm as type char to make decision if 
	                   //user entered correct binary form or not
	
	string binaryNeedsConversion; //Declaring variable to get user input for binary number
				      //type string
	
	int decimalNeedsConversion;   //Declaring variable to get user input for decimal number
				      //type int

	string convertedBinaryNumber;  //Declaring variable to print binary number after converting 
					//from decimal number
				      
	int convertedDecimalNumber;  //Declaring variable to print decimal number after converting 
				     //from binary number
	
	//Giving overview of program to user
	cout << "This program will convert binary to decimal and decimal\n";
	cout << "to binary. Please enter your option:\n\n";

	do{
		//Giving menu to user to choose
		cout << "Please enter 1 if you want to convert binary to decimal.\n";
		cout << "Please enter 2 if you want to convert decimal to binary.\n";
		cout << "Please enter 3 if you want to exit the program.\n";
		cout << "Please enter any one of the options given above :";
		
		//User will choose
		cin >> choose;
		
		cin.clear();  //clear error bit

		//drop first 1000 characters up to and including
		//the first newline (up to length of current stream)
		cin.ignore( 1000, '\n' );

		cout << endl;

		option = choose;  //option will assign to the number user by user
		
		//if user choose first option to convert binary to decimal
		if (option == 1)
		{
			//Asking user to input binary number
			cout << "You chose to convert binary to decimal. Please enter your binary"
		     	     << " number," << endl << "which should contain only ones and zeros." 
			     << " No space allowed between" << endl << "Enter:";
			
			//getline to get user's input as binary form as type string
			getline (cin, binaryNeedsConversion);
			
			//for loop to go through each character the binary string entered by user
			for (unsigned int i = 0; i <= binaryNeedsConversion.length() - 1; i++)
			{
				onesOrZeros = binaryNeedsConversion.at(i);  //assigning character to char
				
				//if the character is not equal to '1' or '0'
				if (!(onesOrZeros == '0' || onesOrZeros =='1'))
				{
					isBinaryForm = 'N'; //not binary form
					
					//Telling user it is not correct binary form and breaking for loop
					cout << "You entered invalid binary number. It should contain only"
				             << " ones and zeros without" << endl << "space. Restarting again.\n\n";
				             break;
				}

				//otherwise if the every character is '1' or '0'
				else if (onesOrZeros == '0' || onesOrZeros =='1')
                		{
					isBinaryForm = 'Y'; //correct binary form
                		}
             		}
		
			//if correct binary form
        		if (isBinaryForm == 'Y')
				{
					//Assigning the length of binary string by subtracting 1
					//to variable length, which will be used in function
					int length = (binaryNeedsConversion.length() - 1); 
					
					//calling a function which will convert binary to decimal
					convertedDecimalNumber = binaryToDecimal(binaryNeedsConversion, length);
					
					//Printing the decimal number for given binary number
					cout << "This is decimal form of the binary number given by you: "
					     << convertedDecimalNumber << endl << endl;

					cout << "Restarting the program again to do another conversion.\n\n";
				}
		}


		//if user choose to convert decimal to binary
		else if (option == 2)
		{
			//Asking user to input decimal number
			cout << "You chose to convert decimal to binary. Please enter your decimal"
		     	     << " number, number" << endl << "should be strictly positive integer: ";
			cin >> decimalNeedsConversion;
				
				//if input is not an integer
				if(cin.get() != '\n')
				{

	          			cout << "The number you entered for "
				     	     <<  "is not valid.\n";
		       			cout << "Restarting again.\n\n";

                 			cin.clear();  //clear error bit

					//drop first 1000 characters up to and including
					//the first newline (up to length of current stream)
					cin.ignore( 1000, '\n' );
	       			}

				//if user input is negative negative
				else if (decimalNeedsConversion < 0)
				{
					cout << "The number entered cannot be negative."
                             	   	     << " Restarting again.\n\n";
	       			}
				
				//if user's input is positive integer or 0
				else
				{
					//calling a function which will convert decimal to binary
					convertedBinaryNumber = decimalToBinary (decimalNeedsConversion);
					
					//Printing the binary number for given decimal number
					cout << "This is binary form of the decimal number given by you: "
			           	     << convertedBinaryNumber << endl << endl;

					cout << "Restarting the program again to do another conversion.\n\n";
				}

		}
		
		//if user choose to exit the program
		else if (option == 3)
		{
			cout << "You chose to exit the program. Exiting the program.\n";
			cout << "Thank you.\n";

		}
		
		//if user enters other number than 1,2 or 3 to choose
		else
		{
			cout << "Please enter 1 or 2 or 3 only to choose. Restarting again.\n\n";
		}
	}while (option !=3); //ending do-while loop if user choose to exit by entering 3

 return 0;
 }

 //starting function to convert binary to decimal
 /**************************
 * Function: binaryToDecimal as type int
 * Entry: string binaryNeedsConversion and int length from main function
 * Exit: Decimal number
 * Purpose: To convert binary to decimal
 * ************************/

 int binaryToDecimal(string binaryString, int len, int base)
 {
	 //till the len reaches the 0. the function will call itself recursively
	 if (len >= 0)
	 {
		 //taking one character from binary string starting from one's place and converting it to type
		 //int and multiplying by base and adding it to next recursive call. Doubling the base and
		 //decrementing the len with every recursive call.
		 return (base*(binaryString.at(len) - '0') + binaryToDecimal(binaryString, len - 1, base*2));
    	 }

	 //base case when len < 0 and call through every character of binary string is finished
	 else
	 {
		 return 0;
	 }
 }

 //starting function to convert decimal to binary
 /**************************
 * Function: Input decimalToBinary from main function
 * Entry: int decimalNeedsConversion from main function
 * Exit: Return the binary form as type string
 * Purpose: To convert binary to decimal
 * ************************/

 string decimalToBinary(int decimalNumber)
 {
	 string binaryForm = "";
	 char oneOrZero = ' ';

	 //base case when decimal number is 1
	 if (decimalNumber == 1)
	 {
		 return "1";
	 }

	 //case if decimal number entered is zero
	 else if (decimalNumber == 0)
	 {
		 return "0";
	 }

	 else
	 {
		 //taking the remainder with every recursive call and converting to
		 //type char
		 oneOrZero = decimalNumber % 2 + '0';

		 //recursive call by changing the value of decimal number dividing it by 2
		 //Adding remainder to string binaryForm with every recursive call
		 //the base will return "1" when decimal number will reach at 1.
		 return (decimalToBinary(decimalNumber/2) + oneOrZero + binaryForm);
	 }
 }



