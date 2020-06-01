#include <cs50.h>
#include <stdio.h>

int checksum(long num)
{
    long count = 1, result, sum1 = 0, sum2 = 0, total = 0;
    long number = num * 10, digit;
    while (number != 0)
    {
        count = number / 100;
        number /= 100;
        digit = count % 10;
        printf("%lu", digit);
        sum1 += (digit * 2) / 10 + (digit * 2) % 10;
    }
    printf("Sum1: %lu", sum1);
    number = num;
    sum2 = number % 10;
    count = 1;
    while (number != 0)
    {
        count = number / 100;
        number /= 100;
        digit = count % 10;
        sum2 += digit;
    }
    printf("Sum2: %lu", sum2);
    total = sum1 + sum2;
    return total;
}

int main()
{
    long number;
    long final;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);
    final = checksum(number);
    
    if (number / 10000000000000 == 34 || number / 10000000000000 == 37)
    {

    }
    else if (number / 100000000000000 == 51 || number / 100000000000000 == 52 || number / 100000000000000 == 53 || number / 100000000000000 == 54 || number / 100000000000000 == 55)
    {
        //MasterCard
    }
    else if (number / 100000000000 == 4 || number / 100000000000000 == 4)
    {
        //Visa
    }
    else
    {
        printf("INVALID");
    }
}
