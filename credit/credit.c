#include <cs50.h>
#include <stdio.h>
int count(long number);
int luhn(long number);
int main(void)
{
    while (1) {
        long input = get_long("Number: ");
        int length = count(input);
        int initial = ;
        if (luhn(input) % 10 == 0) {
            if (length == 13)
        }
    }
}

int luhn(long number) {

    return 0;
}

int count(long number) {
    int count = 1;
    while (number > 9) {
        number /= 10;
        count++;
    }
    return count;
}