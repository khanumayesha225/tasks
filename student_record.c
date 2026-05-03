#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for Employee
struct Employee {
    int id;
    char name[50];
    float basic, hra, da, gross;
};

struct Employee emp[MAX];
int count = 0;

// Add employee
void addEmployee() {
    if (count >= MAX) {
        printf("Limit reached!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &emp[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", emp[count].name);

    printf("Enter Basic Salary: ");
    scanf("%f", &emp[count].basic);

    printf("Enter HRA: ");
    scanf("%f", &emp[count].hra);

    printf("Enter DA: ");
    scanf("%f", &emp[count].da);

    // Calculate Gross Salary
    emp[count].gross = emp[count].basic + emp[count].hra + emp[count].da;

    count++;

    printf("Employee added successfully!\n");
}

// Display all employees
void displayEmployees() {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Employee Records ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nEmployee ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Basic: %.2f\n", emp[i].basic);
        printf("HRA: %.2f\n", emp[i].hra);
        printf("DA: %.2f\n", emp[i].da);
        printf("Gross Salary: %.2f\n", emp[i].gross);
    }
}

// Search employee
void searchEmployee() {
    int id, found = 0;

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            printf("\nEmployee Found!\n");
            printf("Name: %s\n", emp[i].name);
            printf("Gross Salary: %.2f\n", emp[i].gross);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Employee Salary Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}