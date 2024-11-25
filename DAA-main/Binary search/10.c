#include <stdio.h>

int findMissingTerm(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + arr[0]) low = mid + 1;
        else high = mid - 1;
    }
    return arr[low] - 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Missing term: %d\n", findMissingTerm(arr, n));
    return 0;
}
