#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

void stripNewLine(char *string)
{
    //given a string, strip the newline at the end of it if there is any
    char *newline = strchr(string, '\n');
    if (newline != NULL)
    {
        *newline = '\0';
    }
}
counts_t *countFile(const char *filename, kvarray_t *kvPairs)
{
    //given a file containing keys and a kvarray_t*, compute the counts of the values in the file
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        fprintf(stderr, "Could not open file %s", filename);
        return NULL;
    }
    //read each line of filename
    //for each line, check if it is in the kvarray_t keys
    counts_t *result = createCounts();
    char *key = NULL;
    size_t sz;
    int found = 0;
    while (getline(&key, &sz, f) > 1) // '>1' to make sure trailing newlines aren't misinterpreted as keys
    {
        //getline also reads in the newline at the end of a line
        //so we need to remove it
        stripNewLine(key);

        for (size_t i = 0; i < kvPairs->size; i++)
        {
            if (strcmp(kvPairs->kvarr[i]->key, key) == 0)
            {
                addCount(result, kvPairs->kvarr[i]->value);
                found = 1;
            }
        }
        if (!found)
        {
            addCount(result, NULL);
        }
        found = 0;
    }
    free(key);
    if (fclose(f) != 0)
    {
        fprintf(stderr, "Could not close file %s", filename);
        return NULL;
    }
    return result;
}

int main(int argc, char **argv)
{
    //read the key/value pairs from the file named by argv[1] (call the result kv)
    FILE *keyvalues = fopen(argv[1], "r");
    if (keyvalues == NULL)
    {
        fprintf(stderr, "Could not open file %s", argv[1]);
        return EXIT_FAILURE;
    }
    kvarray_t *kv = readKVs(argv[1]);
    if (fclose(keyvalues) != 0)
    {
        perror("Could not close keyvalue file\n");
        return EXIT_FAILURE;
    }

    //count from 2 to argc (call the number you count i)
    for (size_t i = 2; i < argc; i++)
    {
        counts_t *c = countFile(argv[i], kv);
        char *outName = computeOutputFileName(argv[i]);
        FILE *f = fopen(outName, "w");
        if (f == NULL)
        {
            perror("Could not open an output file\n");
            return EXIT_FAILURE;
        }
        printCounts(c, f);
        if (fclose(f) != 0)
        {
            fprintf(stderr, "Could not close output file %s", outName);
        }
        free(outName);
        freeCounts(c);
    }
    freeKVs(kv);

    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)

    //compute the output file name from argv[i] (call this outName)

    //open the file named by outName (call that f)

    //print the counts from c into the FILE f

    //close f

    //free the memory for outName and c

    //free the memory for kv

    return EXIT_SUCCESS;
}
