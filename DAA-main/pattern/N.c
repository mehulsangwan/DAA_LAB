#include <stdio.h>
void printN() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (j == 0 || j == 6 || i == j)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printN();
    return 0;
}
