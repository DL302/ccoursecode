#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);
unsigned tester(unsigned x, unsigned y)
{
    return power(x, y);
}
int main()
{
    int size = 9;
    unsigned x[] = {0, 1, 2, 3, 4, 0, 10, 2, 10};
    unsigned y[] = {0, 3, 2, 0, 2, 9, 5, 10, 2};
    unsigned expected[] = {1, 1, 4, 1, 16, 0, 100000, 1024, 100};
    unsigned testResult;
    for (int i = 0; i < size; i++)
    {
        testResult = tester(x[i], y[i]);
        if (testResult == expected[i])
        {
            printf("test number %d passed.[%u ** %u = %u]\n", i, x[i], y[i], testResult);
            continue;
        }
        else
        {
            printf("test number %d FAILED! [%u ** %u = %u], expected %u\n", i, x[i], y[i], testResult, expected[i]);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}