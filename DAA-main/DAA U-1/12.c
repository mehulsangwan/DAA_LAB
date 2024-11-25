#include <stdio.h>

int countNonZeroElements(int arr[][3], int rows, int cols)
{
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int arr[3][3] = {
        {1, 0, 3},
        {0, 5, 6},
        {7, 8, 0} 
        
    };

    int nonZeroCount = countNonZeroElements(arr, 3, 3);

    printf("Total number of non-zero elements: %d\n", nonZeroCount);

    return 0;
}