#include <stdio.h>
#include <stdlib.h>

void bubblesort(int array[],int size)
{
    for(int i=0; i<size;i++)
    {
        for(int j=0; j<size-1;j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()
{
    int size;
    printf("Enter the size of array:\n");
    scanf("%d", &size);

    int *arr;
    arr = (int *)malloc(size*sizeof(int));

    for (int i=0; i<size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, size);
    printf("The sorted array is:\n");
    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}