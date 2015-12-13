/*
* AVL.h
*
*  Created on: Nov 14, 2015
*      Author: Baljot Singh
*/

#ifndef AVL_H_
#define AVL_H_

#include "trees.h"

template <class T>
class AVL : public trees<T>
{
private:

	node* insert(node* nod, T value);

	void setHeight(node* nod);

	int getHeight(node* nod);

	node* balanceTree(node* nod);

	node* rotateLeft(node* nod);

	node* rotateRight(node* nod);

	int balanceFactor(node* nod);  

public:
	AVL();

	void addVal(T val);

	~AVL();
};

#endif /* AVL_H_ */
