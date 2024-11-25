#include <stdio.h>

int searchInNearlySortedArray(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) return mid;
        if (mid > low && arr[mid - 1] == key) return mid - 1;
        if (mid < high && arr[mid + 1] == key) return mid + 1;

        if (key < arr[mid]) high = mid - 2;
        else low = mid + 2;
    }
    return -1;
}

int main() {
    int arr[] = {3, 2, 10, 4, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int index = searchInNearlySortedArray(arr, n, key);
    if (index != -1) printf("Element found at index: %d\n", index);
    else printf("Element not found\n");
    return 0;
}
