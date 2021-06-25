#include <stdio.h>

struct distance
{
    int m, km;
};

struct distance add(struct distance a, struct distance b)
{
    struct distance c;
    c.m = a.m + b.m;
    c.km = a.km + b.km + c.m/1000;
    c.m = c.m % 1000;
    return c;
};

int main()
{
    struct distance d1;
    struct distance d2;
    struct distance d3;

    printf("Enter the length 1 in kilometers\n");
    scanf("%d", &d1.km);
    printf("Enter the length 1 in meters\n");
    scanf("%d", &d1.m);
    printf("Enter the length 2 in kilometers\n");
    scanf("%d", &d2.km);
    printf("Enter the length 2 in meters\n");
    scanf("%d", &d2.m);

    d3 = add(d1, d2);
    printf("\nThe sum of length is %d km and %d m\n", d3.km, d3.m);

    return 0;
}