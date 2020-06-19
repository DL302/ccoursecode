//atoi function, but not from the c standard library and converting to hex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int diyatoihex(const char *str)
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
    if (*s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
    {
        s += 2;
    }
    while (*s != '\0')
    {
        if ((*s >= '0' && *s <= '9') || (*s >= 'A' && *s <= 'F') || (*s >= 'a' && *s <= 'f'))
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
        if (*s >= '0' && *s <= '9')
        {
            result += (*s - '0') * pow(16, length);
        }
        else if (*s >= 'A' && *s <= 'F')
        {
            result += (*s - 'A' + 10) * pow(16, length);
        }
        else if (*s >= 'a' && *s <= 'f')
        {
            result += (*s - 'a' + 10) * pow(16, length);
        }

        s++;
        length--;
    }
    return result * sign;
}

void tester(char *str)
{
    char *s = str;
    int answer = diyatoihex(s);
    printf("input was \"%s\", output is %d [0x%x in hex]\n", s, answer, answer);
}
int main()
{
    tester("0xFFFF");
    tester("FFFF");
    tester("0XFFFG");
    tester("12345");
    tester("0x12345");
    tester("0123");
    tester("0X0123");
    tester("");
    tester("1x");
    tester("xx");
    tester(":");
    tester("\\");
    tester("999.0");
    tester("-123");
    tester("0x999.0");
    return EXIT_SUCCESS;
}