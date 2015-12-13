/************************
* Items.h file
************************/
 #ifndef ITEMS_H
 #define ITEMS_H

 #include <string>
 #include "Items.h"

 using namespace std;

 //Items class declaration
 class Items
 {
	 private:
		string name; //String name

		string unit; //Unit of item

     		double price; //Price of item

     		double quantity; //quantity as int

	 public:
		Items(); //Default constructor

     		//constructor which takes two strings and two doubles as parameter
		Items(string itemName, string itemUnit, double itemPrice, double itemQuantity);

		//Method to set unit
		void setUnit(string unit_item);

		//Method to set price
		void setPrice(double unit_price);

		//Method to set quantiy
		void setQuantity(int unit_quantity);

		//Method to get name
		string getName();

		//Method to get unit
		string getUnit();

		//Method to get quantity
		double getQuantity();
	
	       	//Method to get price
		double getPrice();
 };

#endif // ITEMS_H

