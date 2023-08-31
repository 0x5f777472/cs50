// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(&header, 1, HEADER_SIZE, input);
    fwrite(&header, 1, HEADER_SIZE, output);
    // TODO: Read samples from input file and write updated data to output file
    fseek(input, 0L, SEEK_END);
    int sz = ftell(input);
    fseek(input, (long)HEADER_SIZE, SEEK_SET);
    fseek(output, (long)HEADER_SIZE, SEEK_SET);
    for (long int i = 1; i < sz - HEADER_SIZE; i+=2)
    {
        int16_t buffer = 0;
        fread(&buffer, 2, 1, input);
        buffer *= factor;
        fseek(output, 2L, SEEK_CUR);
        fwrite(&buffer, 2, 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
