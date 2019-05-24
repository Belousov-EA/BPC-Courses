/*
 * Tree.h
 *
 *  Created on: May 22, 2019
 *      Author: user
 */



#ifndef TREE_H_
#define TREE_H_

#define Knot struct Knot
#define true 1
#define false 0

#define UP 0
#define DOWN 1

	Knot
	{
		Knot *left;
		Knot *right;
		int value;
		Knot* parent;
	};

	int height;
	int isTreeBalanced;

	void addKnot(Knot* knot, int value, int newHeight)
	{
		if (knot->value < value)
		{
			if(knot->right != NULL)
			{
				addKnot(knot->right, value, ++newHeight);
			}else
			{
				Knot* newKnot = malloc(sizeof(Knot));
				newKnot-> value = value;
				newKnot-> left = NULL;
				newKnot-> right = NULL;
				newKnot->parent = knot;
				knot->right = newKnot;
				newHeight++;
				if(newHeight > height)
				{
					height = newHeight;
					//printf("%d", height);
				}
			}
		}else
			if(knot->value > value)
			{
				if(knot->left != NULL)
				{
					addKnot(knot->left, value, ++newHeight);
				}else
				{
					Knot* newKnot = malloc(sizeof(Knot));
					newKnot-> value = value;
					newKnot-> left = NULL;
					newKnot-> right = NULL;
					newKnot->parent = knot;
					knot->left = newKnot;
					newHeight++;
					if(newHeight > height)
					{
						height = newHeight;
					}
				}
			}
	}


	void findNullKnot(Knot* tree, int state, Knot* prevKnot)
	{
		if(tree->parent != NULL)
		{
			if(tree->parent->parent != NULL)
			{
				if(tree->parent->parent->left == NULL || tree->parent->parent->right == NULL)
				{
					isTreeBalanced = false;
					return;
				}
			}
		}
		if(state == DOWN)
		{
			if(tree->left != NULL)
			{
				findNullKnot(tree->left, DOWN, tree);
				return;
			}
			if(tree -> right != NULL)
			{
				findNullKnot(tree->right, DOWN, tree);
				return;
			}
			findNullKnot(tree->parent, UP, tree);
			return;
		}
		if(state == UP)
		{
			if(prevKnot == tree->left)
			{
				if(tree->right != NULL)
				{
					findNullKnot(tree->right, DOWN, tree);
					return;
				}
				findNullKnot(tree->parent, UP, tree);
				return;
			}
			if(tree->parent != NULL)
			{
				findNullKnot(tree->parent, UP, tree);
				return;
			}
			return;
		}
	}


	int isBalanced(Knot* tree)
	{
		isTreeBalanced = true;
		findNullKnot(tree, DOWN, tree->parent);
		return isTreeBalanced;
	}


#endif /* TREE_H_ */
