#include <stdio.h>
#include "Tree.h"


int main()
{
	int input;
	Knot* tree;
	scanf("%d", &input);
	if(input != 0)
	{
		tree = malloc(sizeof(Knot));
		tree->left = NULL;
		tree->right = NULL;
		tree->value = input;
		tree-> parent = NULL;
		height = 1;
		do
		{
			scanf("%d", &input);
			if (input != 0)
			{
				addKnot(tree, input, 1);
			}
		}while(input != 0);
	}
	if(isBalanced(tree) == false)
	{
		printf("NO");
	}else
	{
		printf("YES");
	}
}
