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
    char *input = argv[1];
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    if (strcmp(input[strlen[input] - 4], ".") != 0 || strcmp(input[strlen[input] - 3], "w") != 0 || strcmp(input[strlen[input] - 2], "a") != 0 || strcmp(input[strlen[input] - 1], "v") != 0)
    {
        printf("Input is not a WAV file.");
        return 1;
    }
    // Open input file for reading
    // TODO #2
    if (fopen(input, "r") == NULL)
    {
        return 1;
    }

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