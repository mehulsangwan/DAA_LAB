#include <stdio.h>
void printM() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == 0 || j == 8 || (i == j && i <= 4) || (i + j == 8 && i <= 4))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printM();
    return 0;
}
