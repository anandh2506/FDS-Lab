#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE];

void insert() {
    int key, index, i, hkey;
    printf("\nEnter a value to insert into hash table: ");
    scanf("%d", &key);
    
    hkey = key % TABLE_SIZE;
    
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE;
        // Check for -1 (empty slot) instead of NULL/0
        if (h[index] == -1) {
            h[index] = key;
            printf("Element %d inserted at index %d\n", key, index);
            break;
        }
    }
    
    if (i == TABLE_SIZE) {
        printf("\nElement cannot be inserted (Hash table is full)\n");
    }
}

void search() {
    int key, index, i, hkey;
    printf("\nEnter search element: ");
    scanf("%d", &key);
    
    hkey = key % TABLE_SIZE;
    
    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i) % TABLE_SIZE;
        
        // If we hit an empty slot (-1), the element is definitely not in the table
        if (h[index] == -1) {
            break;
        }
        
        if (h[index] == key) {
            printf("\nValue is found at index %d\n", index);
            return;
        }
    }
    
    printf("\nValue is not found\n");
}

void display() {
    int i;
    printf("\n--- Elements in the hash table ---\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        if (h[i] == -1)
            printf("At index %d \t value = -- (Empty)\n", i);
        else
            printf("At index %d \t value = %d\n", i, h[i]);
    }
    printf("----------------------------------\n");
}

int main() {
    int opt, i;
    
    // Initialize all table slots to -1 to represent empty slots
    for (i = 0; i < TABLE_SIZE; i++) {
        h[i] = -1;
    }
    
    while (1) {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        
        switch (opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    }
    
    return 0;
}
