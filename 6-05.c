#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
char *strdup1(char *);
struct nlist *install(char *, char *);
void undef(char *);

int main(void)
{    
    char key[] = "key1";
    char val[] = "value1";
    install(key, val);
    printf("%s\n", lookup(key)->defn);
    undef(key);
    printf("%s\n", lookup(key)->defn);
    return 0;
}

void undef(char *name)
{
    struct nlist *np;
    
    if ((np = lookup(name)) != NULL) {
        free((void *) np->name);
        free((void *) np->defn);
    }
}

unsigned hash(char *s)
{
    unsigned hashval;
    
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np-> next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

char *strdup1(char *s)
{
    char *p;
    
    p = (char *) malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}
