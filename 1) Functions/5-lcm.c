#include<stdio.h>

int gcd(int a, int b)  
{  
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
}  

int lcm(int a, int b)  
{  
    return (a*b)/gcd(a, b);  
}  

int main()  
{  
    int a,b;
    printf("Enter the 2 numbers: ");
    scanf("%d%d",&a,&b);

    printf("\nLCM of %d and %d is %d ", a, b, lcm(a, b));  
    return 0;  
}  