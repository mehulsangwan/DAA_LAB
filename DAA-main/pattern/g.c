#include <stdio.h>
void printG() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (j == 0 || (i == 0 && j > 0) || (i == 4 && j > 0) || (i == 2 && j >= 3 && j < 6))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printG();
    return 0;
}
