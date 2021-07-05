/*Write C program to implement a menu driven non-recursive traversals (preorder, inorder, postorder).
 Fisrt you must create a balanced tree using a sequence of data as an input, 
 then go for three tree traversals.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct stack
{
	struct node *data[MAX];
	int top;
};

struct node *createTree()
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter data (Enter -1 for no node): ");
	scanf("%d", &newnode->data);
	if (newnode->data == -1)
		return 0;

	printf("\nEnter left child of %d: ", newnode->data);
	newnode->left = createTree();
	printf("Enter right child of %d: ", newnode->data);
	newnode->right = createTree();
	return newnode;
}

int push(struct stack *S, struct node *num)
{
	if (S->top == MAX - 1)
	{
		printf("\nStack Overflow\n");
		return 1;
	}
	S->top++;
	S->data[S->top] = num;
	return 0;
}

int pop(struct stack *S, struct node **num)
{
	if (S->top == -1)
	{
		printf("Stack Underflow\n");
		return 1;
	}
	*num = S->data[S->top];
	S->top--;
	return 0;
}

int isEmpty(struct stack S)
{
	if (S.top == -1)
		return 1;
	else
		return 0;
}

void preorder(struct node *n)
{
	struct node *num;
	struct stack S1;
	S1.top = -1;
	if (n == NULL)
		return;
	push(&S1, n);
	while (!isEmpty(S1))
	{
		pop(&S1, &num);
		printf("%d ", num->data);
		if (num->right != NULL)
			push(&S1, num->right);
		if (num->left != NULL)
			push(&S1, num->left);
	}
	printf("\n");
}

void inorder(struct node *n)
{
	struct node *num;
	struct stack S1;
	S1.top = -1;
	struct node *curr = n;
	while (curr != NULL)
	{
		push(&S1, curr);
		curr = curr->left;
	}
	while (S1.top != -1)
	{
		pop(&S1, &num);
		printf("%d ", num->data);
		curr = num->right;
		while (curr != NULL)
		{
			push(&S1, curr);
			curr = curr->left;
		}
	}
}

void postorder(struct node *n)
{
	struct node *num1;
	struct stack S1;
	struct node *num2;
	struct node *curr = n;
	S1.top = -1;
	while (curr != NULL)
	{
		if (curr->right != NULL)
			push(&S1, curr->right);
		push(&S1, curr);
		curr = curr->left;
	}
	while (!isEmpty(S1))
	{
		pop(&S1, &num1);
		if (num1->right == NULL)
			printf("%d ", num1->data);
		else if (isEmpty(S1))
		{
			printf("%d ", num1->data);
		}
		else
		{
			pop(&S1, &num2);
			if (num1->right != num2)
			{
				printf("%d ", num1->data);
				push(&S1, num2);
			}
			else
			{
				push(&S1, num1);
				curr = num2;
				while (curr != NULL)
				{
					if (curr->right != NULL)
						push(&S1, curr->right);
					push(&S1, curr);
					curr = curr->left;
				}
			}
		}
	}
}

int main()
{
	struct node *root = NULL;
	int choice;
	do
	{
		printf("\nEnter 1 to create");
		printf("\nEnter 2 for preorder traversal");
		printf("\nEnter 3 for Inorder traversal");
		printf("\nEnter 4 for postorder traversal");
		printf("\nEnter 5 to Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			root = createTree();
			break;
		case 2:
			printf("Preorder: ");
			preorder(root);
			break;
		case 3:
			printf("\nInorder: ");
			inorder(root);
			break;
		case 4:
			printf("\nPostorder: ");
			postorder(root);
			break;
		default:
			printf("\nEnter a valid choice!");
		}
	} while (choice != 0);
	return 0;
}