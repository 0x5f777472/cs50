#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%d\n", argc);
    for (int i = 0; i < sizeof(argv); i++)
    {
        printf("%c", argv[i]);
    }
}