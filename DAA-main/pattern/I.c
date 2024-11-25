#include <stdio.h>
void printI() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 2 || (i == 0 && j > 0 && j < 4) || (i == 4 && j > 0 && j < 4))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printI();
    return 0;
}
