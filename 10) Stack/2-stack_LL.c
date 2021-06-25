#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top = NULL;

void push()
{
	int num;
	printf("\nEnter number of elements to push: ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		struct node *newNode = (struct node *)malloc(sizeof(struct node));
		printf("Enter Node %d: ", i + 1);
		scanf("%d", &newNode->data);
		newNode->next = top;
		top = newNode;
	}
}

void pop()
{
	struct node *temp;
	temp = top;
	printf("\nDeleted value is: %d\n", temp->data);
	top = top->next;
	free(temp);
}

void forwardTraverse()
{
	struct node *temp = top;
	printf("\nForward Stack:\n");
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

int main()
{
	int choice;
	do
	{
		printf("\nEnter 1 for push operation on Stack\n");
		printf("Enter 2 for traversing forward\n");
		printf("Enter 3 for pop operation on stack\n");
		printf("Enter 0 to exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			forwardTraverse();
			break;
		case 3:
			pop();
			break;
		default:
			printf("\nInvalid choice\n");
			break;
		}

	} while (choice != 0);

	return 0;
}