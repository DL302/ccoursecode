//strtol function, but not from the c standard library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long diystrtol(const char *str, char **endptr, int base)
{
    long result = 0;
    int sign = 1;
    const char *s = str;
    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    if (*s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X') && base == 16)
    {
        s += 2;
    }
    while (*s != '\0')
    {
        if (*s >= '0' && *s <= '9')
        {
            if (*s - 48 > base - 1)
            {
                if (endptr != NULL)
                {
                    *endptr = (char *)s;
                }
                break;
            }
            else
            {
                result = base * result + (*s - 48);
            }
        }
        else if (*s >= 'A' && *s <= 'Z')
        {
            if (*s - 55 > base - 1)
            {
                if (endptr != NULL)
                {
                    *endptr = (char *)s;
                }
                break;
            }
            else
            {
                result = base * result + (*s - 55);
            }
        }
        else if (*s >= 'a' && *s <= 'z')
        {
            if (*s - 87 > base - 1)
            {
                if (endptr != NULL)
                {
                    *endptr = (char *)s;
                }
                break;
            }
            else
            {
                result = base * result + (*s - 87);
            }
        }
        else
        {
            if (endptr != NULL)
            {
                *endptr = (char *)s;
            }
            break;
        }
        s++;
    }
    return result * sign;
}
int main()
{
    char str0[] = "1234567890abc";
    char *end0;
    long test0 = diystrtol(str0, &end0, 10);
    printf("the long is: %ld, with the pointer pointing at: \"%s\"\n", test0, end0);
    return EXIT_SUCCESS;
}