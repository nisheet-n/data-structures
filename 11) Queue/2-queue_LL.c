#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front = NULL;

void enqueue()
{
	int num;
	printf("\nEnter number of elements to push: ");
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		printf("Enter Node %d: ", i + 1);
		scanf("%d", &newNode->data);
		newNode->next = front;
		front = newNode;
	}
}

void display()
{
	if (front == NULL)
	{
		printf("\nEmpty Queue\n");
		return;
	}
	struct node *temp = front;
	printf("\nForward Queue:\n");
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void dequeue()
{
	if (front == NULL)
	{
		printf("\nEmpty Queue\n");
		return;
	}
	else
	{
		struct node *temp = front;
		if (temp->next == NULL)
		{
			printf("\nDeleted value: %d\n", temp->data);
			free(temp);
			front = NULL;
		}
		else
		{
			while (temp->next->next != NULL)
				temp = temp->next;

			printf("\nDeleted value: %d\n", temp->next->data);
			free(temp->next);
			temp->next = NULL;
		}
	}
}

int main()
{
	int choice;
	do
	{
		printf("\nEnter 1 for Enqueue Operation\n");
		printf("Enter 2 to display\n");
		printf("Enter 3 for Dequeue Operation\n");
		printf("Enter 0 to exit\n");
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
			printf("\nInvalid choice\n");
			break;
		}
	} while (choice != 0);

	return 0;
}