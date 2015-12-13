 /***************************
 * Author: Baljot Singh
 * Date created:  10/28/2014
 * Program name:compareTwoStrings.cpp
 * Description: This program will compare the two strings by comparing
 *              every single character one by one.
 * input: Two words as type string from user str1 and str2
 * Output: The output will tell if the two strings input by user are equal or
           not
 ****************************/

 #include <iostream>
 #include <string> 

 using namespace std;

 //function prototype
 void compareTwoWords(string &, string &, bool &);
 
 //starting main function
 int main()
 {     
 	string str1, str2; // declaring two strings
	bool same;         //declaring a bool same
        
        // Asking user to input the first string
        cout << "Please input your first word you want to compare" << endl;     
        getline (cin, str1);
       
        // Asking user to input the second string
        cout << "Please input your second word you want to compare" << endl;     
        getline (cin, str2);
       
        //Calling the function compareTwoWords
        compareTwoWords( str1, str2, same);

        if (same == true)
        {
		cout << "The two words you entered are same." << endl;
        }

        else
        {
		cout << "The two words you entered are not same." << endl;
        }

 return 0;
 }    
       
 //Starting a function as type bool which is called
 //in main function. Below are details:
 /*************************************
 * Function: compareTwoWords
 * Entry:Two strings. str1 and str2 and variable 'same' from function
 * Exit: none
 * Purpose: It will compare the each character of both strings to check
            and will assign true or false to bool same by referencing
 **************************************/	   
      
 void compareTwoWords( string &word1, string &word2, bool &equal)
 {
 	char char1, char2;  //declaring two chars to compare character from
                            // each string
	char notEqual;    //declare variable notEqual as char to make decision
	 		   //whether strings character are equal or not
			 
        //if statement check if length of strings is not equal
	//This will assign false to variable 'same' i.e. strings are not same 
	if (word1.length() != word2.length())
        { 
		equal = false;
        }
         
	//otherwise if length of strings is equal
        else 
        {   
		//for loop to compare each character
 		for (unsigned int i = 0; i < word1.length(); i++)
	        {   
 			char1 = word1.at(i);
	          	char2 = word2.at(i);
	         
		  	//conditional statement to compare each character
		  	//if at any point the characters are not same this 
		  	//statement will execute and will break the for loop
	          	if (char1 != char2)
	          	{   
	   	     		notEqual = 'y'; //character not matching
		     		break;
	          	}
	       }
	     
	      //conditional statements to make decision if strings are equal or not
	      
	      //This will assign false to variable 'same' i.e. strings are not same
	      if (notEqual == 'y') 
	      { 
	         equal = false; 
	      }
	     
	       //This will assign true to variable 'same' i.e. strings are same
	      else
	      {  
	          equal = true;
	      }
         }
 }


