/************************
 * Author: Baljot Singh
 * Date created:  11/27/2014
 * Program name: carLot.cpp
 * Description: This program will maintain the inventory for cars. It will take
 *              the input from user for detail of car. There will be two
 *              categories, 1. car is purchased but not sold yet. 2. car is
 *              purchased and sold. It will show the details of cars which are
 *              not sold yet, if user wants to see the cars in inventory. It
 *              will also give the profit from sold cars for specific month
 *              and year given by user. It will allow the user to sell the
 *              car if and only if there is a car in inventory, otherwise not.
 * input: Option choice, Car details, If it is sold than also sale details
 *        the month and year for which user want to see profit for sale
 * Output:Display the cars which are purchased but not sold upon user request.
 *        Profit for month and year given by user.
 ****************************/

 #include <iostream>
 #include <string>
 #include <iomanip>
 #include <vector>
 #include <cmath>
 #include <stdexcept>
 #include <cstdlib>


 using namespace std;

 //class Date with three data members
 class Date
 {
	 private:
     		int day;

     		int month;

     		int year;

	public:
		Date (){} //Default constructor
		
		//constructor to intitialize data member
		Date(int car_day, int car_month, int car_year)
		
		:day(car_day), month(car_month), year(car_year) //Initialize data members
		{
			//Conditions to check validity of date and throgh expextation if invalid

			//If day is out of range throw expectation
        		if(day <= 0 || day > 31 || month <= 0 || month > 12)
            		{
                		throw ("ERROR:Invalid day or month.");
            		}

			//if month is second
			else if (month == 2)
			{
				//If day is greater than 29
				if(day > 29)
            			{
                			throw ("ERROR:The given month and day are not valid date.");
            			}
        		}

        		//If month is between 1 and 7
        		else if (month >= 1 && month <= 7)
			{
		    		//If month is even
				if(month % 2 == 0)
            			{
					//if day greater than 30
                			if(day > 30)
                			{
                				throw ("ERROR:The given month and day are not valid date.");
                			}
            			}

        		}

        		//If month is between 8 and 12
        		else if (month >= 8 && month <= 12)
			{
				if(month % 2 != 0)
            			{
                			//if day greater than 30
                			if(day > 30)
                			{
                				throw ("ERROR:The given month and day are not valid date.");
                			}
            			}

        		}
		}

		//Accessor functions

		int getDay()
		{
			return day;
		}

		int getMonth()
		{
			return month;
		}

		int getYear()
		{
			return year;
		}
 };

 //class car
 class Car
 {
	 private:
	     	string make, model; //Two strings for make and model

     		int modelYear; //One int for car make year

     		Date datePurchased, dateSold; // 2 class Date objects

     		bool isSold;  //bool if car is sold or not

     		double purchasePrice, salePrice; //2 doubles for purchase price and sale price


	public:
        
        	Car(){} //default constructor

		//Constructor prototype for car purchase and sold
		Car(string carMake, string carModel, int carMakeYear, double purchase_Price, double sale_price, Date purchase_date, Date sold_date, bool sold);

		//Constructor prototype for car purchase
		Car(string carMake, string carModel, int carMakeYear, double purchase_Price, Date purchase_date, bool sold);

		//member function prototype to get profit
		double getProfit();

		//Accessor functions

		string getMake()
		{
			return make;
		}

		string getModel()
		{
			return model;
		}

		int getModelYear()
		{
			return modelYear;
		}

		Date getDatePurchased()
		{
			return datePurchased;
		}

		Date getDateSold()
		{
			return dateSold;
		}

		bool getIsSold()
		{
			return isSold;
		}

		double getPurchasePrice()
		{
			return purchasePrice;
		}

		double getSalePrice()
		{
			return salePrice;
		}
 };

 //class carLot
 class carLot
 {
	private:
		vector <Car> carData; //vector as object of Car

	public:
		//member function prototype to add car
		void addCar(Car &data);

		//member function prototype to display car
		void carList();

		//member function prototype to get month profit
		void monthProfit();
 };

 /********Constructor definitions for class Car**********/

 //Constructor definition for Constructor if car is purchased and sold
 Car :: Car(string carMake, string carModel, int carMakeYear, double purchase_price, double sale_price, Date purchase_date, Date sold_date, bool sold)
	:datePurchased(purchase_date), dateSold(sold_date) //Initialize objects of Date
 {
	 //Initialize data members

	 make = carMake;

	 model = carModel;

	 modelYear = carMakeYear;

	 purchasePrice = purchase_price;

	 salePrice = sale_price;

	 isSold = sold;
 }

 //Constructor definition for Constructor if car is purchased not sold
 Car :: Car(string carMake, string carModel, int carMakeYear, double purchase_price, Date purchase_date, bool sold)
	:datePurchased(purchase_date) //Initialize object of Date
 {
	 //Initialize data members
	 
	 make = carMake;

	 model = carModel;

	 modelYear = carMakeYear;

	 purchasePrice = purchase_price;

	 isSold = sold;
 }
 
 /*******member function definitions for class carLot******/

 //member function definition of class Car to get profit
 double Car :: getProfit()
 {
	 if(isSold)
	 {
		 return (salePrice - purchasePrice);
	 }

	 else
		{
		  return NAN;
		}
 }

 //Member function definition to add car to vector
 void carLot :: addCar(Car &data)
 {
	 data.getMake();

	 data.getModel();

	 data.getModelYear();

	 data.getDatePurchased();

	 data.getPurchasePrice();

	 if(data.getIsSold())
	 {
		 data.getDateSold();

		 data.getSalePrice();
	 }

	 carData.push_back(data);
 }

 //member function definition to display car list
 void carLot :: carList()
 {
	 int carNum = 0; //Variable car number for total cars

	 cout << "Here is list of cars which are not sold yet.\n\n";

	 //for loop to get every details of every car which is not sold yet
	 for (unsigned int i = 0; i < carData.size(); i++)
	 {
		if(!(carData[i].getIsSold()))
        	{
            		carNum++; //Increment number of cars

            		//For displaying price up to two decimal
            		cout << fixed << showpoint << setprecision(2) << endl;

            		cout << "************ CAR#" << carNum << " **************\n";

            		cout << "Make:             " << carData[i].getMake();
            		cout << endl;

            		cout << "Model:            " << carData[i].getModel();
            		cout << endl;

            		cout << "Year of make:     " << carData[i].getModelYear();
            		cout << endl;

            		cout << "Date of purchase: " << carData[i].getDatePurchased().getMonth() << "/";
            		cout << carData[i].getDatePurchased().getDay() << "/" << carData[i].getDatePurchased().getYear();
            		cout << "\n";

            		cout << "Purchase price:   " <<carData[i].getPurchasePrice();
            		cout << "\n\n";

            		//Just to make user friendly
            		if(i < carData.size() - 1)
        		{
				cout << "Please press enter to see next car in your lot.\n";
            			cin.get();
        		}
        	}
    	}

	cout << "There is/are total " << carNum << "  car(s) which is/are not sold yet.\n\n";

 }

 //member function definition to get month profit
 void carLot :: monthProfit()
 {
 	 double totalPurchase = 0; //Declaring and initializing variable as double to get total purchase price

	 double totalSold = 0; //Declaring and initializing variable as double to get total sale price

	 double profit; //variable to get profit

	 int monthSale; //Declaring a variable for month which user wants to see profit

	 int yearSale; //Declaring a variable for year which user wants to see profit

	 int carSold = 0; //variable to get the total number of cars sold

	 //Asking user for year
	 cout << "Give the year for which you want to see profit: ";
	 cin >> yearSale;

	 //Asking user for month
	 cout << "Give the month of year for which you want to see profit: ";
	 cin >> monthSale;

	 //for loop to get profit for month
	 for (unsigned int i = 0; i < carData.size(); i++)
	 {
		 //If car is sold
	    	if(carData[i].getIsSold())
            	{
			//If its sold in month and year given by user
		    	if(monthSale == carData[i].getDateSold().getMonth() && yearSale == carData[i].getDateSold().getYear())
            	    	{
                		carSold++;  //Increment carSold

				totalPurchase += carData[i].getPurchasePrice();  //Increment purchase price for car

				totalSold += carData[i].getSalePrice();  //Increment sale price for car
            	   	}
           	}
       	 }

       	 profit = totalSold - totalPurchase; //Calculating profit

       	 //Printing profit and total car sold to user
       	 cout << fixed << showpoint << setprecision(2) << endl;
 	 cout << "Total profit for month " << monthSale << " and year " << yearSale;
       	 cout << " is: " << profit << endl;
       	 cout << "There was/were total " << carSold << " car(s) sold.\n\n";
 }



 //Starting main function
 int main()
 {
	 string option; //Declaring a variable to get user option

	 char display = 'n'; //Declaring a variable as type char to check if no items are added

	 char sold;  //char to ask user if car is sold or not

	 string modelOfCar; //To ask user model of car

	 string makeOfCar; //To ask user make of car

	 int yearOfMake; //To ask user year of make of car

	 bool sell; //To assign bool to true or false for car sold or not

	 int dayOfDeal, monthOfDeal, yearOfDeal;  //Variables to get purchase date

	 int dayOfSell, monthOfSell, yearOfSell; //Variables to get sale date

	 double priceOfCar, priceOfCarSale; //Variables for purchase price and sale price

	carLot carInvenotry; //carLot object

	 //Giving Instruction
	 cout << "This program will help you to maintain car inventory.\n\n";

    	 do
    	 {
		//Menu display for options
		cout << "Your options.\n";
        	cout << "Enter 1 if you want to add new entry for car.\n";
        	cout << "Enter 2 if you want detail of all cars in lot, which are not sold yet.\n";
        	cout << "Enter 3 if you want to see profit for particular month of a year.\n";
        	cout << "Enter Quit if you want to exit.\n";
        	cout << "Please enter your option: ";



		//Getting user option
		getline(cin, option);

        	cout << endl;

		//Conditional statements for options

        	if(option == "1")
        	{
			display = 'y';

			//Asking user for car model
                    	cout << "Please give the model of car: ";
                    	getline(cin, modelOfCar);
                    	cout << endl;

                    	//Asking user for car make
                    	cout << "Please give the make of car: ";
                    	getline(cin, makeOfCar);
                    	cout << endl;

                    	//Asking user for year of car make
                    	cout << "Please give the year of make of car: ";
                    	cin >> yearOfMake;
                    	cout << endl;
                    	
			cin.clear();  //clear error bit

		 	//drop first 1000 characters up to and including
		 	//the first newline (up to length of current stream)
		 	cin.ignore( 1000, '\n' );


                    	//Asking user for month in which car is purchased
                    	cout << "Please give the month in which the car is purchased: ";
                    	cin >> monthOfDeal;
                    	cout << endl;
                    	
			cin.clear();  //clear error bit

		 	//drop first 1000 characters up to and including
		 	//the first newline (up to length of current stream)
		 	cin.ignore( 1000, '\n' );


                    	//Asking user for day on which car is purchased
                    	cout << "Please give the day in which the car is purchased: ";
                    	cin >> dayOfDeal;
                    	cout << endl;
                    	
			cin.clear();  //clear error bit

		 	//drop first 1000 characters up to and including
		 	//the first newline (up to length of current stream)
		 	cin.ignore( 1000, '\n' );


                    	//Asking user for year in which car is purchased
                    	cout << "Please give the year in which the car is purchased: ";
                    	cin >> yearOfDeal;
                    	cout << endl;
                    	
			cin.clear();  //clear error bit

		 	//drop first 1000 characters up to and including
		 	//the first newline (up to length of current stream)
		 	cin.ignore( 1000, '\n' );


                    	//Asking user for price for which car is purchased
                    	cout << "Please give the purchase price of car: ";
			cin >> priceOfCar;
                    	cout << endl;
                    	
			cin.clear();  //clear error bit

		 	//drop first 1000 characters up to and including
		 	//the first newline (up to length of current stream)
		 	cin.ignore( 1000, '\n' );

			//Asking user if this car is sold
			cout << "If this car is sold and you want to enter sale information\n";
			cout << "Enter 'y' for yes, otherwise if not sold enter 'n' for no : ";
			cin >> sold;
            		cout << endl;
			
			//If sold
			if(sold == 'y')
			{
				//Asking user for month in which car is sold
                    		cout << "Please give the month in which the car is sold: ";
                    		cin >> monthOfSell;
                    		cout << endl;
                    		
				cin.clear();  //clear error bit

		 		//drop first 1000 characters up to and including
		 		//the first newline (up to length of current stream)
		 		cin.ignore( 1000, '\n' );

                    		//Asking user for day on which car is sold
                    		cout << "Please give the day in which the car is sold: ";
                    		cin >> dayOfSell;
                    		cout << endl;
                    		
				cin.clear();  //clear error bit

		 		//drop first 1000 characters up to and including
		 		//the first newline (up to length of current stream)
		 		cin.ignore( 1000, '\n' );


                    		//Asking user for year in which car is sold
                    		cout << "Please give the year in which the car is sold: ";
                    		cin >> yearOfSell;
                    		cout << endl;
                    		
				cin.clear();  //clear error bit

		 		//drop first 1000 characters up to and including
		 		//the first newline (up to length of current stream)
		 		cin.ignore( 1000, '\n' );


                    		//Asking user for price for which car is sold
                    		cout << "Please give the selling price of car: ";
				cin >> priceOfCarSale;
                    		cout << endl;
                    		cin.clear();  //clear error bit

		 		//drop first 1000 characters up to and including
		 		//the first newline (up to length of current stream)
		 		cin.ignore( 1000, '\n' );

				sell = true;  //Assign sell to true


				
				try //try for expectation
				{
					//Car object for sold car, will also initialize Date data members
					Car carProfit(makeOfCar, modelOfCar, yearOfMake, priceOfCar, priceOfCarSale, Date(dayOfDeal, monthOfDeal, yearOfDeal), Date(dayOfSell, monthOfSell, yearOfSell), sell);
					carInvenotry.addCar(carProfit); //carLot object
					
					//function from carLot class to get profit for car
					cout << "Profit from this car is :" << carProfit.getProfit() << endl << endl;}
				
				//If expectation occurs		
				catch(const char* msg)
				{
					cerr << msg << endl << endl;

					exit(0); //wrong date exit the program
				}


			}

			//If not sold
			else
			{
				sell = false; //Assign sell to false
				
				//For expectation
				try
				{
					//Car object for purchased car, will also initialize Date data members
					Car carProfit(makeOfCar, modelOfCar, yearOfMake, priceOfCar, Date(dayOfDeal, monthOfDeal, yearOfDeal),sell);
					
					carInvenotry.addCar(carProfit); //carLot object
				
					//function from carLot class to get profit for car
					cout << "Profit from this car is :" << carProfit.getProfit() << "(No sale no profit)" << endl << endl;
				}
                		
				//If expectation occurs
				catch(const char* msg)
				{
					cerr << msg << endl << endl;

					exit(0); //wrong date exit the program
				}

				cin.clear();  //clear error bit

		 		//drop first 1000 characters up to and including
		 		//the first newline (up to length of current stream)
		 		cin.ignore( 1000, '\n' );
			}
		}

		//For second option
        	else if(option == "2")
        	{
			//If no car in car lot
			if(display == 'n')
            		{
                		cout << "Your lot is empty. There is no car.\n\n";
            		}

			//Otherwise calling a function which displays cars in lot which are not sold yet
            		else
            		{
				carInvenotry.carList();
            		}
        	}

		//For third option
		else if(option == "3")
        	{
                    	//If no car in car lot
            		if(display == 'n')
            		{
                		cout << "Your lot is empty. There is no car.\n\n";
            		}

			//Otherwise calling a function which tells the profit for month
            		else
            		{
                		carInvenotry.monthProfit();
                		
				cin.clear();  //clear error bit

		 		//drop first 1000 characters up to and including
		 		//the first newline (up to length of current stream)
		 		cin.ignore( 1000, '\n' );
            		}
        	}

		//If use chose to quit
		else if(option == "Quit")
        	{
            		cout << "You chose to exit. Thanks you.\n";
        	}

        	//If not a valid option
		else
        	{
            		cout << "Please enter valid option.\n\n";
		}


	 }while(option != "Quit");

 return 0;
 }



