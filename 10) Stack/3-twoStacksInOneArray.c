#include <stdio.h>

int size;
int top1;
int top2;

void push1(int array[], int top1, int top2)
{
	printf("Top1: %d, Top2: %d\n", top1, top2);
	if (top1 == (top2 - 1))
	{
		printf("\nStack 1 Overflow\n");
		return;
	}
	else
	{
		top1++;
		printf("\nEnter the element: ");
		scanf("%d", &array[top1]);
	}
}

void push2(int array[], int top1, int top2)
{
	printf("Top1: %d, Top2: %d\n", top1, top2);
	if (top2 == (top1 + 1))
	{
		printf("Overflow\n");
		return;
	}
	else
	{
		top2--;
		printf("\nEnter the element: ");
		scanf("%d", &array[top2]);
	}
}

void pop1(int array[], int top1, int size)
{
	if (top1 == -1)
	{
		printf("\nStack1 is empty\n");
		return;
	}
	else
	{
		printf("Deleted Element: %d\n", array[top1--]);
		return;
	}
}

void pop2(int array[], int top2, int size)
{
	if (top2 == size)
	{
		printf("\nStack2 is empty\n");
		return;
	}
	else
	{
		printf("Deleted Element: %d\n", array[top2++]);
		return;
	}
}

void display1(int array[], int top1, int size)
{
	printf("Top1: %d, Top2: %d\n", top1, top2);
	if (top1 == -1)
	{
		printf("\nStack 1 is empty\n");
		return;
	}
	else
	{
		printf("\nStack 1:\n");
		for (int i = 0; i <= top1; i++)
			printf("%d ", array[i]);
		printf("\n");
	}
}

void display2(int array[], int top2, int size)
{
	printf("Top1: %d, Top2: %d\n", top1, top2);
	if (top2 == size)
	{
		printf("\nStack 2 is empty\n");
		return;
	}
	else
	{
		printf("\nStack 2:\n");
		for (int i = (size - 1); i >= top2; i--)
			printf("%d ", array[i]);
		printf("\n");
	}
}

void main()
{
	printf("\nEnter size of array: ");
	scanf("%d", &size);
	int array[size];

	top1 = -1;
	top2 = size;

	int choice;
	do
	{
		printf("\nEnter 1 to Push element in stack 1\n");
		printf("Enter 2 to Push element in stack 2\n");
		printf("Enter 3 to Pop element from stack 1\n");
		printf("Enter 4 to Pop element from stack 2\n");
		printf("Enter 5 to Traverse stack 1\n");
		printf("Enter 6 to Traverse stack 2\n");
		printf("Enter 0 to EXIT\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push1(array, top1, top2);
			break;

		case 2:
			push2(array, top1, top2);
			break;

		case 3:
			pop1(array, top1, size);
			break;

		case 4:
			pop2(array, top2, size);
			break;

		case 5:
			display1(array, top1, size);
			break;

		case 6:
			display2(array, top2, size);
			break;

		default:
			printf("\nEnter Valid Choice!\n");
			break;
		}
	} while (choice != 0);
}