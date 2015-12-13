/************************
* ShoppingCart.h file
************************/
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Items.h"

#include "ShoppingCart.h"

#include <vector>
#include <iomanip>
#include <fstream>

class Items;

class ShoppingCart
 {
 	private:
		 vector <Items> cart; //A vector cart instance of class Items

       	public:

		 void clearVector();
		
	 	//function to add items to vector cart
	 	void addItem(Items shopCart);

	 	//function to list items
	 	void listItems();
	 
		//function to edit item
	 	void editItem(string name_item, fstream &dataFile);
		
		//function to remove item
	 	void removeItem(string name_item, fstream &dataFile);
 };
#endif // SHOPPINGCART_H

