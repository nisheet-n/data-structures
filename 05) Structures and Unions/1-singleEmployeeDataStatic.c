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
    struct employee emp1;

    printf("Enter ID\n");
    scanf("%d", &emp1.id);
    printf("Enter Name\n");
    scanf("%s", emp1.name);
    printf("Enter Gender\n");
    scanf("%s", emp1.gender);
    printf("Enter Designation\n");
    scanf("%s", emp1.designation);
    printf("Enter Department\n");
    scanf("%s", emp1.department);

    printf("Enter Basic Salary\n");
    scanf("%f", &emp1.basicsal);

    emp1.dasal = emp1.basicsal * 75 / 100;
    emp1.hrasal = emp1.basicsal * 25 / 100;
    emp1.grosssal = emp1.basicsal + emp1.dasal + emp1.hrasal;

    printf("\nId = %d, Name = %s, Gender = %s\n", emp1.id, emp1.name, emp1.gender);
    printf("The Designation of of %s is %s\n", emp1.name, emp1.designation);
    printf("The Department of of %s is %s\n", emp1.name, emp1.department);
    printf("The Basic Salary of %s is %.2f\n", emp1.name, emp1.basicsal);
    printf("The DA of %s is %.2f\n", emp1.name, emp1.dasal);
    printf("The HRA of %s is %.2f\n", emp1.name, emp1.hrasal);
    printf("The Gross Salary of %s is %.2f\n", emp1.name, emp1.grosssal);
    
    return 0;
}