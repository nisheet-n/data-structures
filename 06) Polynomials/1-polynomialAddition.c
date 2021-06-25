#include <stdio.h>
#include <stdlib.h>

struct polynomial
{
    int power, coeff;
};

int choice, maxpow1, maxpow2, maxpow;
struct polynomial *p1, *p2, *p3;

void query()
{
    printf("\nEnter 1 for insertion, 2 for display, 3 for addition:\n");
    scanf("%d", &choice);
}

void insert()
{
    printf("Enter the maximum power in first polynomial: ");
    scanf("%d", &maxpow1);

    printf("Enter the maximum power in second polynomial: ");
    scanf("%d", &maxpow2);

    p1 = (struct polynomial *)calloc(sizeof(struct polynomial), maxpow1 + 1);
    p2 = (struct polynomial *)calloc(sizeof(struct polynomial), maxpow2 + 1);

    printf("\nEnter inputs for first polynomial:\n");
    for (int i = maxpow1; i >= 0; i--)
    {
        printf("Coefficient of x^%d: ", i);
        (p1 + i)->power = i;
        scanf("%d", &((p1 + i)->coeff));
    }

    printf("\nEnter inputs for second polynomial:\n");
    for (int i = maxpow2; i >= 0; i--)
    {
        printf("Coefficient of x^%d: ", i);
        (p2 + i)->power = i;
        scanf("%d", &((p2 + i)->coeff));
    }
}

void display()
{
    for (int i = maxpow1; i > 0; i--)
        printf("%dx^%d + ", (p1 + i)->coeff, (p1 + i)->power);
    printf("%dx^%d\n", (p1 + 0)->coeff, (p1 + 0)->power);

    for (int i = maxpow2; i > 0; i--)
        printf("%dx^%d + ", (p2 + i)->coeff, (p2 + i)->power);
    printf("%dx^%d\n", (p2 + 0)->coeff, (p2 + 0)->power);
}

void addpoly()
{
    if (maxpow1 > maxpow2)
        maxpow = maxpow1;
    else
        maxpow = maxpow2;

    p3 = (struct polynomial *)calloc(sizeof(struct polynomial), maxpow + 1);

    for (int i = maxpow; i >= 0; i--)
    {
        if (i <= maxpow1 && i <= maxpow2)
        {
            (p3 + i)->power = (p1 + i)->power;
            (p3 + i)->coeff = (p1 + i)->coeff + (p2 + i)->coeff;
        }
        else if (i <= maxpow1)
        {
            (p3 + i)->power = (p1 + i)->power;
            (p3 + i)->coeff = (p1 + i)->coeff;
        }
        else
        {
            (p3 + i)->power = (p2 + i)->power;
            (p3 + i)->coeff = (p2 + i)->coeff;
        }
    }
    free(p1), free(p2);

    printf("\nSum of the given two polynomials is:\n");

    for (int i = maxpow; i > 0; i--)
        printf("%dx^%d + ", (p3 + i)->coeff, (p3 + i)->power);
    printf("%dx^%d", (p3 + 0)->coeff, (p3 + 0)->power);
    free(p3);
}

int main()
{
    query();
    if (choice == 1)
    {
        insert();
        query();
    }
    else if (choice == 2)
    {
        insert();
        display();
    }
    else if (choice == 3)
    {
        insert();
        printf("\n");
        display();
        addpoly();
    }
    else
        printf("Wrong Input\n");

    return 0;
}