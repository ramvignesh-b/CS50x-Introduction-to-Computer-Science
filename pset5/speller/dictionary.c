// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"


// Global Variable
int wordCount = 0;
int hashValue;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash the incoming word
    hashValue = hash(word);
    // Search in the hashtable
    node *n = table[hashValue];
    // Check the first node
    if (strcasecmp(n->word, word) == 0)
    {
        return true;
    }
    // Traverse and check
    do
    {
        if (strcasecmp(n->word, word) == 0)
        {
            // Word found!
            return true;
        }
        n = n->next;
    }
    while (n != NULL);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // 1 bucket for each alphabet
    hashValue = (int) tolower(word[0]) - 97;
    return hashValue;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open the dictionary file in read mode
    FILE *file = fopen(dictionary, "r");
    // Initialise a temp space to hold words
    char *dictionaryWord = malloc(LENGTH + 1);
    if (dictionaryWord == NULL)
    {
        // Can't allocate space
        return false;
    }

    // Read till End of File
    while (fscanf(file, "%s", dictionaryWord) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // Can't allocate space
            return false;
        }
        strcpy(n->word, dictionaryWord);
        wordCount++;

        // Append the current node to the beginning of the linked list
        hashValue = hash(dictionaryWord);
        n->next = table[hashValue];
        // Array points at the linked list
        table[hashValue] = n;
    }
    fclose(file);
    free(dictionaryWord);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Return the word count
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *temp;
    node *n;
    // Traverse and delte the linked list in each tables
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            // No linked list found on the array.
            continue;
        }
        n = table[i];
        temp = n;
        while (n->next != NULL)
        {
            n = n->next;
            free(temp);
            temp = n;
        }
        free(n);
    }
    return true;
}
