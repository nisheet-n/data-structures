//Smallest and largest element in array//

#include <stdio.h>

int main()
{
	int n, max, min;
	printf("Enter the number of elements in the array\n");
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		printf("Enter element %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	min = max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	printf("The smallest element is: %d\n", min);
	printf("The largest element is: %d\n", max);

	return 0;
}