#include <stdio.h>
#include <math.h>
int count(long number) {
    for (int count = 1;; count++) {
        if (number % pow(10, count) == number) {
            break;
        }
    }
    return count;
}
int main(void) {
    printf("%d\n", count(10));
}