#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t *splitOnEquals(char *line)
{
    //splits a string at the equals character and puts it into a kvpair_t and returns it
    //key=value\n
    kvpair_t *pair = malloc(sizeof(*pair));
    char *value = strchr(line, '=');
    *value = '\0'; //key\0value\n
    value++;
    char *key = line;
    char *n = strchr(line, '\n');
    if (n != NULL)
    {
        *n = '\0'; //key\0value\0
    }

    pair->key = key;
    pair->value = value;
    return pair;
}

kvarray_t *readKVs(const char *fname)
{
    //read key value pairs from file and input them into an array and return the array
    FILE *firstinput = fopen(fname, "r");
    if (firstinput == NULL)
    {
        perror("Could not open first input file\n");
        return NULL;
    }
    kvarray_t *result = malloc(sizeof(*result));
    result->kvarr = NULL;
    result->size = 0;
    char *curr = NULL;
    size_t sz;
    while (getline(&curr, &sz, firstinput) > 1) // getline > 1 so that any trailing \n's in the file aren't used to create pairs
    {
        kvpair_t *tmp = splitOnEquals(curr);
        result->kvarr = realloc(result->kvarr, (result->size + 1) * sizeof(*result->kvarr));
        result->kvarr[result->size] = tmp;
        curr = NULL;
        result->size++;
    }
    free(curr);
    if (fclose(firstinput) != 0)
    {
        return NULL;
    }

    return result;
}

void freeKVs(kvarray_t *pairs)
{
    //frees malloced memory in *pairs
    for (int i = 0; i < pairs->size; i++)
    {
        free(pairs->kvarr[i]);
    }
    free(pairs->kvarr);
    free(pairs);
}

void printKVs(kvarray_t *pairs)
{
    //print key value pairs in the form of
    //"key = '%s' value = '%s'\n"
    for (int i = 0; i < pairs->size; i++)
    {
        printf("key = '%s' value = '%s'\n", pairs->kvarr[i]->key, pairs->kvarr[i]->value);
    }
}

char *lookupValue(kvarray_t *pairs, const char *key)
{
    //given 'pairs' and 'key', search 'pairs' for a key 'key'
    //if found, return the key, else, return NULL
    for (int i = 0; i < pairs->size; i++)
    {
        if (strcmp(key, pairs->kvarr[i]->key) == 0)
        {
            return pairs->kvarr[i]->key;
        }
    }
    return NULL;
}
