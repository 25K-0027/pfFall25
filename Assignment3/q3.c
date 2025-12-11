#include <stdio.h>
#include <string.h>

#define MAX_NAME 100

// Employee structure
typedef struct {
    int id;
    char name[MAX_NAME];
    char designation[50];
    double salary;
} Employee;

// Function to input employee data
void inputEmployees(Employee emp[], int n) {
    for(int i=0; i<n; i++){
        printf("Enter details for Employee %d\n", i+1);
        printf("ID: "); scanf("%d", &emp[i].id);
        printf("Name: "); scanf(" %[^\n]", emp[i].name); // read full line with spaces
        printf("Designation: "); scanf(" %[^\n]", emp[i].designation);
        printf("Salary: "); scanf("%lf", &emp[i].salary);
        printf("\n");
    }
}

// Function to display all employees
void displayEmployees(Employee emp[], int n) {
    printf("ID\tName\t\tDesignation\tSalary\n");
    printf("---------------------------------------------\n");
    for(int i=0; i<n; i++){
        printf("%d\t%s\t\t%s\t%.2lf\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
    }
}

// Function to find highest salary
void findHighestSalary(Employee emp[], int n) {
    if(n <= 0) return;
    int index = 0;
    for(int i=1; i<n; i++){
        if(emp[i].salary > emp[index].salary)
            index = i;
    }
    printf("\nEmployee with highest salary:\n");
    printf("ID: %d, Name: %s, Designation: %s, Salary: %.2lf\n",
           emp[index].id, emp[index].name, emp[index].designation, emp[index].salary);
}

// Function to search by ID or Name
void searchEmployee(Employee emp[], int n) {
    int choice;
    printf("\nSearch by: 1. ID  2. Name: ");
    scanf("%d", &choice);
    if(choice == 1){
        int searchID;
        printf("Enter Employee ID: "); scanf("%d", &searchID);
        for(int i=0; i<n; i++){
            if(emp[i].id == searchID){
                printf("Found: ID: %d, Name: %s, Designation: %s, Salary: %.2lf\n",
                        emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
                return;
            }
        }
        printf("Employee not found.\n");
    } else if(choice == 2){
        char searchName[MAX_NAME];
        printf("Enter Employee Name: "); scanf(" %[^\n]", searchName);
        for(int i=0; i<n; i++){
            if(strcmp(emp[i].name, searchName) == 0){
                printf("Found: ID: %d, Name: %s, Designation: %s, Salary: %.2lf\n",
                        emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
                return;
            }
        }
        printf("Employee not found.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

// Function to apply 10% bonus for salary < threshold
void applyBonus(Employee emp[], int n, double threshold) {
    for(int i=0; i<n; i++){
        if(emp[i].salary < threshold){
            emp[i].salary *= 1.10; // increase by 10%
        }
    }
}

int main() {
    int n;
    printf("Enter number of employees: "); scanf("%d", &n);

    Employee employees[n]; // array of employees

    inputEmployees(employees, n);
    displayEmployees(employees, n);
    findHighestSalary(employees, n);
    searchEmployee(employees, n);

    printf("\nApplying 10%% bonus for salary below 50000...\n");
    applyBonus(employees, n, 50000);
    displayEmployees(employees, n);

    return 0;
}
