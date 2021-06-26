#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *front;
struct Node *last;

struct Node *createNodeC_Queue(int num)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->next = NULL;
	return newNode;
}

void C_Enqueue()
{
	int x;
	scanf("%d", &x);
	struct Node *newNode = createNodeC_Queue(x);
	if (last == NULL)
	{
		front = newNode;
		last = newNode;
		last->next = front;
		return;
	}
	newNode->next = front;
	front = newNode;
}

void C_Dequeue()
{
	if (last == NULL)
	{
		printf("\nCircular linked List is empty.\n");
		return;
	}
	else
	{
		struct Node *temp = front;
		printf("\nDeleted Element: %d\n", last->data);
		while (temp->next != last)
			temp = temp->next;
		free(temp->next);
		temp = last;
		temp->next = front;
	}
}

void displayC_Queue()
{
	struct Node *temp = front;

	printf("\nForward List: ");
	if (front == NULL)
	{
		printf("\nCircular linked List is empty.\n");
		return;
	}
	do
	{
		printf("| %d || %u |-->", temp->data, temp->next);
		temp = temp->next;
	} while (temp != last->next);

	if (temp == last->next)
		printf("| %d |...\n", temp->data);
}

int main()
{
	int n;
	int choice;
	do
	{
		printf("\nEnter 1 to Enqueue\n");
		printf("Enter 2 for traversing forward\n");
		printf("Enter 3 to Dequeue\n");
		printf("Enter 0 to exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nInput the number of nodes: ");
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
			{
				printf("Enter node %d: ", i + 1);
				C_Enqueue();
			}
			break;
		case 2:
			displayC_Queue();
			break;
		case 3:
			C_Dequeue();
			break;
		default:
			printf("\nInvalid choice\n");
			break;
		}

	} while (choice != 0);

	return 0;
}