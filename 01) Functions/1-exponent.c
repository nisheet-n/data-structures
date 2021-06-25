#include<stdio.h>
#include<math.h>

int POWER(int x,int y)
    {
        return(pow(x,y));
    }

int main()
{
int x,y,power;

printf("Enter the Base and the Power: ");
scanf("%d%d",&x,&y);

power=POWER(x,y);

printf("\nThe Value is : %d", power);
}
