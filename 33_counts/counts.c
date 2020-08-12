#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t *createCounts(void)
{
    //mallocs a counts_t * and initializes its values
    counts_t *count = malloc(sizeof(*count));
    count->arr = NULL;
    count->size = 0;
    count->unknowns = 0;
    return count;
}
int foundCount(counts_t *c, const char *name)
{
    //finds 'name' in 'c'
    //if found, return the index, else, return -1
    int found = -1;
    for (size_t i = 0; i < c->size; i++)
    {
        if (strcmp(c->arr[i]->string, name) == 0)
        {
            found = i;
        }
    }
    return found;
}
void addCount(counts_t *c, const char *name)
{
    //given 'c' and 'name', increment the count for 'name' in 'c'
    //if 'name' is NULL, it means the string is unknown
    if (name == NULL)
    {
        c->unknowns++;
    }
    else
    {
        int index = foundCount(c, name);
        if (index > -1) //if 'name' is already in the array c->arr
        {
            c->arr[index]->count++;
        }
        else
        {
            one_count_t *tmp = malloc(sizeof(*tmp));
            tmp->count = 1;
            tmp->string = (char *)name;
            c->arr = realloc(c->arr, (1 + c->size) * sizeof(*c->arr));
            c->arr[c->size] = tmp;
            c->size++;
        }
    }
}
void printCounts(counts_t *c, FILE *outFile)
{
    //given a counts_t*, print out the data in the counts_t in the form of
    //"string: count"
    for (size_t i = 0; i < c->size; i++)
    {
        fprintf(outFile, "%s: %zu\n", c->arr[i]->string, c->arr[i]->count);
    }
    if (c->unknowns > 0)
    {
        fprintf(outFile, "<unknown> : %zu\n", c->unknowns);
    }
}

void freeCounts(counts_t *c)
{
    //given a counts_t*, free the memory that was allocated to it
    for (size_t i = 0; i < c->size; i++)
    {
        free(c->arr[i]);
    }
    free(c->arr);
    free(c);
}
