#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int findLargestIndex(int *arr, int size)
{
    int largestIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[largestIndex])
        {
            largestIndex = i;
        }
    }
    return largestIndex;
}

int findKey(FILE *f)
{
    int c;
    int letterCounts[26] = {0};
    while ((c = fgetc(f)) != EOF)
    {
        c = tolower(c) - 'a';
        letterCounts[c]++;
    }
    int eindex = findLargestIndex(letterCounts, 26) - 4;
    return eindex;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: breaker inputfile.txt\n");
        return EXIT_FAILURE;
    }

    FILE *inf = fopen(argv[1], "r");
    if (inf == NULL)
    {
        perror("Could not open file\n");
        return EXIT_FAILURE;
    }
    int key = findKey(inf);
    printf("%d\n", key);
    if (fclose(inf) != 0)
    {
        perror("Failed to close file\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}