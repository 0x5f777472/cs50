#include <cs50.h>
#include <stdio.h>
int count(long number);
int main(void)
{
    while (1) {
        long input = get_long("Number: ");
        int length = count(input);
        if (length == 13 || length == 16) {
            
        }
    }
}
int count(long number) {
    int count = 1;
    while (number > 9) {
        number /= 10;
        count++;
    }
    return count;
}