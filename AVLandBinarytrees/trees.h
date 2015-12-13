/*
* trees.h
*
*  Created on: Nov 14, 2015
*      Author: Baljot Singh
*/

#include<vector>

#ifndef TREES_H
#define TREES_H



template <class T>
class trees
{
private:

protected:
	class node
	{
	private:
		template <class T> friend class trees;
		template <class T> friend class bst;
		template <class T> friend class AVL;
		node* left;
		node* right;
		T val;
		int height;
	};

	node *root;

	int count;

	virtual node* insert(node* nod, T value);

	void printTree(node *nod);
	 
	void deleteTree(node* nod);

	node* removeNode(node* nod, T val);

	node* removeLeftMost(node* nod);

	T leftMostVal(node *nod);


public:
	/*Iterator class for implementation of iterator for trees*/
	class Iterator
	{
	private:
		node *root;
		std::vector<node*> container;
	public:
		Iterator()
		{
			std::vector<node*> container;
		}
		void initIterator(trees* tree)
		{
			this->root = tree->root;
		}

		bool hasNext()
		{
			if (container.empty())
			{
				while (this->root != NULL)
				{
					container.push_back(root);
					root = root->left;
				}
			}

			else
			{
				node* temp = container.back();
				node* cur;
				container.pop_back();
				if (temp->right != NULL)
				{
					cur = temp->right;
					while (cur != NULL)
					{
						container.push_back(cur);
						cur = cur->left;
					}
				}
			}

			if (container.empty())
			{
				return false;
			}

			else
			{
				return true;
			}
		}

		T next()
		{
			return container.back()->val;
		}

	};
	
	trees();

	virtual void addVal(T val) = 0;

	void removeVal(T val);

	node* contains(T val);

	bool isEmpty();

	int size();

	void print();

	~trees();
};

#endif // !TREES_H
