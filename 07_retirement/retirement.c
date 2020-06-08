//retirement savings calculator
#include <stdio.h>
#include <stdlib.h>

typedef struct _retire_info
{
    int months;            //number of months this is applicable for
    double contribution;   //dollars contributed [negative if spent]
    double rate_of_return; //rate of return
} retire_info;
int currentAge(int age)
{
    return age + 1;
}
double balanceCalculator(int age, double balance, retire_info profile)
{
    printf("Age %3d month %2d you have $%.2lf\n", age / 12, age % 12, balance);
    balance += balance * profile.rate_of_return + profile.contribution;
    return balance;
}
//startAge is in MONTHS, initial in DOLLARS
void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
    double balance = initial;
    int age = startAge;
    for (int i = 0; i < working.months; i++)
    {
        balance = balanceCalculator(age, balance, working);
        age = currentAge(age);
    }
    for (int j = 0; j < retired.months; j++)
    {
        balance = balanceCalculator(age, balance, retired);
        age = currentAge(age);
    }
}
int main()
{
    retire_info working;
    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = 0.045 / 12;
    retire_info retired;
    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = 0.01 / 12;
    retirement(327, 21345, working, retired);
    return EXIT_SUCCESS;
}