#include <stdio.h>
#include <stdbool.h>

void printDistinctElements(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        bool isDistinct = true;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }

      
        if (isDistinct) {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int arr[] = {12, 10, 9, 45, 2, 10, 10, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Distinct elements in the array are:\n");
    printDistinctElements(arr, n);

    return 0;
}
