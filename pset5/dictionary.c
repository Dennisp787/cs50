// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

//kepp track of number of words in dict
int num;

//if dict is loaded
bool is_loaded = false;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //len of original word
    int ow = strlen(word);

    //place to store coppied word
    char cword[ow];

    //copy orininal word
    strcpy(cword, word);

    //lowercase all leters
    for (int i = 0; i < ow; i++)
    {
        cword[i] = tolower(cword[i]);
    }

    //get hash number of copied word
    int hcw = hash(cword);

    //node is point in table
    node *tcopy = table[hcw];

    while (tcopy != NULL)
    {
        if (strcasecmp(tcopy->word, cword) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
//hash table from youtube ->  `Deliberate Think
unsigned int hash(const char *word)
{
    int h = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;

        }
        else
        {
            n = 27;
        }
        h = ((h << 3) + n) % N;
    }
    return h;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open dictionary file
    FILE *dict = fopen(dictionary, "r");

    //check if dictionary exist
    if (dict == NULL)
    {
        return 1;
    }

    //create array to store word
    char word[LENGTH + 1];

    while (fscanf(dict, "%s", word) != EOF)
    {

        //create new node for each word
        node *n = malloc(sizeof(node));

        //if not enough memory
        if (n == NULL)
        {
            return 1;
        }

        //set word of node to scanned word
        strcpy(n->word, word);

        //if word sucessfully added add to count of overall words
        num++;

        //find index of word
        int h_index = hash(word);

        n->next = table[h_index];
        table[h_index] = n;

    }


    is_loaded = true;
    fclose(dict);
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (is_loaded == false)
    {
        return 1;
    }
    return num;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (is_loaded == false)
    {
        return 1;
    }

    //iterate through table
    for (int i = 0; i < N; i++)
    {
        node *tcopy = table[i];

        while (tcopy != NULL)
        {

            node *tcc = tcopy;
            tcopy = tcopy->next;
            free(tcc);

        }
    }
    return true;
}
