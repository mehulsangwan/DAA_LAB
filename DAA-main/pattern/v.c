#include <stdio.h>
void printV() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == i || j == 8 - i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printV();
    return 0;
}
