/*
 * main.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: Baljot Singh
 */

#include <iostream>
#include<string>

#include "trees.h"
#include "trees.cpp"
#include "bst.h"
#include "bst.cpp"
#include "AVL.h"
#include "AVL.cpp"

int main()
{
	trees<double> *tree1 = new bst <double>();

	trees<std::string> *tree = new bst <std::string>();

	trees<int> *AVLtree = new AVL <int>();

	trees<double>::Iterator it1;

	trees<std::string>::Iterator it2;

	trees<int>::Iterator it3;

	tree->addVal("AB");
	tree->addVal("BC");
	tree->addVal("cC");
	tree->addVal("CD");
	tree->addVal("DC");
	tree->addVal("DC");
	
	tree1->addVal(5.7);
	tree1->addVal(4.7);
	tree1->addVal(6.9);
	tree1->addVal(1.5);
	tree1->addVal(2.3);
	tree1->addVal(3.5);

	it1.initIterator(tree1);

	it2.initIterator(tree);

	std::cout << "Traversing bst tree of doubles using iterator.\n";
	while (it1.hasNext())
	{
		std::cout << "IT: " << it1.next() << std::endl;
	}

	std::cout << "\nTraversing bst tree of strings using iterator.\n";
	while (it2.hasNext())
	{
		std::cout << "IT: " << it2.next() << std::endl;
	}

	std::cout << "\nAdding values to AVL tree and showing when rotateLeft and rotateRight is called.\n";
	AVLtree->addVal(1);
	AVLtree->addVal(2);
	AVLtree->addVal(3);
	AVLtree->addVal(4);
	AVLtree->addVal(5);
	AVLtree->addVal(6);
	AVLtree->addVal(7);
	AVLtree->addVal(-6);
	AVLtree->addVal(-5);
	AVLtree->addVal(-7);

	it3.initIterator(AVLtree);
	std::cout << "\nTraversing AVL tree of integer using iterator.\n";
	while (it3.hasNext())
	{
		std::cout << "IT: " << it3.next() << std::endl;
	}

	tree->removeVal("AB");

	tree->removeVal("BC");

	if (!tree->contains("AB"))
	{
		std::cout << "AB is removed.\n";
	}

	if (!tree->contains("BC"))
	{
		std::cout << "BC is removed.\n";
	}

	if (tree->contains("cC"))
	{
		std::cout << "Has cC.\n";
	}
	
	/*Printing inorder traversal of trees*/
	std::cout << "\nIn order traversal bst tree of strings.\n\n";
	tree->print();

	std::cout << "\nIn order traversal bst tree of doubles.\n\n";
	tree1->print();

	std::cout << "\nIn order traversal AVL tree of integers.\n\n";
	AVLtree->print();

	std::cout << "\nSize of bst tree of strings: " << tree->size() << "\nEnd of trees\n";

	delete tree1;
	delete tree;
	delete AVLtree;
	
	return 0;
}
