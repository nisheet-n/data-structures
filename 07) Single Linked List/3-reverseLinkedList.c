#include <stdio.h>
#include <stdlib.h>

struct Node
{
	char data[1];
	struct Node *next;
};

struct Node *p, *head = NULL;
void displayList(); //Globally defined to avoid the warning//

void createList()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);

	head = (struct Node *)malloc(sizeof(struct Node));

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			p = head;
		else
		{
			p->next = (struct Node *)malloc(sizeof(struct Node));
			p = p->next;
		}
		printf("Enter data for Node %d: ", i + 1);
		scanf("%s", &p->data);
	}
	p->next = NULL;
}

void reverseList()
{
	struct Node *prev, *curr;
	prev, curr = (struct Node *)malloc(sizeof(struct Node));
	prev = NULL;
	curr = head;
	p = head;
	while (p != NULL)
	{
		p = p->next;
		curr->next = prev;
		prev = curr;
		curr = p;
	}
	head = prev;
	displayList();
}

void displayList()
{
	int count = 1;
	p = head;
	while (p != NULL)
	{
		printf("\nNode %d:  %s", count, p->data);
		count++;
		p = p->next;
	}
	printf("\n");
}

int main()
{
	createList();
	displayList();
	reverseList();
	return 0;
}