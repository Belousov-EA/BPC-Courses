/*
 * Tree.h
 *
 *  Created on: May 22, 2019
 *      Author: user
 */



#ifndef TREE_H_
#define TREE_H_

#define Knot struct Knot

	Knot
	{
		Knot *left;
		Knot *right;
		int value;
	};

	int height;

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
					knot->left = newKnot;
					newHeight++;
					if(newHeight > height)
					{
						height = newHeight;
						//printf("%d", height);
					}
				}
			}
	}




#endif /* TREE_H_ */
