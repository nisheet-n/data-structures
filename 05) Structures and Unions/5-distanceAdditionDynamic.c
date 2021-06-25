#include <stdio.h>
#include <stdlib.h>

struct distance
{
    int m, km;
};

struct distance add(struct distance *a, struct distance *b)
{
    struct distance *c;
    c = (struct distance *)malloc(1 * sizeof(struct distance));

    c->m = a->m + b->m;
    c->km = a->km + b->km + c->m/1000;
    c->m = c->m % 1000;
    return *c;
};

int main()
{
    struct distance *dinput;
    struct distance *dresult;
    dinput = (struct distance *)malloc(2 * sizeof(struct distance));
    dresult = (struct distance *)malloc(1 * sizeof(struct distance));

    for(int i=0; i<2; i++)
    {
        printf("\nEnter distance %d in kilometres and metres respectively:\n", i+1);
        printf("Enter the kilometres: ");
        scanf("%d", &(dinput+i)->km);
        printf("Enter the meters: ");
        scanf("%d", &(dinput+i)->m);
    }

    *dresult = add((dinput+0), (dinput+1));
    printf("\nThe sum of length is %d km and %d m\n", dresult->km, dresult->m);

    return 0;
}