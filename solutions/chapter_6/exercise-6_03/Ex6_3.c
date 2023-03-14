#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define SIGNDIGITS 6

struct linked {
	int line;
	struct linked* next;
};

struct node {
	char* word;
	int count;
	struct linked* lines;
	struct node* left;
	struct node* right;
};

void printtree(struct node* p);
struct node* addword(struct node* p, char* w, int line);

int main()
{
	// program logic
	int line;
	char word[MAXWORD];
	struct node* root = NULL;
	while ((line = getword(word, MAXWORD)) != EOF) {
		if (line) 
			root = addword(root, word, line);
	}
	printtree(root);
	return 0;
}

char* strdup(char* w)
{
	char* s = (char*)malloc((strlen(w)+1)*sizeof(char));
	strcpy(s, w);
	return s;
}

struct linked* makelink(struct linked* link, int line) // use an iterative version to avoid stack overflow errors
{
	//base case
	if (link == NULL) {
		struct linked* p = (struct linked*)malloc(sizeof(struct linked));
		p->line = line;
		p->next = NULL;
		return p;
	}
	//recursion calls 
	link->next = makelink(link->next, line);
	return link;
}

struct linked* itermakelink(struct linked* link, int line)
{
	// allocate memory, independent of where it will goes on the linked list
	struct linked* linkend;
	linkend = (struct linked*)malloc(sizeof(struct linked));
	linkend->line = line;
	linkend->next = NULL;

	if (link == NULL) {				// new linked list
		return linkend;
	}
	else {							// search end of existing linked list 
		struct linked* tmp = link;
		while (link->next != NULL)  // we  need to operate on "attributes" in order 
			link = link->next;		// to make the change external to the function 
		link->next = linkend;		// instead of just changing local variables.
		return tmp;					// link = linkend; would not work
	}
}

struct node* addword(struct node* p, char* w, int line)
{
	int cond;
	// base cases
	if (p == NULL) {	// no word -> create a new node
		p = (struct node*)malloc(sizeof(struct node));

		p->count = 1;
		p->left = p->right = NULL;
		p->word = strdup(w);
		p->lines = NULL;
		p->lines = itermakelink(p->lines, line);	// makelink(p->lines, line)
	}
	else if ((cond = strcmp(w, p->word)) == 0) {
		++p->count;
		p->lines = itermakelink(p->lines, line);	// makelink(p->lines, line)
	}
	// recursive calls
	else if (cond < 0) {
		p->left = addword(p->left, w, line);
	}
	else {
		p->right = addword(p->right, w, line);
	}
	return p;

}

void printlink(struct linked* p)
{
	//base case: return
	//recursive calls:
	if (p != NULL) {
		printf("%d-", p->line);
		printlink(p->next);
	}
}

void iterprintlink(struct linked* p)
{
	//base case: return
	//recursive calls:
	while(p != NULL) {
		printf("%d-", p->line);
		p = p->next;
	}
}

void printtree(struct node* p)
{
	//base case: return
	//recursive calls:
	if (p != NULL) {
		printtree(p->left);
		printf("%15s: %4d:", p->word, p->count);
		iterprintlink(p->lines); // printlink(p->lines)
		putchar('\n');
		printtree(p->right);
	}
}



