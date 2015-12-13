/*
* trees.cpp
*
*  Created on: Nov 14, 2015
*      Author: Baljot Singh
*/

#include <iostream>
#include<string>
#include"trees.h"

template <class T>
trees<T>::trees()
{
	count = 0;
	root = NULL;

}

template <class T>
typename trees<T>::node* trees<T>::insert(node* nod, T value)
{
	if (nod == NULL)
	{
		node *newNode = new node;
		newNode->val = value;
		newNode->left = NULL;
		newNode->right = NULL;
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

	return nod;
}

template <class T>
typename trees<T>::node* trees<T>::contains(T val)
{
	node *temp = root;
	while (temp != NULL)
	{
		if (temp->val == val)
		{
			return temp;
		}

		else if (val < temp->val)
		{
			temp = temp->left;
		}

		else
		{
			temp = temp->right;
		}
	}

	return NULL;
}

template <class T>
void trees<T>::printTree(node *nod)
{
	if (nod != NULL)
	{
		printTree(nod->left);
		std::cout << "Value: " << nod->val << std::endl;
		
		printTree(nod->right);
	}
}

template <class T>
void trees<T>::deleteTree(node* nod)
{
	if (nod != NULL)
	{
		deleteTree(nod->left);
		deleteTree(nod->right);
		delete nod;
	}
}

template <class T>
typename trees<T>::node* trees<T>::removeLeftMost(node* nod)
{
	if (nod->left == NULL)
	{
		node* temp = nod;
		nod = nod->right;
		delete temp;
	}
	else
	{
		nod->left = removeLeftMost(nod->left);
	}
	return nod;
}

template <class T>
T trees<T>::leftMostVal(node *nod)
{
	node* temp = nod;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}

	return temp->val;
}

template <class T>
typename trees<T>::node* trees<T>::removeNode(node* nod, T val)
{
	if (nod->val == val)
	{
		if (nod->right == NULL)
		{
			node* temp;
			temp = nod;
			nod = nod->left;
			delete temp;
		}

		else
		{
			nod->val = leftMostVal(nod->right);
			nod->right = removeLeftMost(nod->right);
		}
	}

	else if (nod->val < val)
	{
		nod->right = removeNode(nod->right, val);
	}

	else
	{
		nod->left = removeNode(nod->left, val);
	}

	return nod;
}

template <class T>
void trees<T>::removeVal(T val)
{
	if (contains(val))
	{
		root = removeNode(root, val);
		count--;
	}
}

template <class T>
void trees<T>::print()
{
	printTree(root);

}

template <class T>
int trees<T>::size()
{
	return count;
}

template <class T>
trees<T>::~trees()
{
	std::cout << "Destructor is called.\n";
	deleteTree(root);
}
