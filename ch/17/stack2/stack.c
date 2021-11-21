#include <stdio.h>
#include "stack.h"

void InitializeStack(Stack * ps)
{
	ps->top = 0;
}

bool FullStack(const Stack * ps)
{
	return ps->top + 1 > MAXSTACK;
}

bool EmptyStack(const Stack * ps)
{
	return ps->top == 0;
}

/* operation: push item onto top of stack */
/* precondition: ps points to previously initialized stack */
/* item is to be placed on top of stack */
/* postcondition: if stack is not full, item is placed at */
/* top of stack and function returns */
/* true; otherwise, stack is unchanged and */
/* function returns false */
bool Push(Item item, Stack * ps)
{
	if (FullStack(ps))
		return false;
	else
	{
			ps->items[ps->top] = item;
			ps->top++;
			return true;
	}
}


/* operation: remove item from top of stack */
/* precondition: ps points to previously initialized stack */
/* postcondition: if stack is not empty, item at top of */
/* stack is copied to *pitem and deleted from */
/* stack, and function returns true; if the */
/* operation empties the stack, the stack is */
/* reset to empty. If the stack is empty to */
/* begin with, stack is unchanged and the */
/* function returns false */
bool Pop(Item *pitem, Stack * ps)
{
	if (EmptyStack(ps))
		return false;
	else
	{
        *pitem = ps->items[ps->top - 1];
		ps->top--;
		return true;
	}
}
