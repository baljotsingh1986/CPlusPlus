/************************
 * Author: Baljot Singh
 * Date created:  1/29/2015
 * Program name: groceryList.cpp
 * Description: This program will help the user in shopping. User can add new items
 *              items in cart, can see added item into cart and can see total price
 *              of all items in cart. List will be automatically saved as list.txt
 * input: Item details(Name, unit, Quantity and Price)
 * Output:Display Items which are added by user and total price of all Items.
 ****************************/

 #include <iostream>
 #include <string>
 #include <fstream>
 #include <cstdlib>
 
 #include "Items.h"
 #include "ShoppingCart.h"
 #include "double_validation.h"

 using namespace std;

 //Starting main function
 int main()
 {
	 string option; //Declaring a variable to get user option

	 string item_name; //A variable to get name from user

	 string item_unit; //A variable to get unit from user

	 double item_price; //A variable to get price from user

	 double item_quantity; //A variable to get quantity from user

	 string action; //Declaring a variable as type char to check if no items are added

	 ShoppingCart shopHelp;  //A ShoppingCart object

	 //Giving Instruction
	 cout << "\nLets start shopping. Your items will be automatically saved in file list.txt\n\n";

	 fstream groceryFile("list.txt", ios::out); //A fstream object for input and output to file
	 
	 //If error in opening file
	 if(!groceryFile)
	 {
		 std::cout << "\nError in opening file.\n\n";
	 }

	 else
	 {
	     	 char choice; //A variable to ask user if wants to add another item

		 //Do-while loop till user wants to add another item
		 do
		 {
			//Asking user for item name
			cout << "Enter the item name:";
			getline(cin, item_name);
			
			//Asking user for unit
			cout << "Enter the item unit:";
			getline(cin, item_unit);

			//Asking user price
			cout << "Please give the price of item : ";

			//Calling a Function which validates price input
			item_price = double_validation();

			//Asking user quantity
			cout << "Please give the quantity of item : ";

			//Calling a Function which validates quantity input
			item_quantity = double_validation();

			//Writing all input to file list.txt
			groceryFile << item_name << "\n";
			groceryFile << item_unit << "\n";
			groceryFile << item_price << "\n";
			groceryFile << item_quantity << "\n";

			//Asking user if wants to add another item in list
			cout << "\nDo you want to add another item?";
			cout << "Enter y for yes n for no:";
			cin >> choice;

                 	cin.clear();  //clear error bit

			cin.ignore(1000,'\n');
		 
		 }while(choice == 'y');
                 
		 groceryFile.clear(); //Clear flag on file
		 
		 groceryFile.close(); //Close file

                 cout << "Your shopping list is saved as list.txt\n\n";
	 }

        //Starting do-while loop
    	 do
    	 {
		//Menu display for options
		cout << "\nYour options.\n";
        	cout << "Enter 1 if you want to see all items in list.\n";
        	cout << "Enter Quit if you want to exit shopping.\n";
        	cout << "Please enter your option: ";

		//Getting user option
		getline(cin, option);

		cout << endl;

		//Conditional statements for options

        	if(option == "1")
        	{
			string item_na; //A variable to read name from list.txt file

	 		string item_un; //A variable to read unit from list.txt file

	 		string item_pr; //A variable to read price from list.txt file

	 		string item_qua; //A variable to read quantity from list.txt file
			
			shopHelp.clearVector(); //Clearing vector
			
			groceryFile.open("list.txt", ios::in); //Opening file for input

			//If error in opening file
			if(!groceryFile)
			{
				 std::cout << "\nError in opening file.\n\n";
			}

			else
			{
				//Reading data from file

				getline(groceryFile, item_na);  
						
				getline(groceryFile, item_un);

				getline(groceryFile, item_pr);

				getline(groceryFile, item_qua);

				double price = atof(item_pr.c_str()); //Convert string to float

				double quantity = atof(item_qua.c_str()); //Convert string to float
				
				//While reach end of file
				while(!groceryFile.eof())
				{
					//If reading failed
					if(groceryFile.fail())
					{
						cout << "Error:The input file format may be wrong.\n\n";
					}

					else
					{
						//call ShoppingCart member function to add items to vector and
						//pass argument constructor of Items class which will set the values
						//of data members of Items class to user input
						shopHelp.addItem(Items(item_na,item_un, price, quantity));
						
						//Reading data from file

						getline(groceryFile, item_na);  
						
						getline(groceryFile, item_un);

						getline(groceryFile, item_pr);

						getline(groceryFile, item_qua);

						price = atof(item_pr.c_str()); //Convert string to float

						quantity = atof(item_qua.c_str()); //Convert string to float
					}
				}

				groceryFile.clear(); //Clear flag on file
				
				groceryFile.close(); //Close file

				shopHelp.listItems(); //calling function from class ShoppingCart to display Items

				//Asking user for action
				cout << "\nIf you want edit an item in above list enter E.\n";
				cout << "\nIf you want to remove an item in above list enter R.\n";
				cout << "\nIf you want to add an item in above list enter A.\n";
				cout << "\nIf you do not want to make any change. Enter N.\n";
				cout << "Please enter your option:";
				cin >> action;

				cin.clear();  //clear error bit

				cin.ignore(1000,'\n');

				//If user wants to edit an item
				if(action == "e" || action == "E")
				{
					groceryFile.open("list.txt", ios::out|ios::trunc); //Open file and erase all data

					if(!groceryFile)
					{
						cout << "Error:The input file format may be wrong.\n\n";
					}

					else
					{
						//Asking user the name of item wants to edit
						cout << "Enter the item name you want to edit:";
						getline(cin, item_name);

						shopHelp.editItem(item_name, groceryFile); //calling function from class ShoppingCart to edit Item
					}
				
					groceryFile.clear();
				
					groceryFile.close();
				}
				
				//If user wants to remove an item
				else if(action == "r" || action == "R")
				{
					groceryFile.open("list.txt", ios::out|ios::trunc); //Open file and erase all data

					if(!groceryFile)
					{
						cout << "Error:The input file format may be wrong.\n\n";
					}

					else
					{
						cout << "Enter the item name you want to remove:";
						getline(cin, item_name);

						shopHelp.removeItem(item_name, groceryFile); //calling function from class ShoppingCart to remove Item
					}
			
					groceryFile.clear();
				
					groceryFile.close();
				}
				
				//If user wants to add an item
				else if(action == "a" || action == "A")
				{
					groceryFile.open("list.txt", ios::out|ios::app); //Open file in append mode

					if(!groceryFile)
	 				{
						std::cout << "\nError in opening file.\n\n";
	 				}

	 				else
	 				{
	 				    char choice;
		 				do
		 				{
							cout << "Enter the item name:";
							getline(cin, item_name);

							cout << "Enter the item unit:";
							getline(cin, item_unit);

							//Asking user price
							cout << "Please give the price of item : ";

							//Calling a Function which validates price input
							item_price = double_validation();

							//Asking user quantity
							cout << "Please give the quantity of item : ";

							//Calling a Function which validates quantity input
							item_quantity = double_validation();

							groceryFile << item_name << endl;
							groceryFile << item_unit << endl;
						        groceryFile << item_price << endl;
							groceryFile << item_quantity << endl;

							cout << "Do you want to add another item?";
							cout << "Enter y for yes n for no:";
							cin >> choice;

							cin.clear();  //clear error bit

						        cin.ignore(1000,'\n');

						}while(choice == 'y');

		 				cout << "Your shopping list is updated and saved as list.txt\n\n";
					}	
				
					groceryFile.clear();
				
					groceryFile.close();
				}
				
				//If user doesn't want to change
				else if(action == "n" || action == "N")
				{
					cout << "No changes made. Returning to main menu.\n\n";
				}

				else
				{
					cout << "Invalid option. Returning to main menu\n\n";
				}
			}
		}

		//If use chose to quit
		else if(option == "Quit")
        	{
            		cout << "You chose to exit shopping. Thanks you.\n";
        	}

        	//If not a valid option
		else
        	{
            		cout << "Please enter valid option.\n\n";

		}

	 }while(option != "Quit");

 return 0;
 }
