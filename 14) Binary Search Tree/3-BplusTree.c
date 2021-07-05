#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int *data;
	struct TreeNode **child_ptr;
	int leaf;
	int n;
} *root = NULL, *np = NULL, *x = NULL;

struct TreeNode *init()
{
	int i;
	np = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	np->data = (int *)malloc(5 * sizeof(int));
	np->child_ptr = (struct TreeNode **)malloc(6 * sizeof(struct TreeNode));
	np->leaf = 1;
	np->n = 0;
	for (i = 0; i < 6; i++)
	{
		np->child_ptr[i] = NULL;
	}
	return np;
}

void traverse(struct TreeNode *p)
{
	printf("\n");
	if (root == NULL)
	{
		printf("Tree is empty.\n");
		return;
	}
	int i;
	for (i = 0; i < p->n; i++)
	{
		if (p->leaf == 0)
		{
			traverse(p->child_ptr[i]);
		}
		printf(" %d ", p->data[i]);
	}
	if (p->leaf == 0)
	{
		traverse(p->child_ptr[i]);
	}
	printf("\n");
}

void sort(int *p, int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = i; j <= n; j++)
		{
			if (p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

int split_child(struct TreeNode *x, int i)
{
	int j, mid;
	struct TreeNode *np1, *np3, *y;
	np3 = init();
	np3->leaf = 1;
	if (i == -1)
	{
		mid = x->data[2];
		x->data[2] = 0;
		x->n--;
		np1 = init();
		np1->leaf = 0;
		x->leaf = 1;
		for (j = 3; j < 5; j++)
		{
			np3->data[j - 3] = x->data[j];
			np3->child_ptr[j - 3] = x->child_ptr[j];
			np3->n++;
			x->data[j] = 0;
			x->n--;
		}
		for (j = 0; j < 6; j++)
		{
			x->child_ptr[j] = NULL;
		}
		np1->data[0] = mid;
		np1->child_ptr[np1->n] = x;
		np1->child_ptr[np1->n + 1] = np3;
		np1->n++;
		root = np1;
	}
	else
	{
		y = x->child_ptr[i];
		mid = y->data[2];
		y->data[2] = 0;
		y->n--;
		for (j = 3; j < 5; j++)
		{
			np3->data[j - 3] = y->data[j];
			np3->n++;
			y->data[j] = 0;
			y->n--;
		}
		x->child_ptr[i + 1] = y;
		x->child_ptr[i + 1] = np3;
	}
	return mid;
}

void insert(int a)
{
	int i, temp;
	x = root;
	if (x == NULL)
	{
		root = init();
		x = root;
	}
	else
	{
		if (x->leaf == 0 && x->n == 5)
		{
			temp = split_child(x, -1);
			x = root;
			for (i = 0; i < (x->n); i++)
			{
				if ((a > x->data[i]) && (a < x->data[i + 1]))
				{
					i++;
					break;
				}
				else if (a < x->data[0])
				{
					break;
				}
				else
				{
					continue;
				}
			}
			x = x->child_ptr[i];
		}
		else
		{
			while (x->leaf == 0)
			{
				for (i = 0; i < (x->n); i++)
				{
					if ((a > x->data[i]) && (a < x->data[i + 1]))
					{
						i++;
						break;
					}
					else if (a < x->data[0])
					{
						break;
					}
					else
					{
						continue;
					}
				}
				if ((x->child_ptr[i])->n == 5)
				{
					temp = split_child(x, i);
					x->data[x->n] = temp;
					x->n++;
					continue;
				}
				else
				{
					x = x->child_ptr[i];
				}
			}
		}
	}
	x->data[x->n] = a;
	sort(x->data, x->n);
	x->n++;
}

void delete ()
{
	root = NULL;
	free(root);
}

int main()
{
	int i, n, t, ch;

	while (1)
	{
		printf("\n1-Insertion in B+ Tree\n2-Traversal of B+ Tree\n3-Deletion\n4-Exit\n\n");
		printf("Enter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter a element to be inserted:");
			scanf("%d", &n);
			insert(n);
			break;
		case 2:
			printf("\nTraversal of constructed tree:");
			traverse(root);
			break;
		case 3:
			delete ();
			printf("\nB+ Tree is deleted successfully.\n");
			break;
		case 4:
			exit(0);
		default:
			printf("!!!...Wrong choice...!!!\n\n");
		}
	}
	return 0;
}