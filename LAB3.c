#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h> 

#define SIZE 24
#define nRows 8
#define nCols 3


void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void set_array(int arr[], int length, int values[]);
void rem_align(int arr[], int length, int pos);

int main() {
    int arr[SIZE];
    int arr2d[nRows][nCols];

    
    int initial_values[SIZE];

    for (int i = 0; i < SIZE; i++) {
        initial_values[i] = i;
    }
    
    set_array(arr, SIZE, initial_values);

    
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            arr2d[i][j] = i * nCols + j;
        }
    }

    printf("1D Array:\n");
    print_array(arr, SIZE);

   
    int pos_to_remove = 8;  
    printf("\nRemoving element at position %d\n", pos_to_remove);
    rem_align(arr, SIZE, pos_to_remove);

   
    printf("\nModified 1D Array:\n\n");
    print_array(arr, SIZE);

    return 0;
}


void print_array(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}


void print_matrix(int mat[][nCols], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < nCols; j++)
            printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);
        puts("");
    }
}


void set_array(int arr[], int length, int values[]) {

    for (int i = 0; i < length; i++) {
        arr[i] = i;
    }
}



void rem_align(int arr[], int length, int pos) {
    if (pos < 0 || pos >= length) {
        printf("Invalid array index to remove: %d\n", pos);
        return;
    }

    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[length - 1] = 0;  
}

