#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This function is used to figure out the ordering
//of the strings in qsort. You do not need
//to modify it.

int stringOrder(const void *vp1, const void *vp2)
{
    const char *const *p1 = vp1;
    const char *const *p2 = vp2;
    return strcmp(*p1, *p2);
}

//This function will sort and print data (whose length is count).

void sortData(char **data, size_t count)
{
    qsort(data, count, sizeof(char *), stringOrder);
}

char **getData(char **arr, char *line, size_t *len, FILE *f)
{
    size_t s;
    size_t i = 0;
    while (getline(&line, &s, f) >= 0)
    {
        arr = realloc(arr, (i + 1) * sizeof(*arr));
        arr[i] = line;
        line = NULL;
        i++;
    }
    *len = i;
    free(line);
    return arr;
}
void printData(char **arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%s", arr[i]);
        free(arr[i]);
    }
    free(arr);
}

int main(int argc, char **argv)
{
    //size_t sz;
    char **lines = NULL;
    char *line = NULL;
    size_t length = 0;
    if (argc == 1)
    {
        lines = getData(lines, line, &length, stdin);
        sortData(lines, length);
        printf("\nSorted strings from stdin:\n");
        printData(lines, length);
    }
    else if (argc > 1)
    {
        for (size_t i = 1; i <= argc - 1; i++)
        {
            FILE *inf = fopen(argv[i], "r");
            if (inf == NULL)
            {
                fprintf(stderr, "could not open file %s", argv[i]);
                return EXIT_FAILURE;
            }
            lines = getData(lines, line, &length, inf);
            sortData(lines, length);
            printf("\nSorted strings from file %s:\n", argv[i]);
            printData(lines, length);
            if (fclose(inf) != 0)
            {
                fprintf(stderr, "could not close file %s", argv[i]);
            }
        }
    }
    printf("Finished successfully\n");
    return EXIT_SUCCESS;
}