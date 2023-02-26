#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void sieve(int max, bool primes[]);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    bool primes[max + 1];
    sieve(max, primes);

    for (int i = min; i <= max; i++)
    {
        if (primes[i])
        {
            printf("%i\n", i);
        }
    }
}

void sieve(int max, bool primes[])
{
    for (int i = 0; i <= max; i++)
    {
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;

    int limit = sqrt(max);
    for (int i = 2; i <= limit; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= max; j += i)
            {
                primes[j] = false;
            }
        }
    }
}
