#include <stdio.h>

int size;
int top1, top2, top3;
int counter = 0;

void push(int array[], int data)
{
	array[counter] = data;
	counter++;
}

int pop(int stack_num)
{
	if (stack_num == 1)
		top1--;
	else if (stack_num == 2)
		top2--;
	else if (stack_num == 3)
		top3--;
	else
		printf("\nEnter a valid number from 1 to 3.");
}

void display(int array[], int size)
{
	printf("\nTop 1: %d, Top 2: %d, Top 3: %d\n", top1, top2, top3);

	printf("\nArray Of 3 Stacks:\n");
	for (int i = 0; i <= top1; i++)
		printf("%d\n", array[i]);
	for (int i = size; i <= top2; i++)
		printf("%d\n", array[i]);
	for (int i = size * 2; i <= top3; i++)
		printf("%d\n", array[i]);
}

int main()
{
	printf("\nEnter the size of each stack: ");
	scanf("%d", &size);
	int array[size * 3];

	top1 = -1;
	top2 = top1 + size;
	top3 = top2 + size;

	int choice;
	do
	{
		printf("\nEnter 1 to push\n");
		printf("Enter 2 to Display\n");
		printf("Enter 3 to Pop\n");
		printf("Enter 0 to exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter stack 1:\n");
			for (int i = 0; i < size; i++)
			{
				int data;
				printf("Enter element %d: ", i + 1);
				scanf("%d", &data);
				push(array, data);
				top1++;
			}

			printf("\nEnter stack 2:\n");
			for (int i = 0; i < size; i++)
			{
				int data;
				printf("Enter element %d: ", i + 1);
				scanf("%d", &data);
				push(array, data);
				top2++;
			}

			printf("\nEnter stack 3:\n");
			for (int i = 0; i < size; i++)
			{
				int data;
				printf("Enter element %d: ", i + 1);
				scanf("%d", &data);
				push(array, data);
				top3++;
			}
			break;

		case 2:
			display(array, size);
			break;

		case 3:
			printf("\nEnter stack number to pop from: ");
			int stack_num;
			scanf("%d", &stack_num);
			pop(stack_num);
			break;
		default:
			printf("\nExit\n");
			break;
		}
	} while (choice != 0);

	return 0;
}