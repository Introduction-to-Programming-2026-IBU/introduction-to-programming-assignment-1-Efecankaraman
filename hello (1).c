#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Kullanıcıdan isim alıyoruz
    string name = get_string("What is your name? ");

    // İsmi ekrana yazdırıyoruz
    printf("hello, %s\n", name);
}
