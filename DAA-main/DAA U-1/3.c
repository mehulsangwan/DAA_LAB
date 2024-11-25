#include <stdio.h>
#include <ctype.h>

void toLowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char str[] = "HELLO WORLD";
    toLowercase(str);
    printf("Lowercase string: %s\n", str);
    return 0;
}
