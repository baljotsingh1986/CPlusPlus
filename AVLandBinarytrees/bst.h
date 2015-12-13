/*
 * bst.h
 *
 *  Created on: Nov 14, 2015
 *      Author: Baljot Singh
 */

#ifndef BST_H_
#define BST_H_

#include "trees.h"

template <class T>
class bst: public trees<T>
{
private:

public:
	bst();

	void addVal(T val);

	~bst();
};

#endif /* BST_H_ */
