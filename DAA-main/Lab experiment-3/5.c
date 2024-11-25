//SUM OF SUBSET

#include <stdio.h>
int isSubsetSum(int set[], int n, int sum) {
    if (sum == 0) 
        return 1;
    if (n == 0 && sum != 0) 
        return 0;

    if (set[n - 1] > sum) 
        return isSubsetSum(set, n - 1, sum);

    return isSubsetSum(set, n - 1, sum) || 
           isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
    int n, sum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the required sum: ");
    scanf("%d", &sum);

    if (isSubsetSum(set, n, sum))
        printf("A subset with the given sum exists.\n");
    else
        printf("No subset with the given sum exists.\n");

    return 0;
}

/*

//N QUEEN PROBLEM
#include <stdio.h>
#define N 8 

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQUtil(int board[N][N], int col) {
    if (col >= N)
        return 1;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return 1;

            board[i][col] = 0;
        }
    }
    return 0;
}

void solveNQ() {
    int board[N][N] = {0};

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist.\n");
        return;
    }

    printSolution(board);
}

int main() {
    printf("Solving the N-Queens problem for %d queens:\n", N);
    solveNQ();
    return 0;
}
*/