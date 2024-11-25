#include <stdio.h>
void findFloorCeilRecursive(int arr[], int low, int high, int key, int* floor, int* ceil) {
    if (low > high) return;
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        *floor = *ceil = arr[mid];
        return;
    }
    if (arr[mid] < key) {
        *floor = arr[mid];
        findFloorCeilRecursive(arr, mid + 1, high, key, floor, ceil);
    } else {
        *ceil = arr[mid];
        findFloorCeilRecursive(arr, low, mid - 1, key, floor, ceil);
    }
}
int main() {
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int floor = -1, ceil = -1;
    findFloorCeilRecursive(arr, 0, n - 1, key, &floor, &ceil);
    if (floor != -1) printf("Floor: %d\n", floor);
    else printf("Floor: not found\n");
    if (ceil != -1) printf("Ceil: %d\n", ceil);
    else printf("Ceil: not found\n");
    return 0;
}
