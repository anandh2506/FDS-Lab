#include <stdio.h>

// Function prototype so bubbleSort knows about printArray beforehand
void printArray(int array[], int n);

void bubbleSort(int array[], int n) {
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        printArray(array, n); // Prints the array after each pass
    }
}

void printArray(int array[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {5, 4, 8, 1, 2}; 
    int n = sizeof(data) / sizeof(data[0]); 
    
    printf("unsorted array:\n"); 
    printArray(data, n); 
    
    bubbleSort(data, n); 
    
    printf("sorted Array ascending order:\n"); 
    printArray(data, n); 
    
    return 0;
}
