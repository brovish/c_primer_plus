#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdbool.h>
#define STACK_MAX_SIZE 10

typedef int Item;

typedef struct node
{
	Item item;
	struct Node * next;
} Node;

typedef struct stack
{
	Node * next;
	Node * rear;
	int size;
} Stack;

void InitializeStack(Stack * ps);

bool StackIsFull(const Stack * ps);

bool StackIsEmpty(const Stack * ps);

void Pop(Stack * ps);

bool Push(Item * pitem, Stack * ps);

bool EmptyStack(Stack * ps);

void Traverse(const Stack * ps, void (*pfun)(Item item));

#endif // STACK_H_INCLUDED
