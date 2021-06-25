#include <stdio.h>

int top = -1;

void push(int stack[], int size)
{
	int n;
	printf("\nEnter number of elements to push: ");
	scanf("%d", &n);

	if (n + top >= size)
		printf("\nStack Over Flow\n");
	else
	{
		int data;
		for (int i = 0; i < n; i++)
		{
			printf("Enter element %d: ", i + 1);
			scanf("%d", &data);
			top++;
			stack[top] = data;
		}
	}
}

void pop(int stack[])
{
	if (top <= -1)
		printf("\nStack Under Flow\n");
	else
	{
		printf("\nThe popped element is: %d\n", stack[top]);
		top--;
	}
}

void display(int stack[])
{
	if (top >= 0)
	{
		printf("\nThe elements in Stack are:\n");
		for (int i = top; i >= 0; i--)
			printf("%d\n", stack[i]);
	}
	else
		printf("\nEmpty Stack\n");
}

int main()
{
	int size;
	printf("\nEnter the size of Stack: ");
	scanf("%d", &size);
	int stack[size];

	int choice;
	do
	{
		printf("\nEnter 1 for push operation");
		printf("\nEnter 2 for pop operation");
		printf("\nEnter 3 to display stack");
		printf("\nEnter 0 to exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push(stack, size);
			break;
		case 2:
			pop(stack);
			break;
		case 3:
			display(stack);
			break;
		default:
			printf("\nEnter a Valid Choice(1/2/3/0)\n");
			break;
		}
	} while (choice != 0);

	return 0;
}