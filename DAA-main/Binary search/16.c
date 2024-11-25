#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return 1;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}

void findPairsWithDifferenceK(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (binarySearch(arr, n, arr[i] + k)) {
            printf("Pair: (%d, %d)\n", arr[i], arr[i] + k);
        }
    }
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    findPairsWithDifferenceK(arr, n, k);
    return 0;
}
