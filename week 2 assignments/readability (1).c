#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Fonksiyon prototipleri
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Kullanıcıdan metni al
    string text = get_string("Text: ");

    // Sayımları yap
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // L ve S değerlerini hesapla (100 kelime üzerinden ortalama)
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Coleman-Liau endeksini hesapla ve yuvarla
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Sonucu yazdır
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Harf sayma: Sadece a-z ve A-Z arasındakileri sayar
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Kelime sayma: Boşlukları sayar ve 1 ekler (boşluk + 1 = kelime sayısı)
int count_words(string text)
{
    int count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Cümle sayma: '.', '!' veya '?' işaretlerini sayar
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
