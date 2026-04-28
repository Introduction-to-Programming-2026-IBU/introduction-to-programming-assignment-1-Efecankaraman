#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents;
    // Kullanıcıdan negatif olmayan bir tam sayı alana kadar bekle
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Kaç tane 25 sentlik (quarters) verilecek?
    int quarters = cents / 25;
    cents = cents % 25;

    // Kaç tane 10 sentlik (dimes) verilecek?
    int dimes = cents / 10;
    cents = cents % 10;

    // Kaç tane 5 sentlik (nickels) verilecek?
    int nickels = cents / 5;
    cents = cents % 5;

    // Kalan her şey 1 sentliktir (pennies)
    int pennies = cents;

    // Toplam bozuk para sayısını ekrana yazdır
    printf("%i\n", quarters + dimes + nickels + pennies);
}
