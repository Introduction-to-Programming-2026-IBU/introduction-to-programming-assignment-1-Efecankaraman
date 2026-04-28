#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // 1. Argüman kontrolü
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // 2. Anahtar geçerlilik kontrolü
    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // 3. Şifreleme döngüsü
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 'A';
            printf("%c", toupper(key[index]));
        }
        else if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a';
            printf("%c", tolower(key[index]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

bool is_valid_key(string key)
{
    int len = strlen(key);
    if (len != 26) return false;

    bool seen[26] = {false};
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i])) return false;

        int index = tolower(key[i]) - 'a';
        if (seen[index]) return false; // Tekrar eden harf kontrolü
        seen[index] = true;
    }
    return true;
}
