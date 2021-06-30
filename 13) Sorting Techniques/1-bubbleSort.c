#include <stdio.h>

int main()
{
	int size;
	printf("\nEnter the size of array: ");
	scanf("%d", &size);
	int array[size];
	printf("\nEnter %d elements:\n", size);
	for (int i = 0; i < size; i++)
		scanf("%d", &array[i]);

	printf("\nThe array is:\n");
	for (int i = 0; i < size; i++)
		printf("Element %d: %d\n", i + 1, array[i]);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}

	printf("\nThe Bubble Sorted array is:\n");
	for (int i = 0; i < size; i++)
		printf("Element %d: %d\n", i + 1, array[i]);

	return 0;
}