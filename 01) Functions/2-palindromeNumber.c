#include<stdio.h>
#include<string.h>

int pallindrome(char *a,int size)
    {
        int temp=-1;

        for (int i = 0; i < size/2 ; i++)
        {
            if(a[i]!=a[size-1-i])
                {
                    temp++;
                    break;
                }
        }
        
    return(temp);
        
    }

int main()
{
    char ch[100];
    int check=-1,size=0;

    printf("Enter a line: ");
    scanf("%s", ch);
    size=strlen(ch);

    check=pallindrome(ch,size);

    if (check==-1)
    {
        printf("\nIt is a Pallindrome!!!");
    }
    else
    {
        printf("\nIt is not a Pallindrome!!!");
    }
        
return 0;
}