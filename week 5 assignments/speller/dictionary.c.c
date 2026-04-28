#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

#define N 10007
typedef struct node {
    char word[LENGTH + 1];
    struct node *next;
} node;

node *table[N];
unsigned int word_count = 0;

unsigned int hash(const char *word) {
    unsigned long h = 5381;
    for (int i = 0; word[i]; i++)
        h = ((h << 5) + h) + tolower(word[i]);
    return h % N;
}

bool load(const char *dictionary) {
    FILE *file = fopen(dictionary, "r");
    if (!file) return false;
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF) {
        node *n = malloc(sizeof(node));
        if (!n) return false;
        strcpy(n->word, word);
        int index = hash(word);
        n->next = table[index];
        table[index] = n;
        word_count++;
    }
    fclose(file);
    return true;
}

unsigned int size(void) { return word_count; }

bool check(const char *word) {
    int index = hash(word);
    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
        if (strcasecmp(tmp->word, word) == 0) return true;
    return false;
}

bool unload(void) {
    for (int i = 0; i < N; i++) {
        node *cursor = table[i];
        while (cursor) {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
