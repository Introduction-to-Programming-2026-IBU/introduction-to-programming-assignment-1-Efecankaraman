#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // 1 ile 8 arasında geçerli bir sayı alana kadar döngü devam eder
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Satırlar için döngü
    for (int i = 0; i < n; i++)
    {
        // Boşluklar için döngü (Sola dayalı yapmak için)
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // Kareler (#) için döngü
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // Bir sonraki satıra geç
        printf("\n");
    }
}
