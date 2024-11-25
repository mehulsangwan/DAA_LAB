#include <stdio.h>

double divide(int dividend, int divisor) {
    double low = 0, high = dividend, mid;
    double epsilon = 0.00001;
    while (high - low > epsilon) {
        mid = (low + high) / 2;
        if (mid * divisor > dividend) high = mid;
        else low = mid;
    }
    return (low + high) / 2;
}

int main() {
    int dividend = 10, divisor = 2;
    printf("Result of %d / %d = %.5f\n", dividend, divisor, divide(dividend, divisor));
    return 0;
}
