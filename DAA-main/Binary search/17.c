#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
void findKClosestElements(int arr[], int n, int x, int k) {
    int idx = binarySearch(arr, n, x);
    int left = idx - 1, right = idx;
    while (k--) {
        if (left >= 0 && right < n) {
            if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                printf("%d ", arr[left]);
                left--;
            } else {
                printf("%d ", arr[right]);
                right++;
            }
        } else if (left >= 0) {
            printf("%d ", arr[left]);
            left--;
        } else {
            printf("%d ", arr[right]);
            right++;
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int k = 3;
    findKClosestElements(arr, n, x, k);
    return 0;
}
