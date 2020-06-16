#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n);

size_t grader(int *array, size_t n, size_t correctSequence)
{
    int funcAns = maxSeq(array, n);
    if (correctSequence != funcAns)
    {
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }
}
int main()
{
    int test[7] = {1, 2, 2, 3, 4, 5, 0};
    int testResult = grader(test, 7, 4);
    if (testResult == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    int test2[6] = {10, 9, 8, 7, 6, 7};
    int test2Result = grader(test2, 6, 2);
    if (test2Result == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    int test3[0];
    int test3Result = grader(test3, 0, 0);
    if (test3Result == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    int test4[7] = {1, 1, 1, 1, 1, 1, 1};
    int test4Result = grader(test4, 7, 0);
    if (test4Result == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    int test5[5] = {10, 9, 8, 7, 7};
    int test5Result = grader(test5, 5, 0);
    if (test5Result == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    int test6[3] = {1, 2, 3};
    int test6Result = grader(test6, 3, 3);
    if (test6Result == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    int test7[3] = {3, 2, 1};
    int test7Result = grader(test7, 3, 0);
    if (test7Result == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    int test8[3] = {3, -2, 1};
    int test8Result = grader(test8, 3, 2);
    if (test8Result == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}