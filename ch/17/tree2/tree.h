#ifndef _TREE_H_INCLUDED_
#define _TREE_H_INCLUDED_
#include <stdbool.h>
#define MAX_WORD_SZ 100

#define MAXITEMS 200000

typedef struct item
{
	char word[MAX_WORD_SZ];
	int cnt;
} Item;

typedef struct trnode
{
	Item item;
	struct trnode * left;
	struct trnode * right;
} Trnode;

typedef struct tree
{
	Trnode * root;
	int size;
} Tree;

void InitalizeTree(Tree * ptree);

bool TreeIsEmpty(const Tree * ptree);

bool TreeIsFull(const Tree * ptree);

int TreeItemCount(const Tree * ptree);

bool AddItem(Item * pi, Tree * ptree);

bool InTree(const Item * pi, const Tree * ptree);

bool DeleteItem(const Item * pi, Tree * ptree);

void Traverse(const Tree * ptree, void (*pfun)(Item item));

void DeleteAll(Tree * ptree);

Item GetTreeNode(const Item * pi, const Tree * ptree);

#endif // _TREE_H_INCLUDED_
