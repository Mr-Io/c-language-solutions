#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define SIGNDIGITS 6

struct node {
	char* word;
	int count;
	struct node* left;
	struct node* right;
};

void printtree(struct node* p);
struct node* addword(struct node* p, char* w, int n);

int main(int argc, char* argv[])
{
	//retrieve number of significant digits
	int n;
	if (argc != 2 || (n = atoi(argv[1])) < 1 || n >= MAXWORD)
		n = SIGNDIGITS;
	// program logic
	int isword;
	char word[MAXWORD];
	struct node* root = NULL;
	while ((isword = getword(word, MAXWORD)) != EOF) {
		if (isword) 
			root = addword(root, word, n);
	}
	printtree(root);
	return 0;
}

char* strdup(char* w, int n)
{
	char* s = (char*)malloc(n + 1);
	strncpy(s, w, n);
	s[n] = '\0';
	return s;
}

struct node* addword(struct node* p, char* w, int n)
{
	int cond;
	// base cases
	if (p == NULL) {	// no word -> create a new node
		p = (struct node*)malloc(sizeof(struct node));
		p->count = 1;
		p->left = p->right = NULL;
		p->word = strdup(w, n);
	}
	else if ((cond = strncmp(w, p->word, n)) == 0) {
		++p->count;
	}
	// recursive calls
	else if (cond < 0) {
		p->left = addword(p->left, w, n);
	}
	else {
		p->right = addword(p->right, w, n);
	}
	return p;

}

void printtree(struct node* p)
{
	//base case: return
	//recursive calls:
	if (p != NULL) {
		printtree(p->left);
		printf("%6s: %3d\n", p->word, p->count);
		printtree(p->right);
	}
}


