#include <cs50.h>
#include <stdio.h>
#include <math.h>
int count(long number);
int luhn(long number);
int nth(long number, int n);
int main(void)
{
    while (1) {
        long input = get_long("Number: ");
        int length = count(input);
        int initial = input / pow(10, length - 2);
        if (fmod(luhn(input), 10) == 0) {
            if (length == 15 && (initial == 34 || initial == 37)) {
                printf("AMEX\n");
                return 0;
            } else if (length == 16 && (initial == 51 || initial == 52 || initial == 53 || initial == 54 || initial == 55)) {
                printf("MASTERCARD\n");
                return 0;
            } else if ((length == 13 || length == 16) && (initial / 10 == 4)) {
                printf("VISA\n");
                return 0;
            } else {
                printf("INVALID\n");
                return 0;
            }
        } else {
            printf("INVALID\n");
            return 0;
        }
    }
    return 0;
}

int luhn(long number) {
    int sum = 0;
    for (int i = 1; i < count(number); i += 2) {
        int stupid = 2 * nth(number, i);
        for (int j = 0; j < count(stupid); j++) {
            sum += nth(stupid, j);
        }
    }
    for (int i = 0; i < count(number); i += 2) {
        sum += nth(number, i);
    }
    return sum;
}

int count(long number) {
    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}
int nth(long number, int n) {
    return fmod(number / pow(10, n), 10);
}