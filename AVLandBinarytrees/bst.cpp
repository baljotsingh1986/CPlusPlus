/*
 * bst.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: Baljot Singh
 */
#include <iostream>
#include<string>
#include"bst.h"

template <class T>
bst<T>::bst():trees<T>::trees()
{
}

template <class T>
void bst<T>::addVal (T val)
{
	count++;
	root = insert(root, val);
}

template <class T>
bst<T>::~bst()
{
	deleteTree(root);
}
