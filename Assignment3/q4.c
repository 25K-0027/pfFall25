#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    int popularity;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int size;   // current number of books on shelf
    int capacity; // max books shelf can hold
} Shelf;

// Function to find book index by ID
int findBookIndex(Shelf *shelf, int id) {
    for(int i=0; i<shelf->size; i++){
        if(shelf->books[i].id == id)
            return i;
    }
    return -1; // not found
}

// ADD operation
void addBook(Shelf *shelf, int id, int popularity) {
    int idx = findBookIndex(shelf, id);
    if(idx != -1){
        // book exists, update popularity
        shelf->books[idx].popularity = popularity;
        return;
    }

    // if shelf full, remove first (least recently added) book
    if(shelf->size == shelf->capacity){
        for(int i=1; i<shelf->size; i++){
            shelf->books[i-1] = shelf->books[i];
        }
        shelf->size--;
    }

    // add new book at end
    shelf->books[shelf->size].id = id;
    shelf->books[shelf->size].popularity = popularity;
    shelf->size++;
}

// ACCESS operation
int accessBook(Shelf *shelf, int id) {
    int idx = findBookIndex(shelf, id);
    if(idx == -1)
        return -1;

    // Move accessed book to end (simulate recent access)
    Book temp = shelf->books[idx];
    for(int i=idx+1; i<shelf->size; i++){
        shelf->books[i-1] = shelf->books[i];
    }
    shelf->books[shelf->size-1] = temp;

    return temp.popularity;
}

int main() {
    Shelf shelf;
    shelf.size = 0;
    int Q;
    printf("Enter shelf capacity and number of operations: ");
    scanf("%d %d", &shelf.capacity, &Q);

    for(int i=0; i<Q; i++){
        char op[10];
        int x, y;
        printf("Enter operation: ");
        scanf("%s", op);

        if(strcmp(op,"ADD") == 0){
            scanf("%d %d", &x, &y);
            addBook(&shelf, x, y);
        } else if(strcmp(op,"ACCESS") == 0){
            scanf("%d", &x);
            int pop = accessBook(&shelf, x);
            printf("%d\n", pop);
        } else {
            printf("Invalid operation\n");
        }
    }

    return 0;
}
