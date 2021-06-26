/*STACK QUESTION 1*/

#include <stdio.h>

int rear = -1;

void enqueue(int queue[], int size)
{
	if (rear == size - 1)
	{
		printf("\nQueue Is Full\n");
		return;
	}
	else
	{
		rear++;
		printf("\nInsert the element: ");
		scanf("%d", &queue[size - rear - 1]);
	}
}

void display(int queue[], int size)
{
	if (rear == -1)
	{
		printf("\nQueue Is Empty \n");
		return;
	}
	else
	{
		printf("\nQueue: \n");
		for (int i = 0; i <= rear; i++)
			printf("%d\n", queue[i]);
	}
}

void dequeue(int queue[], int size)
{
	if (rear == -1)
	{
		printf("\nQueue Is Empty \n");
		return;
	}
	else
	{
		printf("\nDeleted Element: %d\n", queue[rear]);
		rear--;
	}
}

int main()
{
	int size;
	printf("\nEnter the size of the queue: ");
	scanf("%d", &size);
	int queue[size];

	int choice;
	do
	{
		printf("\nEnter 1 for Enqueue Operation\n");
		printf("Enter 2 to Display\n");
		printf("Enter 3 for Dequeue Operation\n");
		printf("Enter 0 to exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			enqueue(queue, size);
			break;
		case 2:
			display(queue, size);
			break;
		case 3:
			dequeue(queue, size);
			break;
		default:
			printf("\nInvalid choice\n");
			break;
		}
	} while (choice != 0);

	return 0;
}