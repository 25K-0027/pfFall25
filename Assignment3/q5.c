#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 200

int main() {
    int n = 0;           // number of lines
    int capacity = 5;    // initial capacity
    char **lines = malloc(capacity * sizeof(char*));
    if(!lines) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice;
    char buffer[MAX_LINE];

    do {
        printf("\n1.Insert Line\n2.Delete Line\n3.Print Lines\n4.Exit\nChoose: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        if(choice == 1) {
            if(n == capacity){
                capacity *= 2;
                lines = realloc(lines, capacity * sizeof(char*));
            }
            printf("Enter text: ");
            fgets(buffer, MAX_LINE, stdin);
            buffer[strcspn(buffer, "\n")] = 0; // remove newline

            lines[n] = malloc(strlen(buffer)+1);
            strcpy(lines[n], buffer);
            n++;
        } else if(choice == 2) {
            int index;
            printf("Enter line number to delete (0-%d): ", n-1);
            scanf("%d", &index);
            getchar();

            if(index >=0 && index < n){
                free(lines[index]);
                for(int i=index+1; i<n; i++)
                    lines[i-1] = lines[i];
                n--;
            } else {
                printf("Invalid index\n");
            }
        } else if(choice == 3) {
            printf("\n--- Text Editor Content ---\n");
            for(int i=0; i<n; i++)
                printf("%d: %s\n", i, lines[i]);
        } else if(choice == 4) {
            printf("Exiting...\n");
        } else {
            printf("Invalid choice\n");
        }
    } while(choice != 4);

    // Free memory
    for(int i=0; i<n; i++)
        free(lines[i]);
    free(lines);

    return 0;
}
