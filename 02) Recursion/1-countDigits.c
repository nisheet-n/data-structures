#include<stdio.h>

int count(int num)
    {

        if(num%10==0)
            return 0;
           
        return (num%10!=0)+count(num/10) ;        
    }

int main()
{
    unsigned int num;
    int ctr=0;

    printf("Enter a number:  ");
    scanf("%d",&num);

    ctr=count(num);

    printf("\nNumber of digits are: %d",ctr);
}