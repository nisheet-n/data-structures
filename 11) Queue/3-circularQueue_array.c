#include <stdio.h>
#include <stdlib.h>

int arr[100];
int size = 0, front = -1, last = -1;

void enqueue()
{
	if (last == size - 1 && front == 0)
	{
		printf("Queue is full\n");
		return;
	}
	else if (last == front - 1)
	{
		printf("Queue is full\n");
		return;
	}
	else if (last == size - 1 && front > 0)
	{
		last = 0;
		printf("Enter data: ");
		scanf("%d", &arr[last]);
		return;
	}
	else
	{
		last++;
		if (last == 0)
		{
			front++;
		}
		printf("Enter data: ");
		scanf("%d", &arr[last]);
	}
}

void display()
{
	if (last == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	if (last >= front)
	{
		int k;
		for (int k = front; k <= last; k++)
		{
			printf("%d ", arr[k]);
		}
	}
	else
	{
		for (int i = front; i <= size - 1; i++)
		{
			printf("%d ", arr[i]);
		}
		for (int j = 0; j <= last; j++)
		{
			printf("%d ", arr[j]);
		}
	}
	printf("\n");
}

void dequeue()
{
	if (last == -1 || last == front)
	{
		last = front = -1;
		printf("Queue is empty\n");
		return;
	}
	else
	{
		if (front == size - 1)
		{
			front = 0;
			printf("Element deleted\n");
		}
		else
		{
			front++;
			printf("Element deleted\n");
		}
	}
}
int main()
{
	printf("enter the size of Queue: ");
	scanf("%d", &size);
	while (1)
	{
		printf("enter the choice:\n Press 1 to enqueue\n Press 2 to display\n Press 3 to dequeue\n Press 0 to exit\n");
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			enqueue();
			break;
		case 2:
			display();
			break;
		case 3:
			dequeue();
			break;
		default:
			exit(0);
		}
	}
}