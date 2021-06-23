#include<stdio.h>
#include<math.h>

int value(int num,int size)
    {
        return num/(pow(10,size-1));
    }

int main()
{
    int num,size=0,first;

    printf("Enter a number:  ");
    scanf("%d",&num);

    int temp=num;

    while (temp%10!=0)
    {
        size++;
        temp=temp/10;
    }

    first=value(num,size);
    printf("\nThe first digit of the number is:  %d",first);
    
}