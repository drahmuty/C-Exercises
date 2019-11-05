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
    char k2[] = "hello";
    char v2[] = "world";
    char k3[] = "david";
    char v3[] = "ahmud";
    install(key, val);
    install(k2, v2);
    install(k3, v3);
    printf("%s\n", lookup(k2)->defn);
    undef(k2);
    printf("%s\n", lookup(k2)->defn);
    return 0;
}

void undef(char *s)
{
    struct nlist *np, *xp;
    unsigned h;
    
    hashval = hash(s);
    for (xp = np = hashtab[h]; np != NULL; xp = np, np = np->next) {
        if (strcmp(s, np->name) == 0) {
            xp = np->next;
            free((void *) np->name);
            free((void *) np->defn);
            free((void *) np);
            return;
        }
    }
    return;
}

// Book answer version
void undef_ans(char *s)
{
    int h;
    struct nlist *prev, *np;
    
    prev = NULL;
    h = hash(s);
    for (np = hashtab[h]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0)
            break;
        prev = np;
    }
    if (np != NULL) {
        if (prev == NULL)
            hashtab[h] = np->next;
        else
            prev->next = np->next;
        free((void *) np->name);
        free((void *) np->defn);
        free((void *) np);
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
    
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
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
