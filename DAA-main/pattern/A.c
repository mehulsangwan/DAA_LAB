#include <stdio.h>
void printA() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == 4 - i || j == 4 + i || (i == 2 && j > 0 && j < 8))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printA();
    return 0;
}
