#include <stdio.h>
void printR() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (j == 0 || j == 6 || (i == 0 && j < 6) || (i == 2 && j < 6) || (i == j && i > 2))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printR();
    return 0;
}
