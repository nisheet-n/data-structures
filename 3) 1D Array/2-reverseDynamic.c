//Reverse dynamic array//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter the size of the array\n");
	scanf("%d", &n);

	int *arr;
	arr = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		printf("Enter the element %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("The array in reverse order is\n");

	for (int i = n - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}