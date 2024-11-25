#include <stdio.h>

int searchInCircularArray(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        if (arr[low] <= arr[mid]) {
            if (key >= arr[low] && key < arr[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if (key > arr[mid] && key <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int index = searchInCircularArray(arr, n, key);
    if (index != -1) printf("Element found at index: %d\n", index);
    else printf("Element not found\n");
    return 0;
}
