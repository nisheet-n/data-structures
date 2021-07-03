#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left, *right;
	int data;
	int lt;
	int rt;
};

struct node *insert(struct node *r, int val)
{
	if (r == NULL)
	{
		struct node *cur = (struct node *)malloc(sizeof(struct node));
		cur->data = val;
		cur->left = cur->right = NULL;
		cur->lt = cur->rt = 0;
		return cur;
	}
	else if (r->data < val)
	{
		r->right = insert(r->right, val);
		return r;
	}
	else if (r->data > val)
	{
		r->left = insert(r->left, val);
		return r;
	}
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int search(struct node *root, int val)
{
	if (root == NULL)
		return 0;
	else if (val == root->data)
		return 1;
	else if (val < root->data)
		search(root->left, val);
	else if (val > root->data)
		search(root->right, val);
}

struct node *min(struct node *r)
{
	if (r == NULL)
		return NULL;
	while (r->left != NULL)
		r = r->left;
	return r;
}

struct node *max(struct node *r)
{
	if (r == NULL)
		return NULL;
	while (r->right != NULL)
		r = r->right;
	return r;
}

int main()
{
	struct node *root = NULL;
	int choice;
	do
	{
		printf("\nEnter 0 to Quit\n");
		printf("Enter 1 to Create/Insert\n");
		printf("Enter 2 for Inorder Traversal\n");
		printf("Enter 3 for Preorder Traversal\n");
		printf("Enter 4 for Postorder Traversal\n");
		printf("Enter 5 to search for an element\n");
		printf("Enter 6 to find Maximum\n");
		printf("Enter 7 to Find Minimum\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter the number of elements to be inserted: ");
			int size;
			scanf("%d", &size);
			for (int i = 0; i < size; i++)
			{
				int data;
				printf("Enter number %d: ", i + 1);
				scanf("%d", &data);
				root = insert(root, data);
			}
			break;

		case 2:
			printf("\nPreorder is: ");
			preorder(root);
			break;

		case 3:
			printf("\nInorder is: ");
			inorder(root);
			break;

		case 4:
			printf("\nPostorder is: ");
			postorder(root);
			break;

		case 5:
			printf("\nEnter a number to be searched: ");
			int num;
			scanf("%d", &num);
			printf("%s", (search(root, num) == 1) ? "PRESENT" : "NOT PRESENT");
			break;

		case 6:
			printf("\nLargest Number present in tree is: %d", max(root)->data);
			break;

		case 7:
			printf("\nSmallest Number present in tree is: %d", min(root)->data);
			break;

		default:
			printf("\nEnter a valid choice!");
			break;
		}
	} while (choice != 0);
	return 0;
}