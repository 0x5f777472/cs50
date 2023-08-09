// #include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int count_letters(char *text);
int count_words(char *text);
int count_sentences(char *text);

int main(void)
{
    char input[2048];
    printf("Text: ");
    fgets(input, sizeof(input), stdin);
    float W = count_words(input);
    float L = 100 * count_letters(input) / W;
    float S = 100 * count_sentences(input) / W;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    return 0;
}

int count_letters(char *text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            count++;
        }
    }
    return count;
}

int count_words(char *text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]) != 0)
        {
            count++;
        }
    }
    return count;
}

int count_sentences(char *text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}