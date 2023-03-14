#include "lookup.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct keypair** table = NULL;
static int tablesize = 0;
static int entries = 0;
#define TABLELIMIT 1 << 24

static struct keypair* insert(struct keypair* p);
static int hashfunction(char* s);

static void resize() {
    int i;
    // update size (hash function changes)
    tablesize = (tablesize < 1) ? 1 : tablesize * 2;
    // make new table
    struct keypair** lasttable = table;
    table = (struct keypair**)malloc(tablesize * sizeof(void*));
    for (i = 0; i < tablesize; ++i)
        table[i] = NULL;
    // copy entries
    struct keypair* p;
    for (i = 0; i < tablesize/2; ++i) {
        p = lasttable[i];
        while (p)
            p = insert(p);  // insert p
    }
    // free memory
    free(lasttable);
}

static struct keypair* insert(struct keypair* p)
{
    struct keypair* next = p->next;
    int hash = hashfunction(p->key);
    p->next = table[hash];
    table[hash] = p;
    return next;
}

static int hashfunction(char* s) 
{
    int i;
    int hashadress = 0;
    for (i = 0; s[i] != '\0'; ++i)
        hashadress = hashadress * 31 % tablesize + s[i];
    return hashadress % tablesize;
}

static char* strdup(char* s)
{
    char* p;
    p = (char*)malloc((strlen(s)+1)*sizeof(char));
    if (!p)
        return NULL;
    strcpy(p, s);
    return p;
}

struct keypair* lookup(char* s) 
{
    if (!table)
        return NULL;
    struct keypair* p;
    for (p = table[hashfunction(s)]; p != NULL; p = p->next) {
        if (!strcmp(s, p->key))
            return p;
    }
    return NULL;
}


struct keypair* install(char* s, char* t)
{
    struct keypair* p;
    if ((p=lookup(s)) != NULL) {
        free((void*)p->value);
        p->value = strdup(t);
    }
    else {
        ++entries;
        //check capacity
        if (1.5 * entries > tablesize)
            resize();
        // allocate memory
        p = (struct keypair*)malloc(sizeof(struct keypair)); 
        p->key = strdup(s);
        p->value = strdup(t);
        if (!p || !p->key || !p->value)
            return NULL;
        // put it at the beginning of the linked list
        p->next = table[hashfunction(s)];
        table[hashfunction(s)] = p;
    }
    return p;
}

void printtable()
{
    int i;
    struct keypair* p;
    printf("TABLE\n");
    for (i = 0; i < tablesize; ++i) {
        printf("%3d:\n", i);
        p = table[i];
        while (p) {
            printf("%10s: %10s\n", p->key, p->value);
            p = p->next;
        }
    }
}

void undef(char* s)
{
    struct keypair* pp = table[hashfunction(s)];
    struct keypair* p = lookup(s);
    if (p != NULL){
        --entries;
        // update table
        if (pp == p) {
            table[hashfunction(s)] = NULL;
        }
        else {
            while (pp->next != p)
                pp = pp->next;
            pp->next = p->next;
        }
        //free p
        free(p->key);
        free(p->value);
        free(p);
    }
}
