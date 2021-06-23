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
    int size, num;
    printf("Enter the size of array\n");
    scanf("%d", &size);

    int *arr;
    arr = (int*)malloc(size*sizeof(int));
    
    int evenarr[size], oddarr[size];
    for(int i=0; i<size; i++)
    {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    bubblesort (arr, size);

    int evencount = 0, oddcount = 0;
    for(int i=0; i<size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenarr[evencount] = arr[i];
            evencount = evencount + 1;
        }
        else
        {
            oddarr[oddcount] = arr[i];
            oddcount = oddcount + 1;
        }
    }
    
    printf("The required odd even array is:\n");
    for (int i=0; i<oddcount; i++)
        printf("%d ", oddarr[i]);
    for (int i=0; i<evencount; i++)
        printf("%d ", evenarr[i]);

    return 0;
}