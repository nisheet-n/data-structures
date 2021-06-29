#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int top;
	unsigned size;
	int *array;
};

struct Stack *createStack(unsigned size)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

	stack->top = -1;
	stack->size = size;
	stack->array = (int *)malloc(stack->size * sizeof(int));
	return stack;
}

int isEmpty(struct Stack *stack)
{
	return stack->top == -1;
}

char pop(struct Stack *stack)
{
	if (!isEmpty(stack))
	{
		return stack->array[stack->top--];
	}
}

void push(struct Stack *stack, char ch)
{
	stack->array[++stack->top] = ch;
}

int evaluatePostfix(char *ch)
{

	struct Stack *stack = createStack(strlen(ch));
	int i;

	if (!stack)
	{
		return -1;
	}

	for (i = 0; ch[i]; ++i)
	{
		if (isdigit(ch[i]))
		{
			push(stack, ch[i] - '0');
		}
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (ch[i])
			{
			case '+':
				push(stack, val2 + val1);
				break;
			case '-':
				push(stack, val2 - val1);
				break;
			case '*':
				push(stack, val2 * val1);
				break;
			case '/':
				push(stack, val2 / val1);
				break;
			}
		}
	}
	return pop(stack);
}

int main()
{
	char s[] = "35*64*+";
	printf("%d", evaluatePostfix(s));

	return 0;
}