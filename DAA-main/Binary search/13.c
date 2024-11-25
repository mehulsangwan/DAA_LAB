#include <stdio.h>

double squareRoot(int x) {
    double low = 0, high = x, mid;
    double epsilon = 0.00001;
    while (high - low > epsilon) {
        mid = (low + high) / 2;
        if (mid * mid > x) high = mid;
        else low = mid;
    }
    return (low + high) / 2;
}

int main() {
    int x = 10;
    printf("Square root of %d is %.5f\n", x, squareRoot(x));
    return 0;
}
