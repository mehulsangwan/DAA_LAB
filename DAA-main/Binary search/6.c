#include <stdio.h>
void findFloorCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int floor = -1, ceil = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            floor = ceil = arr[mid];
            break;
        } else if (arr[mid] < x) {
            floor = arr[mid];
            low = mid + 1;
        } else {
            ceil = arr[mid];
            high = mid - 1;
        }
    }
    if (floor != -1) printf("Floor: %d\n", floor);
    else printf("Floor: not found\n");

    if (ceil != -1) printf("Ceil: %d\n", ceil);
    else printf("Ceil: not found\n");
}

int main() {
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    findFloorCeil(arr, n, x);
    return 0; }
