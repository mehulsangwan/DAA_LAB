#include <stdio.h>
void printC() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (j == 0 || (i == 0 && j > 0) || (i == 4 && j > 0))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printC();
    return 0;
}
