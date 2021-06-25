#include <stdio.h>

int main()
{
    int smat[4][5] =
    {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    
    int i, j, k, size = 0;

    for(i = 0; i < 4; i++)
    {
        for(j=0; j<5; j++)
        {
            if(smat[i][j]!=0)
            {
                size++;
            }
        }
    }

    int sm[size][3];
    k=0;
    sm[k][0] = 4;
    sm[k][1] = 5;
    sm[k][2] = size;
    k++;

    for(i = 0; i < 4; i++)
    {
        for(j=0; j<5; j++)
        {
            if(smat[i][j]!=0)
            {
                sm[k][0] = i;
                sm[k][1] = j;
                sm[k][2] = smat[i][j];
                k++;
            }
        }
    }

    for(i = 0; i < size+1; i++)
    {
        for(j=0; j < 3; j++)
        {
            printf("%d", sm[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}