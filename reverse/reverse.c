#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    if (argv[1][strlen(argv[1]) - 4] != '.' || argv[1][strlen(argv[1]) - 3] != 'w' || argv[1][strlen(argv[1]) - 2] != 'a' || argv[1][strlen(argv[1]) - 1] != 'v')
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }
    // Open input file for reading
    // TODO #2
    if (fopen(argv[1], "r") == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");

    // Read header
    // TODO #3

    // Use check_format to ensure WAV format
    // TODO #4

    // Open output file for writing
    // TODO #5

    // Write header to file
    // TODO #6

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    // TODO #4
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}