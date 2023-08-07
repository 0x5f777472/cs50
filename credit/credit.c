#include <cs50.h>
#include <stdio.h>
#include <math.h>
int count(long number);
int luhn(long number);
int main(void)
{
    while (1) {
        long input = get_long("Number: ");
        int length = count(input);
        int initial = input / pow(10, length - 2);
        if (luhn(input) % 10 == 0) {
            if (length == 15 && (initial == 34 || initial == 37)) {
                printf("AMEX\n");
            } else if (length == 16 && (initial == 51 || initial == 52 || initial == 53 || initial == 54 || initial == 55)) {
                printf("MASTERCARD\n");
            } else if ((length == 13 || length == 16) && (initial / 10 == 4)) {
                printf("VISA\n");
            } else {
                printf("INVALID\n");
            }
        }
    }
}

int luhn(long number) {
    for (int sum = 0;; sum += 2) {

    }
    return sum;
}

int count(long number) {
    for (int count = 0;; count++) {
        if (number % pow(10, count) == number) {
            break;
        }
    }
    return count;
}