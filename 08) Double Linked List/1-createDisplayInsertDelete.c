#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};

struct Node *head;

struct Node *createNodeDLL(int num)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void insertAtHeadDLL()
{
	int x;
	scanf("%d", &x);
	struct Node *newNode = createNodeDLL(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void insertAtTailDLL()
{
	int x;
	scanf("%d", &x);
	struct Node *temp = head;
	struct Node *newNode = createNodeDLL(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
}

void insertAtPosDLL()
{
	int pos, x, counter = 1;
	printf("\nEnter the position: ");
	scanf("%d", &pos);
	printf("Enter the data: ");
	scanf("%d", &x);
	struct Node *newNode = createNodeDLL(x);

	struct Node *temp = head;
	if (head == NULL)
		return;
	while (counter < pos - 1)
	{
		temp = temp->next;
		counter++;
	}
	newNode->next = temp->next;
	temp->next->prev = newNode;
	newNode->prev = temp;
	temp->next = newNode;
}

void forwardTraverseDLL()
{
	struct Node *temp = head;
	printf("\nForward List: ");
	while (temp != NULL)
	{
		printf(" <--> | %u || %d || %u |", temp->prev, temp->data, temp->next);
		temp = temp->next;
	}
	printf("\n");
}

void reverseTraverseDLL()
{
	struct Node *temp = head;
	if (temp == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	printf("\nReverse List: ");
	while (temp != NULL)
	{
		printf(" <--> | %u || %d || %u |", temp->next, temp->data, temp->prev);
		temp = temp->prev;
	}
	printf("\n");
}

void deleteAtHeadDLL()
{
	struct Node *temp = head;
	if (head == NULL)
	{
		printf("\nEmpty List!\n");
		return;
	}
	head = head->next;
	printf("\nDeleted Value: %d\n", temp->data);
	free(temp);
	head->prev = NULL;
}

void deleteAtTailDLL()
{
	struct Node *temp = head;
	if (head == NULL)
	{
		printf("\nEmpty List!");
		return;
	}
	while (temp->next->next != NULL)
		temp = temp->next;
	printf("\nDeleted Value: %d\n", temp->next->data);
	temp->next = NULL;
	free(temp->next);
}

void deleteAtPosDLL()
{
	int pos, counter = 1;
	printf("\nEnter the position: ");
	scanf("%d", &pos);
	struct Node *temp = head;
	if (head == NULL)
		return;
	while (counter < pos - 1)
	{
		temp = temp->next;
		counter++;
	}
	printf("Deleted Value: %d\n", temp->next->data);
	struct Node *temp2;
	temp2 = temp->next;
	temp->next->next->prev = temp;
	temp->next = temp->next->next;
	free(temp2);
}

int main()
{
	int n;
	int choice;
	printf("\nEnter 1 for creating DLL\n");
	printf("Enter 2 for traversing forward\n");
	printf("Enter 3 for traversing backward\n");
	printf("Enter 4 for inserting at the start\n");
	printf("Enter 5 for inserting at the end\n");
	printf("Enter 6 for inserting at any position\n");
	printf("Enter 7 for deleting at the start\n");
	printf("Enter 8 for deleting at the end\n");
	printf("Enter 9 for deleting at any position\n");
	printf("Enter 0 to exit\n");
	scanf("%d", &choice);

	do
	{
		switch (choice)
		{
		case 1:
			printf("\nInput the number of nodes: ");
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
			{
				printf("Enter node %d: ", i + 1);
				insertAtTailDLL();
			}
			break;
		case 2:
			forwardTraverseDLL();
			break;
		case 3:
			reverseTraverseDLL();
			break;
		case 4:
			printf("\nEnter the data: ");
			insertAtHeadDLL();
			break;
		case 5:
			printf("\nEnter the data: ");
			insertAtTailDLL();
			break;
		case 6:
			insertAtPosDLL();
			break;
		case 7:
			deleteAtHeadDLL();
			break;
		case 8:
			deleteAtTailDLL();
			break;
		case 9:
			deleteAtPosDLL();
			break;
		default:
			printf("\nInvalid choice\n");
			break;
		}

		printf("\nEnter 1 for creating DLL\n");
		printf("Enter 2 for traversing forward\n");
		printf("Enter 3 for traversing backward\n");
		printf("Enter 4 for inserting at the start\n");
		printf("Enter 5 for inserting at the end\n");
		printf("Enter 6 for inserting at any position\n");
		printf("Enter 7 for deleting at the start\n");
		printf("Enter 8 for deleting at the end\n");
		printf("Enter 9 for deleting at any position\n");
		printf("Enter 0 to exit\n");
		scanf("%d", &choice);
	} while (choice != 0);

	return 0;
}