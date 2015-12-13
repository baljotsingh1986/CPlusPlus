/*
* AVL.cpp
*
*  Created on: Nov 14, 2015
*      Author: Baljot Singh
*/
#include <iostream>
#include<string>
#include<assert.h>
#include"AVL.h"

template <class T>
AVL<T>::AVL():trees<T>::trees()
{
}


template <class T>
int AVL<T>::getHeight(node* nod)
{
	if (nod == NULL)
	{
		return -1;
	}

	return nod->height;
}

template <class T>
void AVL<T>::setHeight(node* nod)
{
	assert(nod != NULL);
	int heightOfLeftChild = getHeight(nod->left);
	int heightOfRightChild = getHeight(nod->right);

	if (heightOfLeftChild < heightOfRightChild)
	{
		nod->height = heightOfRightChild + 1;
	}

	else
	{
		nod->height = heightOfLeftChild + 1;
	}
}

template <class T>
int AVL<T>::balanceFactor(node* nod)
{
	return getHeight(nod->right) - getHeight(nod->left);
}

template <class T>
typename AVL<T>::node* AVL<T>::rotateLeft(node* nod)
{
	std::cout << "AVL rotate left is called.\n";
	node *temp = nod->right;
	
	nod->right = temp->left;

	temp->left = nod;

	setHeight(nod);

	setHeight(temp);

	return temp;
}

template <class T>
typename AVL<T>::node* AVL<T>::rotateRight(node* nod)
{
	std::cout << "AVL rotate right is called.\n";
	node *temp = nod->left;

	nod->left = temp->right;

	temp->right = nod;

	setHeight(nod);

	setHeight(temp);

	return temp;
}

template <class T>
typename AVL<T>::node* AVL<T>::balanceTree(node* nod)
{
	if (balanceFactor(nod) < -1)
	{
		if (balanceFactor(nod->left) > 0)
		{
			nod->left = rotateLeft(nod->left);
		}

		return rotateRight(nod);
	}

	else if (balanceFactor(nod) > 1)
	{
		if (balanceFactor(nod->right) < 0)
		{
			nod->right = rotateRight(nod->right);
		}

		return rotateLeft(nod);
	}

	setHeight(nod);

	return nod;
}

template <class T>
typename AVL<T>::node* AVL<T>::insert(node* nod, T value)
{
	if (nod == NULL)
	{
		node *newNode = new node;
		newNode->val = value;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->height = 0;
		return newNode;
	}

	else if (nod->val > value)
	{
		nod->left = insert(nod->left, value);
	}

	else if (nod->val <= value)
	{
		nod->right = insert(nod->right, value);
	}

	return balanceTree(nod);
}

template <class T>
void AVL<T>::addVal(T val)
{
	root = insert(root, val);
	count++;
}

template <class T>
AVL<T>::~AVL()
{
	deleteTree(root);
}
