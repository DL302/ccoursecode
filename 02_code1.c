//max function that takes in 2 ints and outputs the bigger of the two
#include <stdio.h>

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int main()
{
    int num1 = 0x451215AF;
    int num2 = 0x913591AF;
    int result = max(num1, num2);
    printf("The max of %d and %d is %d\n", num1, num2, result);
    return 0;
}