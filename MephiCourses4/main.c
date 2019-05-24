#include <stdio.h>
#include <string.h>

//реализуем очередь
#define QueryItem struct QueryItem
#define Query struct Query


Query
{
	QueryItem* start;
	QueryItem* end;
	int size;
};

QueryItem
{
	int value;
	QueryItem* next;
};

Query* newQuery()
{
	Query* query = malloc(sizeof(Query));
	query->size = 0;
	query->start = NULL;
	query -> end = NULL;
	return query;
}

void push(Query* query, int value)
{
	QueryItem *queryItem = malloc(sizeof(QueryItem));
	queryItem->next = NULL;
	queryItem->value = value;
	if(query->start == NULL)
	{
		query->start = queryItem;
		query->end = queryItem;
	}else
	{
		query->end->next = queryItem;
		query->end = queryItem;
	}
	query->size++;
}

int pop(Query* query)
{
	int value = -1;
	if(query->start !=NULL)
	{
		value = query -> start->value;
		if(query->size == 1)
		{
			free(query->start);
			query->start = NULL;
			query->end = NULL;
		}else
		{
			QueryItem* queryItem = query->start;
			query->start = query->start->next;
			free(queryItem);
		}
		query->size--;
	}
	return value;
}

int front(Query* query)
{
	int value = -1;
	if(query->size > 0)
	{
		value = query->start->value;
	}
	return value;
}

int size(Query* query)
{
	return query->size;
}

void clear(Query* query)
{
	while(query->size != 0)
	{
		int a = pop(query);
	}
}

void deleteQuery(Query* query)
{
	clear(query);
	free(query);
}



int main()
{
	char comand1;
	char comand2;
	int value;
	Query* query = newQuery();
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
			push(query, value);
			printf("ok\n");
		}else
			if((comand1 == 'p')&&(comand2 == 'o'))
			{
				comand1=getchar();
				comand1=getchar();
				value = pop(query);
				printf("%d\n", value);
			}else
				if(comand1 == 'f')
				{
					comand1=getchar();
					comand1=getchar();
					comand1=getchar();
					comand1=getchar();
					value = front(query);
					printf("%d\n", value);
				}else
					if(comand1 == 's')
					{
						comand1=getchar();
						comand1=getchar();
						comand1=getchar();
						value = size(query);
						printf("%d\n", value);
					}else
						if(comand1 == 'c')
						{
							comand1=getchar();
							comand1=getchar();
							comand1=getchar();
							comand1=getchar();
							clear(query);
							printf("ok\n");
						}else
							if(comand1 == 'e')
							{
								puts("bye");
								deleteQuery(query);
								return 0;
							}
	}
}



