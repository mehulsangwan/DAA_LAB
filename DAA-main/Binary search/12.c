#include <stdio.h>

int findFirstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int findLastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

void findFrequencies(int arr[], int n) {
    int i = 0;
    while (i < n) {
        int key = arr[i];
        int first = findFirstOccurrence(arr, n, key);
        int last = findLastOccurrence(arr, n, key);
        printf("Element %d occurs %d times\n", key, last - first + 1);
        i = last + 1;
    }
}

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    findFrequencies(arr, n);
    return 0;
}
