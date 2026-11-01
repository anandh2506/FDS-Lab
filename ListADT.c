#include <stdio.h>
#define MAXSIZE 50

int arr[MAXSIZE], index = 0, nofelements = 0;

void append(int data) {
    if (nofelements >= MAXSIZE) {
        printf("Error: Array Overflow\n");
        return;
    }
    arr[index] = data;
    index++;
    nofelements++;
}

void traverse() {
    int i; // Use a local variable instead of modifying the global 'index'
    for (i = 0; i < nofelements; i++) {
        printf("%d->", arr[i]);
    }
    printf("NULL\n");
}

void prepend(int data) {
    if (nofelements >= MAXSIZE) {
        printf("Error: Array Overflow\n");
        return;
    }
    int i;
    for (i = index; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = data;
    index++;
    nofelements++;
}

void insert(int data, int pos) {
    if (nofelements >= MAXSIZE) {
        printf("Error: Array Overflow\n");
        return;
    }
    if (pos < 0 || pos > nofelements) {
        printf("Error: Invalid position\n");
        return;
    }
    int i;
    for (i = index; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = data;
    index++;
    nofelements++;
}

int getnofelements() {
    return nofelements;
}

int main() {
    int n;
    append(5);
    append(6);
    append(7);
    prepend(8);
    prepend(9);
    insert(4, 2);
    
    traverse();
    
    n = getnofelements();
    printf("nof elements: %d\n", n);
    
    return 0;
}
