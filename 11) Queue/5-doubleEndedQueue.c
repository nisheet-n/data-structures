#include <stdio.h>
#define MAX 5
int deque[MAX];
int rear = -1;
int front = -1;
void insertAtFront();
void insertAtRear();
void deleteAtFront();
void deleteAtRear();
void display();

int main()
{
	int option;

	printf("\n\n DEQUE");
	printf("\n 1. Insert at front");
	printf("\n 2. Insert at rear");
	printf("\n 3. Delete from front");
	printf("\n 4. Delete from rear");
	printf("\n 5. Display");
	printf("\n 6. Quit");
	do
	{
		printf("\n Enter your option : ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			insertAtFront();
			break;
		case 2:
			insertAtRear();
			break;
		case 3:
			deleteAtFront();
			break;
		case 4:
			deleteAtRear();
			break;
		case 5:
			display();
			break;
		case 6:
			break;
		default:
			printf("Wrong Choice ...\n");
		}
	} while (option != 6);
	return 0;
}

void insertAtFront()
{
	int item;
	if (front == (rear + 1) % MAX)
	{
		printf("Deque Overflow...\n");
		return;
	}
	printf("\n Enter the value: ");
	scanf("%d", &item);

	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
	else if (front == 0)
		front = MAX - 1;
	else
		front = front - 1;
	deque[front] = item;
}

void insertAtRear()
{
	int item;
	if (front == (rear + 1) % MAX)
	{
		printf("Deque Overflow...\n");
		return;
	}
	printf("\n Enter the value: ");
	scanf("%d", &item);

	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
		rear = (rear + 1) % MAX;
	deque[rear] = item;
}
void deleteAtFront()
{
	if (front == -1)
	{
		printf("\nDeque Underflow...\n");
		return;
	}
	printf("\nElement is : %d", deque[front]);
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front = (front + 1) % MAX;
}
void deleteAtRear()
{
	if (front == -1)
	{
		printf("\nDeque Underflow...\n");
		return;
	}
	printf("\nElement is : %d", deque[rear]);
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (rear == 0)
		rear = MAX - 1;
	else
		rear = rear - 1;
}
void display()
{
	int f = front, r = rear;
	if (front == -1)
	{
		printf("\n Empty Deque...\n");
		return;
	}
	printf("\nThe elements of the Deque are : ");
	if (f <= r)
		while (f <= r)
		{
			printf("%d ", deque[f]);

			f++;
		}
	else
	{
		while (f <= MAX - 1)
		{
			printf("%d ", deque[f]);

			f++;
		}
		f = 0;
		while (f <= r)
		{
			printf("%d ", deque[f]);

			f++;
		}
	}
	printf("\n");
}
