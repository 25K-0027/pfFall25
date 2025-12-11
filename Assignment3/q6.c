#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define INIT_CAP 5

typedef struct {
    int id;
    char name[MAX_NAME];
    char batch[20];
    char membership[10];
} Student;

int main() {
    int n = 0, capacity = INIT_CAP;
    Student *students = malloc(capacity * sizeof(Student));
    if(!students){
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    do {
        printf("\n1.Add Student 2.Display All 3.Exit\nChoose: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        if(choice == 1){
            if(n >= capacity){
                capacity *= 2;
                students = realloc(students, capacity * sizeof(Student));
            }
            printf("Enter ID: "); scanf("%d", &students[n].id); getchar();
            printf("Enter Name: "); fgets(students[n].name, MAX_NAME, stdin);
            students[n].name[strcspn(students[n].name,"\n")] = 0;
            printf("Enter Batch: "); scanf("%s", students[n].batch);
            printf("Enter Membership: "); scanf("%s", students[n].membership);
            n++;
        } else if(choice == 2){
            printf("\nID\tName\tBatch\tMembership\n");
            for(int i=0;i<n;i++){
                printf("%d\t%s\t%s\t%s\n", students[i].id, students[i].name, students[i].batch, students[i].membership);
            }
        } else if(choice == 3){
            printf("Exiting...\n");
        } else{
            printf("Invalid choice\n");
        }

    } while(choice != 3);

    free(students);
    return 0;
}
