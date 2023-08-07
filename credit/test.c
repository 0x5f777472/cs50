#include <stdio.h>
#include <math.h>
int nth(long number, int n) {
    return fmod(number / pow(10, n), 10);
}
int count(long number) {
    int count = 1;
    while (number > 9) {
        number /= 10;
        count++;
    }
    return count;
}
int digitsum(long number) {
    int sum = 0;
    for (int i = 0; i < count(number); i++) {
        if (2 * nth(number, i) > 9) {
            sum += digitsum(2 * nth(number, i));
        } else {
            sum += 2 * nth(number, i);
        }
    }
    return sum;
}

int main(void) {
    int blah = digitsum(4003600000000014);
    printf("%d\n", blah);
}
