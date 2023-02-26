#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <pthread.h>
#include <stdint.h>

#define MAX_THREADS 8

void* sieve(void* args);

typedef struct {
    int max;
    uint32_t* primes;
    uint64_t* cache;
} thread_data_t;

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

    // Determine the number of primes less than the square root of the maximum
    int sqrt_max = sqrt(max);
    int num_primes = sqrt_max - 1;

    // Allocate memory for the primes bit array and the cache array
    uint32_t* primes = (uint32_t*) calloc((max / 32) + 1, sizeof(uint32_t));
    uint64_t* cache = (uint64_t*) calloc((max / 64) + 1, sizeof(uint64_t));

    // Initialize the cache array with the first 64 prime numbers
    uint64_t mask = 1;
    int count = 0;
    for (int i = 2; i <= 313; i++)
    {
        if (primes[i / 32] & (mask << (i % 32)))
        {
            cache[count / 64] |= (mask << (count % 64));
            count++;
        }
    }

    // Divide the range of numbers to be checked into subranges for each thread
    int range_size = (max - sqrt_max) / MAX_THREADS;
    thread_data_t thread_data[MAX_THREADS];
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++)
    {
        thread_data[i].max = i == MAX_THREADS - 1 ? max : sqrt_max + (i + 1) * range_size;
        thread_data[i].primes = primes;
        thread_data[i].cache = cache;
        pthread_create(&threads[i], NULL, sieve, &thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Print out all prime numbers in the range
    for (int i = min; i <= max; i++)
    {
        int index = i / 32;
        uint32_t mask = 1 << (i % 32);
        if ((index > num_primes || (primes[index] & mask)) && !(cache[i / 64] & (1ull << (i % 64))))
        {
            printf("%d\n", i);
        }
    }

    // Free memory
    free(primes);
    free(cache);
}

void* sieve(void* args)
{
    thread_data_t* data = (thread_data_t*) args;
    int max = data->max;
    uint32_t* primes = data->primes;
    uint64_t* cache = data->cache;
    int sqrt_max = sqrt(max);

    // Calculate the starting index and mask for the thread's chunk of the primes array
