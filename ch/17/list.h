#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>
#define TSIZE 45

struct film
{
	char title[TSIZE];
	int rating;
};

typedef struct film Item;

typedef struct node {
	Item item;
	struct node * next;
} Node;

typedef Node * List;

/* operation 	initialize a list */
/* preconditions: plist point to a list  */
/* post conditions: the list is initialized to empty */
void InitializeList(List * plist);

/* operation 	determine if list is empty */
/* preconditions: plist points to initialized list  */
/* post conditions: function return True if list is empty 
		    and returns False if not */
bool ListIsEmpty(const List * plist);

/* operation 	determine if list is full */
/* preconditions: plist points to initialized list  */
/* post conditions: function return True if list is full 
		    and returns False if not */
bool ListIsFull(const List * plist);

/* operation 	determine if number of items in list */
/* preconditions: plist points to initialized list  */
/* post conditions: function return number of items in the list */
unsigned int ListItemCount(const List * plist);

/* operation 	add item to the end of list */
/* preconditions: item is an item to be added to list  
		  plist points to initialized list */
/* post conditions: if possible, function adds item to end of list
		    and returns True; otherwise the 
		    function rreturn False*/
bool AddItem(Item item, List * plist);

/* operation 	 apply function to each item in list */
/* preconditions plist point to an initialized list 
		 pfun points to a function that takes an
		 Item argument and has no return value */
/* post conditions: the function pointed to by pfun is executed once
		 	for each item in the list*/
void Traverse (const List *plist, void (*pfun)(Item item));

/* operation 	free allocated memory, if any
		plist points to and initialized list */
/* post conditions: any memory allocated for the list is 
		freed and the list is set to empty*/
void EmptyList(List * plist);

#endif
