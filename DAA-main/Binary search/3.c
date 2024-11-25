//FIRST OCCURENCE
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

int main() {
    int arr[] = {2, 4, 10, 10, 10, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int index = findFirstOccurrence(arr, n, key);
    if (index != -1) printf("First occurrence at index: %d\n", index);
    else printf("Element not found\n");
    printf("\n-------------------------------------------------------------------------------\n");
    return 0;
}


//LAST OCCURENCE
/*
#include <stdio.h>

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

int main() {
    int arr[] = {2, 4, 10, 10, 10, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int index = findLastOccurrence(arr, n, key);
    if (index != -1) printf("Last occurrence at index: %d\n", index);
    else printf("Element not found\n");
    return 0;
}

*/