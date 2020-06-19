//atoi function, but not from the c standard library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int diyatoi(const char *str)
{
    int result = 0;
    int length = 0;
    int sign = 1;
    const char *s = str;
    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    while (*s != '\0')
    {
        if ((int)*s >= 48 && (int)*s <= 57)
        {
            s++;
            length++;
        }
        else if (*s == '.')
        {
            break;
        }
        else
        {
            return 0;
        }
    }
    s -= length;

    length--;
    while (length > -1)
    {
        result += ((int)*s - '0') * pow(10, length);
        s++;
        length--;
    }
    return result * sign;
}

void tester(char *str)
{
    char *s = str;
    int answer = diyatoi(s);
    printf("input was \"%s\", output is %d\n", s, answer);
}
int main()
{
    tester("12345");
    tester("0123");
    tester("1230");
    tester("");
    tester("1x");
    tester("xx");
    tester(":");
    tester("\\");
    tester("123.0");
    tester("999.0");
    tester("-123");
    return EXIT_SUCCESS;
}