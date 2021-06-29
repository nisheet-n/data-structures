#include <stdio.h>

char stack[100];
int top = -1;

void push(char x)
{
	stack[++top] = x;
}

char pop()
{
	if (top == -1)
		return -1;
	else
		return stack[top--];
}

int check(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	return 0;
}

int main()
{
	char s[100];
	char *num, x;
	printf("Enter the expression: ");
	scanf("%s", s);
	printf("\n");
	num = s;
	while (*num != '\0')
	{
		if (isalnum(*num))
			printf("%c ", *num);
		else if (*num == '(')
			push(*num);
		else if (*num == ')')
		{
			while ((x = pop()) != '(')
				printf("%c ", x);
		}
		else
		{
			while (check(stack[top]) >= check(*num))
				printf("%c ", pop());
			push(*num);
		}
		num++;
	}

	while (top != -1)
	{
		printf("%c ", pop());
	}
	return 0;
}