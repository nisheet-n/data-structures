#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *p, *head = NULL;

//a) Creating a list//
void createList()
{
	int n;
	printf("\nEnter number of nodes: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			head = (struct Node *)malloc(sizeof(struct Node));
			p = head;
		}
		else
		{
			p->next = (struct Node *)malloc(sizeof(struct Node));
			p = p->next;
		}
		printf("Enter node %d: ", i + 1);
		scanf("%d", &p->data);
	}
	p->next = NULL;
}

//b) Displaying the list//
void displayList()
{
	int count = 1;
	if (head == NULL)
	{
		printf("\nEmpty List...");
		return;
	}
	p = head;
	while (p != NULL)
	{
		printf("\nNode %d:  %d", count, p->data);
		count++;
		p = p->next;
	}
	printf("\n");
}

//c) Inserting a node at the start//
void insertAtBegining()
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter the new data: ");
	scanf("%d", &newNode->data);
	newNode->next = head;
	head = newNode;
}

//d) Inserting a node at the end//
void insertAtEnd()
{
	struct Node *last;
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter the new data: ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	last = head;
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newNode;
}

//e) Inserting a node at any given position//
void insertAtPos()
{
	int pos, i, nodes = 0;
	struct Node *newNode, *prev;
	struct Node *curr = head;
	while (curr != NULL)
	{
		nodes++;
		curr = curr->next;
	}
	printf("\nEnter the position: ");
	scanf("%d", &pos);
	if (pos < 1 || pos > nodes)
	{
		printf("Invalid Input...");
		return;
	}
	newNode = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter the new data: ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	if (pos == 1)
	{
		newNode->next = head;
		head = newNode;
	}
	i = 1;
	curr = head;
	while (i < pos)
	{
		i++;
		prev = curr;
		curr = curr->next;
	}
	newNode->next = prev->next;
	prev->next = newNode;
}

//f) Inserting a node after a particular element//
void insertAfterElem()
{
	struct Node *nod;
	struct Node *prev;
	struct Node *p;
	nod = (struct Node *)malloc(sizeof(struct Node));
	prev = (struct Node *)malloc(sizeof(struct Node));
	p = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter the value after which u wanna enter");
	scanf("%d", &prev->data);
	if (prev == NULL)
	{
		printf("Invalid node entered");
		return;
	}
	printf("Enter the new value");
	scanf("%d", &p->data);
	nod = head;
	while (nod->data != prev->data)
	{
		nod = nod->next;
	}
	p->next = nod->next;
	nod->next = p;
}

int main()
{
	int choice;
	printf("Enter 1 for creating\n");
	printf("Enter 2 for displaying\n");
	printf("Enter 3 for inserting at the start\n");
	printf("Enter 4 for inserting at the end\n");
	printf("Enter 5 for inserting at any position\n");
	printf("Enter 6 for inserting after a specific element\n");
	printf("Enter 0 to exit\n");
	scanf("%d", &choice);

	do
	{
		switch (choice)
		{
		case 1:
			createList();
			break;
		case 2:
			displayList();
			break;
		case 3:
			insertAtBegining();
			break;
		case 4:
			insertAtEnd();
			break;
		case 5:
			insertAtPos();
			break;
		case 6:
			insertAfterElem();
			break;
		default:
			printf("Invalid choice\n");
			break;
		}

		printf("\nEnter 1 for creating\n");
		printf("Enter 2 for displaying\n");
		printf("Enter 3 for inserting at the start\n");
		printf("Enter 4 for inserting at the end\n");
		printf("Enter 5 for inserting at any position\n");
		printf("Enter 6 for inserting after a specific element\n");
		printf("Enter 0 to exit\n");
		scanf("%d", &choice);
	} while (choice != 0);

	return 0;
}