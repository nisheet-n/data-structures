#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *last;

struct Node *createNodeCLL(int num)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->next = NULL;
	return newNode;
}

void insertAtTailCLL()
{
	int x;
	scanf("%d", &x);
	struct Node *newNode = createNodeCLL(x);
	if (last == NULL)
	{
		last = newNode;
		last->next = newNode;
		newNode->next = newNode;
		return;
	}
	newNode->next = last->next;
	last->next = newNode;
	last = newNode;
}

/* ERROR IN WHILE as while is Entry-controlled loop and do while is Exit-controlled loop
----------------------------------------------------------------
void forwardTraverseCLL()
{
	struct Node *temp = last->next;

	printf("\nForward List: ");
	if (last == NULL)
	{
		printf("Circular linked List is empty.\n");
		return;
	}

	while (temp != last->next)
	{
		printf("| %d || %u |-->", temp->data, temp->next);
		temp = temp->next;
	} 

	if (temp == last->next)
		printf("| %d |...\n", temp->data);
} */

void forwardTraverseCLL()
{
	struct Node *temp = last->next;

	printf("\nForward List: ");
	if (last == NULL)
	{
		printf("Circular linked List is empty.\n");
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
		printf("\nEnter 1 for creating CLL\n");
		printf("Enter 2 for traversing forward\n");
		printf("Enter 3 for inserting at the end\n");
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
				insertAtTailCLL();
			}
			break;
		case 2:
			forwardTraverseCLL();
			break;
		case 3:
			printf("\nEnter the data: ");
			insertAtTailCLL();
			break;
		default:
			printf("\nInvalid choice\n");
			break;
		}

	} while (choice != 0);

	return 0;
}