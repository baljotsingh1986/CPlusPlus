/*Item.cpp implementation of Item.h*/

#include<iostream>

#include "Item.h"

//Default constructor
Item::Item(){}

//Constructor which assign values to attributes of Item
Item::Item(std::string name, TYPE type, int herb, double power, int armor)
{
    this->itemName = name;

    this->itemType = type;

    this->shield = armor;

    this->heal = herb;

    this->weapon = power;

}

//Function to return Item name
std::string Item::getName()
{
    return itemName;
}

//Function to return type
TYPE Item::getType()
{
    return itemType;
}

//Function to return heal
int Item::getHeal()
{
    return heal;
}

//Function to return Shield
int Item::getShield()
{
    return shield;
}

//Function to return weapon
double Item::getWeapon()
{
    return weapon;
}

//Destructor
Item::~Item()
{

}
