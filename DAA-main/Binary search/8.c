#include <stdio.h>

int countOnes(int arr[], int n) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == 1) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (result == -1) return 0;
    return n - result;
}

int main() {
    int arr[] = {0, 0, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Number of 1's: %d\n", countOnes(arr, n));
    return 0;
}
