#include "wav.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("File could not be opened.\n");
        fclose(input);
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, 1, sizeof(WAVHEADER), input);
    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(header))
    {
        printf("Input is not a WAV file.\n");
        fclose(input);
        return 1;
    }
    // for (int i = 0; i < sizeof header; i++)
    // {
    //     printf("%d: %c or 0x%0x\n", i , *(header.chunkID + i), *(header.chunkID + i));
    // }
    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "a");
    if (output == NULL)
    {
        printf("File could not be opened.\n");
        fclose(input);
        fclose(output);
        return 1;
    }
    // Write header to file
    // TODO #6
    fwrite(&header, 1, sizeof(WAVHEADER), output);
    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);
    // Write reversed audio to file
    // TODO #8

    fclose(input);
    fclose(output);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return true;
    }
    return false;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int size = header.bitsPerSample * header.numChannels >> 3;
    return size;
}