#include <stdio.h>

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

    struct employee emp[size];

    for(int i=0; i<size; i++)
    {
        printf("\nEnter details of employee %d\n", i+1);

        printf("Enter ID\n");
        scanf("%d", &emp[i].id);
        printf("Enter Name\n");
        scanf("%s", emp[i].name);
        printf("Enter Gender\n");
        scanf("%s", emp[i].gender);
        printf("Enter Designation\n");
        scanf("%s", emp[i].designation);
        printf("Enter Department\n");
        scanf("%s", emp[i].department);
                
        printf("Enter Basic Salary\n");
        scanf("%f", &emp[i].basicsal);

        emp[i].dasal = emp[i].basicsal * 75 / 100;
        emp[i].hrasal = emp[i].basicsal * 25 / 100;
        emp[i].grosssal = emp[i].basicsal + emp[i].dasal + emp[i].hrasal;
    }

    for(int i=0; i<size; i++)
    {
        printf("\nDetails of employee %d:\n", i+1);
        printf("Id = %d, Name = %s, Gender = %s\n", emp[i].id, emp[i].name, emp[i].gender);
        printf("The Designation of of %s is %s\n", emp[i].name, emp[i].designation);
        printf("The Department of of %s is %s\n", emp[i].name, emp[i].department);
        printf("The Basic Salary of %s is %.2f\n", emp[i].name, emp[i].basicsal);
        printf("The DA of %s is %.2f\n", emp[i].name, emp[i].dasal);
        printf("The HRA of %s is %.2f\n", emp[i].name, emp[i].hrasal);
        printf("The Gross Salary of %s is %.2f\n", emp[i].name, emp[i].grosssal);
    }
    
    return 0;
}