#include <stdio.h>

#define List struct List
#define ListItem struct ListItem

#define EMPTY 'e'

List
{
	ListItem* first;
	ListItem* last;
	int size;
};

ListItem
{
	ListItem* next;
	ListItem* before;
	char value;
};

List* newList()
{
	List* list = malloc(sizeof(List));
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return list;
}

void addBack(List* list, char value)
{
	ListItem* listItem = malloc(sizeof(ListItem));
	listItem->value = value;
	if(list->first == NULL)
	{
		list->first = listItem;
		list->last = listItem;
	}else
	{
		list->last->next = listItem;
		listItem->before = list->last;
		list->last = listItem;
	}
	list->size++;
}

void delItem(List* list, ListItem* item)
{
	if(list->size == 1)
	{
		list->first = NULL;
		list->last = NULL;
		free(item);
	}else
		if(list->first == item)
		{
			list->first = item->next;
			list->first->before = NULL;
			free(item);
		}else
			if(list->last == item)
			{
				list->last = item->before;
				list->last->next = NULL;
				free(item);
			}else
			{
				item->before->next = item->next;
				item->next->before = item->before;
				free(item);
			}
	list->size--;
}

int main()
{
	char input = getchar();
	List* list = newList();
	while(input != '\n')
	{
		addBack(list, input);
		input = getchar();
	}
	while(list->size > 1)
	{
		int size = list->size;
		ListItem* secondIter = list->first;
		ListItem* firstIter = secondIter->next;
		do{
			if((firstIter->value == ']'&& secondIter->value == '[')||
								(firstIter->value == '}'&& secondIter->value == '{')||
								(firstIter->value == ')'&& secondIter->value == '('))
			{
				ListItem* forDel1 = firstIter;
				ListItem* forDel2 = secondIter;
				if(firstIter->next != NULL)
				{
					firstIter = firstIter->next->next;
				}else
				{
					firstIter = firstIter->next;
				}


				secondIter = secondIter->next->next;

				delItem(list, forDel1);
				delItem(list, forDel2);
			}else{
				firstIter = firstIter->next;
				secondIter = secondIter->next;
			}
		}while(firstIter != list->last && firstIter != NULL);
		if(size == list->size)
		{
			puts("no");
			return 0;
		}
	}
	puts("yes");
	return 0;
}
