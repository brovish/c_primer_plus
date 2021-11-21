#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void InitializeList(List * plist)
{
    plist->items = 0;
}

bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

bool ListIsFull(const List * plist)
{
    return plist->items >= MAXSIZE;
}

unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

bool AddItem(Item item, List * plist)
{
    plist->entries[plist->items] = item;
	plist->items++;
    return true;

}

void Traverse(const List * plist, void (* pfun)(Item item))
{
	for (int i = 0; i < plist->items; i++)
	{
		(* pfun)(plist->entries[i]);
	}
}

void EmptyList(List * plist)
{
    plist->items = 0;
    free(plist);
}
