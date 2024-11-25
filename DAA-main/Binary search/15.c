#include <stdio.h>

int findOddOccurrence(int arr[], int low, int high) {
    if (low > high) return -1;
    
    int mid = (low + high) / 2;
    
    if (mid % 2 == 0) {
        if (arr[mid] == arr[mid + 1]) return findOddOccurrence(arr, mid + 2, high);
        else return findOddOccurrence(arr, low, mid - 1);
    } else {
        if (arr[mid] == arr[mid - 1]) return findOddOccurrence(arr, mid + 1, high);
        else return findOddOccurrence(arr, low, mid - 1);
    }
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Odd occurring element: %d\n", findOddOccurrence(arr, 0, n - 1));
    return 0;
}
