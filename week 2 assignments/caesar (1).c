#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonksiyon prototipleri
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // 1. Argüman kontrolü: Sadece 1 anahtar girilmeli ve bu bir sayı olmalı
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 2. Anahtarı metinden tam sayıya (int) çevir
    int key = atoi(argv[1]);

    // 3. Kullanıcıdan gizli mesajı al
    string plaintext = get_string("plaintext:  ");

    // 4. Şifreli mesajı yazdır
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

// Bir metnin sadece rakamlardan oluşup oluşmadığını kontrol eder
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Harfi anahtar kadar kaydıran fonksiyon
char rotate(char c, int n)
{
    if (isupper(c))
    {
        // Büyük harf formülü: (Harf - 'A' + anahtar) % 26 + 'A'
        return (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        // Küçük harf formülü: (Harf - 'a' + anahtar) % 26 + 'a'
        return (c - 'a' + n) % 26 + 'a';
    }
    // Harf değilse olduğu gibi bırak
    return c;
}
