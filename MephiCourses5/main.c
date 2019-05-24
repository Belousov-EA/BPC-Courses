#include <stdio.h>
//#include <stdlib.h>

#define Deck struct Deck
#define DeckItem struct DeckItem

DeckItem
{
	DeckItem* next;
	DeckItem* prev;
	int value;
};

Deck
{
	DeckItem* start;
	DeckItem* end;
	int size;
};

Deck* newDeck()
{
	Deck* deck = malloc(sizeof(Deck));
	deck->end = NULL;
	deck->start = NULL;
	deck->size = 0;
	return deck;
}

void pushFront(Deck* deck, int value)
{
	DeckItem* deckItem = malloc(sizeof(DeckItem));
	deckItem->value = value;
	deckItem->prev = NULL;
	if(deck->size == 0)
	{
		deckItem->next = NULL;
		deck->end = deckItem;
		deck->start = deckItem;
	}else
	{
		deckItem->next = deck->start;
		deck->start->prev = deckItem;
		deck->start = deckItem;
	}
	deck->size++;
}

void pushBack(Deck* deck, int value)
{
	DeckItem* deckItem = malloc(sizeof(DeckItem));
	deckItem->value = value;
	deckItem->next = NULL;
	if(deck->size == 0)
	{
		deckItem->prev = NULL;
		deck->end = deckItem;
		deck->start = deckItem;
	}else
	{
		deckItem->prev = deck->end;
		deck->end->next = deckItem;
		deck->end = deckItem;
	}
	deck->size++;
}

int popFront(Deck* deck)
{
	int value = -1;
	if(deck->size > 0)
	{
		value = deck->start->value;
		if(deck->size == 1)
		{
			free(deck->start);
			deck->start = NULL;
			deck->end = NULL;
		}else
		{
			DeckItem* deckItem = deck->start;
			deck->start = deckItem->next;
			deck->start->prev = NULL;
			free(deckItem);
		}
		deck->size--;
	}
	return value;
}

int popBack(Deck* deck)
{
	int value = -1;
	if(deck->size > 0)
	{
		value = deck->end->value;
		if(deck->size == 1)
		{
			free(deck->end);
			deck->start = NULL;
			deck->end = NULL;
		}else
		{
			DeckItem* deckItem = deck->end;
			deck->end = deckItem->prev;
			deck->end->next = NULL;
			free(deckItem);
		}
		deck->size--;
	}
	return value;
}

int front(Deck* deck)
{
	int value = -1;
	if(deck->size > 0)
	{
		value = deck->start->value;
	}
	return value;
}

int back(Deck* deck)
{
	int value = -1;
	if(deck->size > 0)
	{
		value = deck->end->value;
	}
	return value;
}

int size(Deck* deck)
{
	return deck->size;
}

void clear(Deck* deck)
{
	while(deck->size != 0)
	{
		int a = popBack(deck);
	}
}

void deleteDeck(Deck* deck)
{
	clear(deck);
	free(deck);
}

int main()
{
	char comand1;
	char comand2;
	int value;
	Deck* deck = newDeck();
	while(1)
	{
		comand1 = getchar();
		comand2 = getchar();
		if((comand1=='p')&&(comand2 =='u'))
		{
			comand1=getchar();
			comand1=getchar();
			comand1=getchar();
			comand1=getchar();
			if(comand1 == 'f')
			{
				comand1=getchar();
				comand1=getchar();
				comand1=getchar();
				comand1=getchar();
				scanf("%d", &value);
				comand1 = getchar();
				pushFront(deck, value);
				printf("ok\n");
			}else
			{
				comand1=getchar();
				comand1=getchar();
				comand1=getchar();
				scanf("%d", &value);
				comand1 = getchar();
				pushBack(deck, value);
				printf("ok\n");
			}
		}else
			if((comand1 == 'p')&&(comand2 == 'o'))
			{
				comand1=getchar();
				comand1=getchar();
				comand1=getchar();
				if(comand1 == 'f')
				{
					comand1=getchar();
					comand1=getchar();
					comand1=getchar();
					comand1=getchar();
					comand1=getchar();
					value = popFront(deck);
					printf("%d\n", value);
				}else
				{
					comand1=getchar();
					comand1=getchar();
					comand1=getchar();
					comand1=getchar();
					value = popBack(deck);
					printf("%d\n", value);
				}
			}else
				if(comand1 == 'f')
				{
					comand1=getchar();
					comand1=getchar();
					comand1=getchar();
					comand1=getchar();
					value = front(deck);
					printf("%d\n", value);
				}else
					if(comand1 == 's')
					{
						comand1=getchar();
						comand1=getchar();
						comand1=getchar();
						value = size(deck);
						printf("%d\n", value);
					}else
						if(comand1 == 'c')
						{
							comand1=getchar();
							comand1=getchar();
							comand1=getchar();
							comand1=getchar();
							clear(deck);
							printf("ok\n");
						}else
							if(comand1 == 'e')
							{
								puts("bye");
								deleteDeck(deck);
								return 0;
							}else
								if(comand1 == 'b')
								{
									comand1=getchar();
									comand1=getchar();
									comand1=getchar();
									value = back(deck);
									printf("%d\n", value);
								}
	}
}



