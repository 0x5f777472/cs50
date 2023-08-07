#include <cs50.h>
#include <stdio.h>
int count(long number);
int main(void)
{
    while (1) {
        long input = get_long("Number: ");
        int c = count(input);
        printf("%d\n", c);
    }
}
int count(long number) {
    for (int i = 0; number > 1; i++) {
        number /= 10;
        return i;
    }
    return 0;
}