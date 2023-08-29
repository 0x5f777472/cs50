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
    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("File could not be opened.\n");
        fclose(input);
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
    fseek(input, 0L, SEEK_END);
    int sz = ftell(input);
    int num_samples = (sz - sizeof(WAVHEADER)) / block_size;
    for (long int i = block_size; i < (sz - sizeof(WAVHEADER)); i += 2 * block_size)
    {
        char buffer[block_size];
        fseek(input, -i, SEEK_END);
        fread(buffer, 1, block_size, input);
        fseek(output, 0L, SEEK_END);
        fwrite(buffer, 1, block_size, output);
    }
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