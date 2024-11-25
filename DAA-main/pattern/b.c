#include <stdio.h>
void printB() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (j == 0 || j == 6 || (i == 0 && j < 6) || (i == 2 && j < 6) || (i == 4 && j < 6))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printB();
    return 0;
}
