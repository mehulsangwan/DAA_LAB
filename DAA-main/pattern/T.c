#include <stdio.h>
void printT() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (i == 0 || j == 3)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printT();
    return 0;
}
