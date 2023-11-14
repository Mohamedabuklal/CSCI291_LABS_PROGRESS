
#include <stdio.h>
#include <math.h>
void swap_number(int a[], int b[]);
void iterative(int arr[], int n);
int recursive(int arr[], int left_side, int right_side);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    iterative(arr, n);
    recursive(arr, 0, n - 1);

    printf("The Odd values (using recursive func): ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 1) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    printf("The Even values (using recursive func): ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    } printf("\n\n");



    return 0;
}

void iterative(int arr[], int n) {
    int left_side = 0;
    int right_side = n - 1;
    int oddSectionSize = 0;

    while (left_side < right_side) {
      
        while (left_side < right_side && arr[left_side] % 2 == 1) {
            left_side++;
            oddSectionSize++;
        }

        while (left_side < right_side && arr[right_side] % 2 == 0) {
            right_side--;
        }

        swap_number(&arr[left_side], &arr[right_side]);
    }

    if (arr[left_side] % 2 == 1) {
        oddSectionSize++;
    }

    printf("\n\nThe Odd numbers (using iterative func): ");
    for (int i = 0; i < oddSectionSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("The Even numbers (using iterative func): ");
    for (int i = oddSectionSize; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}
void swap_number(int a[], int b[]) {
      int i, j;
    int temp = a[i];
    a[i] = b[j];
    b[j] = temp;
}
int recursive(int arr[], int left_side, int right_side) {
    if (left_side >= right_side) {
        return 0;
    }

    int mid = (left_side + right_side) / 2;
    int i, j;
    i = left_side;
    j = mid + 1;
    while (i <= mid && arr[i] % 2 == 1) {
        i++;
    }
    while (j <= right_side && arr[j] % 2 == 1) {
        j++;
    }
    while (i <= mid && j <= right_side) {
        swap_number(&arr[i], &arr[j]);
        i++;
        j++;
    }
    return recursive(arr, left_side, mid);
    return recursive(arr, mid + 1, right_side);
}


