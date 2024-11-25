#include <stdio.h>
#include <limits.h> // For INT_MAX and INT_MIN

void findSecondSmallestAndBiggest(int *arr, int n, int **secondSmallest, int **secondBiggest)
{
    int *smallest = arr;
    int *biggest = arr;
    *secondSmallest = NULL;
    *secondBiggest = NULL;

    for (int i = 1; i < n; i++)
    {
        if (*(arr + i) < *smallest)
        {
            smallest = arr + i;
        }
        if (*(arr + i) > *biggest)
        {
            biggest = arr + i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((arr + i) != smallest)
        {
            if (*secondSmallest == NULL || *(arr + i) < **secondSmallest)
            {
                *secondSmallest = arr + i;
            }
        }

        if ((arr + i) != biggest)
        {
            if (*secondBiggest == NULL || *(arr + i) > **secondBiggest)
            {
                *secondBiggest = arr + i;
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *secondSmallest, *secondBiggest;

    findSecondSmallestAndBiggest(arr, n, &secondSmallest, &secondBiggest);

    if (secondSmallest != NULL && secondBiggest != NULL)
    {
        printf("Second Smallest: %d\n", *secondSmallest);
        printf("Second Biggest: %d\n", *secondBiggest);

        swap(secondSmallest, secondBiggest);

        printf("\nArray after swapping second smallest and second biggest:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Array doesn't have enough distinct elements for second smallest and second biggest.\n");
    }

    return 0;
}
