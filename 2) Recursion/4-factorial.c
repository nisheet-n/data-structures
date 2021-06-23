#include<stdio.h>

int fact(int num)
    {
        if(num==0)
            {
                return 0;
            }
        else if (num==1)
        {
            return 1;
        }
        else
        {
            return num*fact(num-1);
        }
        
    }

int main()
{
    int num,fac;

    printf("Enter a number: ");
    scanf("%d",&num);

    fac=fact(num);
    printf("\nFactorial:  %d",fac);
}