#include <stdio.h>
void printZ() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (i == 0 || i == 4 || i + j == 6)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printZ();
    return 0;
}
