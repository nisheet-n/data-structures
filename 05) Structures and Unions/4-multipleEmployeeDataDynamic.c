#include <stdio.h>
#include <stdlib.h>

struct employee
{
    int id;
    char name[30], designation[20], department[20];
    char gender[1];
    float basicsal, dasal, hrasal, grosssal;
};

int main()
{
    int size;

    printf("Enter number of Employees\n");
    scanf("%d", &size);

    struct employee *ptr;
    ptr = (struct employee *)malloc(size * sizeof(struct employee));

    for(int i=0; i<size; i++)
    {
        printf("\nEnter details of employee %d:\n", i+1);

        printf("Enter ID\n");
        scanf("%d", &(ptr + i)->id);
        printf("Enter Name\n");
        scanf("%s", (ptr + i)->name);
        printf("Enter Gender\n");
        scanf("%s", (ptr + i)->gender);
        printf("Enter Designation\n");
        scanf("%s", (ptr + i)->designation);
        printf("Enter Department\n");
        scanf("%s", (ptr + i)->department);
        printf("Enter Basic Salary\n");
        scanf("%f", &(ptr + i)->basicsal);

        (ptr+i)->dasal = (ptr+i)->basicsal * 75 / 100;
        (ptr+i)->hrasal = (ptr+i)->basicsal * 25 / 100;
        (ptr+i)->grosssal = (ptr+i)->basicsal + (ptr+i)->dasal + (ptr+i)->hrasal;
    }

    for(int i=0; i<size; i++)
    {
        printf("\nDetails of employee %d:\n", i+1);
        printf("Id = %d, Name = %s, Gender = %s\n", (ptr+i)->id, (ptr+i)->name, (ptr+i)->gender);
        printf("The Designation of of %s is %s\n", (ptr+i)->name, (ptr+i)->designation);
        printf("The Department of of %s is %s\n", (ptr+i)->name, (ptr+i)->department);
        printf("The Basic Salary of %s is %.2f\n", (ptr+i)->name, (ptr+i)->basicsal);
        printf("The DA of %s is %.2f\n", (ptr+i)->name, (ptr+i)->dasal);
        printf("The HRA of %s is %.2f\n", (ptr+i)->name, (ptr+i)->hrasal);
        printf("The Gross Salary of %s is %.2f\n", (ptr+i)->name, (ptr+i)->grosssal);
    }
    
    return 0;
}