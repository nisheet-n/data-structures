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

	for (int i = 1; i <= size - 1; i++)
	{
		int j = i;
		while (j > 0 && array[j - 1] > array[j])
		{
			int temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
	}

	printf("\nThe Insertion Sorted array is:\n");
	for (int i = 0; i < size; i++)
		printf("Element %d: %d\n", i + 1, array[i]);

	return 0;
}