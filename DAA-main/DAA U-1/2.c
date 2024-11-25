#include <stdio.h>

void insertElement(int arr[], int *n, int pos, int val) {
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    (*n)++;
}

void deleteElement(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5;

    insertElement(arr, &n, 2, 10);  // Insert 10 at index 2
    deleteElement(arr, &n, 1);  // Delete element at index 1

    printf("Updated array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
