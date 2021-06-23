#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, num;
    printf("Enter the size of array\n");
    scanf("%d", &size);

    int *arr;
    arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter a number to search for: ");
    scanf("%d", &num);

    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
            flag = flag + 1;
    }
    if (flag == 0)
        printf("The element %d does not exist in the array\n", num);
    else
        printf("The element %d exists in the array %d times\n", num, flag);

    return 0;
}