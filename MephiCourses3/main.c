#include <stdio.h>
#include <string.h>

//реализуем стек
#define StackItem struct StackItem
#define Stack struct Stack


Stack
{
	StackItem* item;
	int size;
};

StackItem
{
	int value;
	StackItem* next;
};

Stack* newStack()
{
	Stack* stack = malloc(sizeof(Stack));
	stack->size = 0;
	stack->item = NULL;
	return stack;
}

void push(Stack* stack, int value)
{
	StackItem* item = malloc(sizeof(StackItem));
	item->value = value;
	item->next = stack->item;
	stack->item = item;
	(stack->size)++;
}

int pop(Stack* stack)
{
	int popValue = -1;
	if(stack->item != NULL)
	{
		popValue = stack->item->value;
		//удаление
		StackItem* item = stack->item;
		stack->item = stack->item->next;
		(stack->size)--;
		free(item);
	}
	return popValue;
}

int back(Stack* stack)
{
	int backValue = -1;
	if(stack -> item!= NULL)
	{
		backValue = stack->item->value;
	}
	return backValue;
}

int size(Stack* stack)
{
	return stack->size;
}

void clear(Stack* stack)
{
	while(stack->item != NULL)
	{
		int i = pop(stack);
	}
}

void deleteStack(Stack* stack)
{
	clear(stack);
	free(stack);
}



int main()
{
	char comand1;
	char comand2;
	int value;
	Stack* stack = newStack();
	while(1)
	{
		comand1 = getchar();
		comand2 = getchar();
		if((comand1=='p')&&(comand2 =='u'))
		{
			comand1=getchar();
			comand1=getchar();
			scanf("%d", &value);
			comand1 = getchar();
			push(stack, value);
			printf("ok\n");
		}else
			if((comand1 == 'p')&&(comand2 == 'o'))
			{
				comand1=getchar();
				comand1=getchar();
				value = pop(stack);
				printf("%d\n", value);
			}else
				if(comand1 == 'b')
				{
					comand1=getchar();
					comand1=getchar();
					comand1=getchar();
					value = back(stack);
					printf("%d\n", value);
				}else
					if(comand1 == 's')
					{
						comand1=getchar();
						comand1=getchar();
						comand1=getchar();
						value = size(stack);
						printf("%d\n", value);
					}else
						if(comand1 == 'c')
						{
							comand1=getchar();
							comand1=getchar();
							comand1=getchar();
							comand1=getchar();
							clear(stack);
							printf("ok\n");
						}else
							if(comand1 == 'e')
							{
								puts("bye");
								deleteStack(stack);
								return 0;
							}
	}
}



