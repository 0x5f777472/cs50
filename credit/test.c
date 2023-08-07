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
int luhn(long number) {
    int sum = 0;
    for (int i = 1; i < count(number); i += 2) {
        if (count(nth(number, i) > 1)) {
            
        }
        sum += nth(number, i);
    }
    for (int i = 0; i < count(number); i += 2) {
        sum += nth(number, i);
    }
    return sum;
}
int main(void) {
    int blah = luhn(4003600000000014);
    printf("%d\n", blah);
}
