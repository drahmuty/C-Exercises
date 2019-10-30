#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdup1(char *);
int getch(void);
void ungetch(int);
struct tnode *treesort(struct tnode *, struct tnode *);
struct tnode *treesorter(struct tnode *, struct tnode *);

char buf[BUFSIZE];
int bufp = 0;

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int main(void)
{
    struct tnode *root;
    struct tnode *sroot;
    char word[MAXWORD];
    
    root = sroot = NULL;
    while (getword(word, MAXWORD) != '0')
        if (isalpha(word[0]))
            root = addtree(root, word);
    sroot = treesort(sroot, root);
    treeprint(sroot);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    
    if (p == NULL) {
        p = talloc();
        p->word = strdup1(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

struct tnode *treesort(struct tnode *s, struct tnode *t)
{
    if (t != NULL) {
        s = treesorter(s, t);
        treesort(s, t->left);
        treesort(s, t->right);
    }
    return s;
}

struct tnode *treesorter(struct tnode *s, struct tnode *t)
{
    if (s == NULL) {
        s = talloc();
        s->word = t->word;
        s->count = t->count;
        s->left = s->right = NULL;
    } else if (t->count >= s->count)
        s->left = treesorter(s->left, t);
    else
        s->right = treesorter(s->right, t);
    return s;
}

void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup1(char *s)
{
    char *p;
    
    p = (char *) malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void unetch(int);
    char *w = word;
    
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
