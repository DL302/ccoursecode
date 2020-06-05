//program to print a triangle given a height
#include <stdio.h>

void printTriangle(int height)
{
    int count = 0;
    printf("Here is a triangle with height %d", height);
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
        count += i;
    }
    printf("That triangle had %d total stars\n", count);
}
int main()
{
    printTriangle(4);
    printTriangle(7);
    return 0;
}