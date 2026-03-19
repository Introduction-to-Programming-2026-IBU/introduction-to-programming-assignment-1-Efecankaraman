#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Kişi yapısı
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele(void);

int main(void)
{
    srand(time(0));

    // Aile ağacını oluştur
    person *p = create_family(GENERATIONS);

    // Ağacı yazdır
    print_family(p, 0);

    // Hafızayı temizle
    free_family(p);
}

// TODO 1: Aile ağacını oluştur
person *create_family(int generations)
{
    // 1. Hafıza ayır
    person *new_person = malloc(sizeof(person));
    if (new_person == NULL)
    {
        return NULL;
    }

    // 2. Eğer daha jenerasyon varsa
    if (generations > 1)
    {
        // Ebeveynleri oluştur
        new_person->parents[0] = create_family(generations - 1);
        new_person->parents[1] = create_family(generations - 1);

        // Miras al (Ebeveynlerin NULL olup olmadığını kontrol etmeye gerek yok
        // çünkü yukarıda malloc kontrolü yapıyoruz, ama güvenlik iyidir)
        new_person->alleles[0] = new_person->parents[0]->alleles[rand() % 2];
        new_person->alleles[1] = new_person->parents[1]->alleles[rand() % 2];
    }
    // 3. En üst nesil (Grandparents)
    else
    {
        // Ebeveynleri mutlaka NULL yap! (Runtime hatasının ana sebebi budur)
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    return new_person;
}

// TODO 2: Hafızayı serbest bırak
void free_family(person *p)
{
    // Base case
    if (p == NULL)
    {
        return;
    }

    // Önce ebeveynleri sil (Recursive)
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Kişiyi sil
    free(p);
}

char random_allele(void)
{
    int r = rand() % 3;
    if (r == 0) return 'A';
    else if (r == 1) return 'B';
    else return 'O';
}

void print_family(person *p, int generation)
{
    if (p == NULL) return;
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
    for (int i = 0; i < generation * INDENT_LENGTH; i++) printf(" ");
    if (generation == 0) printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    else if (generation == 1) printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    else printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
}
