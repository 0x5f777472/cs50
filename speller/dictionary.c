// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 75000;

// Hash table
node *table[N];

int load_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashed = hash(word);
    node * n = table[hashed];
    while (n)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long blah = 1;
    for (int i = 0; i < strlen(word); i++)
    {
        blah *= word[i];
    }
    return (blah) % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE * dict_ptr = fopen(dictionary, "r");
    if (dict_ptr == NULL)
    {
        printf("Failed to load dictionary.");
        return false;
    }
    char buffer[LENGTH + 1];
    while (fscanf(dict_ptr, "%s", buffer) != EOF)
    {
        node * n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Could not allocate memory for node pointer n");
            return false;
        }
        strcpy(n->word, buffer);
        int hashed = hash(buffer);
        n->next = table[hashed];
        table[hashed] = n;
        load_count++;
        return true;
    }
    fclose(dict_ptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return load_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node * n = table[i];
        while (n)
        {
            node * cur = n;
            free(cur);
            n = n->next;
        }
        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
