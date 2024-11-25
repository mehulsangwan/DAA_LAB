#include <stdio.h>

void multiplyMatrices(int *a, int *b, int *result, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            *(result + i * p + j) = 0;
            for (int k = 0; k < n; k++) {
                *(result + i * p + j) += *(a + i * n + k) * *(b + k * p + j);
            }
        }
    }
}

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{1, 2}, {3, 4}};
    int result[2][2];

    multiplyMatrices((int *)a, (int *)b, (int *)result, 2, 2, 2);

    printf("Product of matrices:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
