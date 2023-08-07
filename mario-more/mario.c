#include <cs50.h>
#include <stdio.h>

int main(void)
{
    while (1) {
        int input = get_int("Height: ");
        if (input < 1 || input > 8) {
            break;
        }
        for (int i = 1; i <= input; i++) {
            for (int j = 0;j < input - i; j++) {
                printf(" ");
            }
            for (int j = 0; j < i; j++) {
                printf("#");
            }
            printf("  ");
            for (int j = 0; j < i; j++) {
                printf("#");
            }
            printf("\n");
        }
        break;
    }
    return 0;

}