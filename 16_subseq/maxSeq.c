#include <stdlib.h>
size_t maxSeq(int *array, size_t n)
{
    size_t longestSeq = 0;
    size_t currentSeq = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (array[i] > array[i - 1])
        {
            if (currentSeq == 0)
            {
                currentSeq++;
            }
            currentSeq++;
            if (currentSeq > longestSeq)
            {
                longestSeq = currentSeq;
            }
        }
        else
        {
            currentSeq = 0;
        }
    }
    return longestSeq;
}