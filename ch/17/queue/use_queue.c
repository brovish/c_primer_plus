#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void TraverseQueue(const Queue * pq);
void ListQueue(const Queue * pq);


int main(int argc, char *argv[])
{
	Queue line;
	Item temp;
	char ch;

	InitializeQueue(&line);
	puts("Testing the Queue interface. Type a to add a value,");
	puts("type d to delete a value, and type q to exit.");

	while ((ch = getchar()) != 'q')
	{
		if (ch != 'a' && ch != 'd')
		{
			continue;
		}
		if (ch == 'a')
		{
			printf("Integer to add: ");
			scanf("%d", &temp);
			if (!QueueIsFull(&line))
			{
				printf("Putting %d into queue\n", temp);
				EnQueue(temp, &line);
			}
			else
				puts("Queue is full.");
		}
		else
		{
			if (QueueIsEmpty(&line))
				puts("Nothing to delete.");
			else
			{
				DeQueue(&temp, &line);
				printf("Removing %d from queue\n", temp);
			}
		}

		ListQueue(&line);
		puts("Type a to add, d to delete, q to quit.");

	}

	EmptyQueue(&line);

    return 0;
}

void ListQueue(const Queue * pq)
{
	system("cls");
	if (QueueIsEmpty(pq))
	{
		printf("\nQueue is empty.\n");
		return;
	}
	else
		printf("\nItems:\n");

	Node * pnode;
	pnode = pq->front;

	int i = 1;

	while (pnode != NULL)
	{
		printf("%d item: %d\n", i, pnode->item);
		pnode = pnode->next;
		i++;
	}
}

void TraverseQueue(const Queue * pq)
{
    printf("Queue is %s, %d items\n",
           QueueIsEmpty(pq) == true ? "empty" : "not empty", QueueItemCount(pq));

}
