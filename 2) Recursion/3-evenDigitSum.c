#include<stdio.h>
#include<stdlib.h>

int add(int num)
    {
        if(num%10==0)
        {
            return 0;
        }
        else{
            return (num%10)*(num%2==0)+add(num/10);
        }
    }

int main()
{
    int size,sum=0;

    int num;
    printf("Enter the number:  ");
    scanf("%d",&num);

    int temp=num;

    for (size = 0; temp%10!=0 ; size++)
    {
        temp=temp/10;
    }

    sum=add(num);
    printf("\nSum Of the Even Digits:  %d",sum);

return 0;    
}