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
	if (head == NULL)
	{
		printf("\nEmpty List...");
		return;
	}
	p = head;
	while (p != NULL)
	{
		printf(" --> | %d || %u |", p->data, p->next);
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
	printf("Enter the value after which you want to insert: ");
	scanf("%d", &prev->data);
	if (prev == NULL)
	{
		printf("Invalid node entered");
		return;
	}
	printf("Enter the new data: ");
	scanf("%d", &p->data);
	nod = head;
	while (nod->data != prev->data)
	{
		nod = nod->next;
	}
	p->next = nod->next;
	nod->next = p;
}

//Delete a node at beginning//
void deleteAtBeginning()
{
	struct Node *temp = head;
	if (temp == NULL)
	{
		printf("\nEmpty list...");
		return;
	}
	printf("\nValue of the deleted node = % d\n", temp->data);

	head = head->next;
	free(temp);
}

//Delete a node at the end//
void deleteAtEnd()
{
	struct Node *temp = head;
	struct Node *prev;
	if (temp == NULL)
	{
		printf("\nEmpty list...");
		return;
	}
	if (temp->next == NULL)
	{
		printf("\nList contains only node, its value = % d", temp->data);
		head = NULL;
		free(temp);
		return;
	}
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	printf("\nValue of the deleted node = % d\n", temp->data);

	prev->next = temp->next;
	free(temp);
}

// Delete a node at any postion//
void deleteAtAnyPosition()
{
	int pos;
	printf("Enter an element to delete: ");
	scanf("%d", &pos);

	struct Node *temp = head, *prev;

	if (temp == NULL)
	{
		printf("Empty List\n");
		return;
	}
	if (temp != NULL && temp->data == pos)
	{
		printf("\nValue of the deleted node = % d ", temp->data);

		head = temp->next;
		free(temp);
		return;
	}
	while (temp && temp->data != pos)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("\nSearched value does not exist in the list...");
		return;
	}
	printf("\nValue of the deleted node = % d\n", temp->data);

	prev->next = temp->next;
	free(temp);
}

//Count total number of nodes//
void countNodes()
{
	int count = 0;
	if (head == NULL)
		return;
	p = head;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	printf("The total number of nodes is %d\n", count);
}

int main()
{
	int choice;
	printf("\nEnter 1 for creating\n");
	printf("Enter 2 for displaying\n");
	printf("Enter 3 for inserting at the start\n");
	printf("Enter 4 for inserting at the end\n");
	printf("Enter 5 for inserting at any position\n");
	printf("Enter 6 for inserting after a specific element\n");
	printf("Enter 7 for deleting at the start\n");
	printf("Enter 8 for deleting at the end\n");
	printf("Enter 9 for deleting at any position\n");
	printf("Enter 10 for counting the number of nodes\n");
	printf("Enter 0 to exit\n\n");
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
			displayList();
			break;
		case 4:
			insertAtEnd();
			displayList();
			break;
		case 5:
			insertAtPos();
			displayList();
			break;
		case 6:
			insertAfterElem();
			displayList();
			break;
		case 7:
			deleteAtBeginning();
			displayList();
			break;
		case 8:
			deleteAtEnd();
			displayList();
			break;
		case 9:
			deleteAtAnyPosition();
			displayList();
			break;
		case 10:
			countNodes();
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
		printf("Enter 7 for deleting at the start\n");
		printf("Enter 8 for deleting at the end\n");
		printf("Enter 9 for deleting at any position\n");
		printf("Enter 10 for counting the number of nodes\n");
		printf("Enter 0 to exit\n\n");
		scanf("%d", &choice);
	} while (choice != 0);

	return 0;
}