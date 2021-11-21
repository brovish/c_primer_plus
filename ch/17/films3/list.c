#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static void CopyToNode(Item item, Node * pnode);

void InitializeList(List * plist)
{
    plist->end = NULL;
    plist->head = NULL;
}

bool ListIsEmpty(const List * plist)
{
    if (plist->head == NULL)
        return true;
    else
        return false;
}

bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full = false;
    pt = (Node *) malloc(sizeof(Node));

    if (pt == NULL)
        full = true;

    free(pt);

    return full;
}

unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;

    if (plist->head == NULL)
		return count;

    Node * pnode = plist->head;

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
    }

    return count;
}

bool AddItem(Item item, List * plist)
{
    Node * pnew;
    Node * scan = plist->head;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;

    CopyToNode(item, pnew);

    pnew->next = NULL;
    if (scan == NULL)
	{
		plist->head = pnew;
		plist->end = NULL;
	}
    else
    {
        while (scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }

    return true;

}

void Traverse(const List * plist, void (* pfun)(Item item))
{
    Node * pnode = plist->head;
    while (pnode != NULL)
    {
        (* pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyList(List * plist)
{
    Node * psave;
    while (plist->end != NULL)
    {
        psave = plist->end;
        free(plist);
        plist->head = psave;
    }
}

static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}

