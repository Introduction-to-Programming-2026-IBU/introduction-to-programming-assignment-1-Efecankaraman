#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    int sum = 0;
    int count = 0;
    long temp = number;
    long start_digits = number;

    // Luhn Algoritması Uygulaması
    while (temp > 0)
    {
        int digit = temp % 10;
        if (count % 2 == 1)
        {
            int doubled = digit * 2;
            sum += (doubled / 10) + (doubled % 10);
        }
        else
        {
            sum += digit;
        }
        temp /= 10;
        count++;
    }

    // İlk iki basamağı bulma
    while (start_digits >= 100)
    {
        start_digits /= 10;
    }

    // Geçerlilik ve Tür Kontrolü
    if (sum % 10 == 0)
    {
        if ((count == 15) && (start_digits == 34 || start_digits == 37))
        {
            printf("AMEX\n");
        }
        else if ((count == 16) && (start_digits >= 51 && start_digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((count == 13 || count == 16) && (start_digits / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
