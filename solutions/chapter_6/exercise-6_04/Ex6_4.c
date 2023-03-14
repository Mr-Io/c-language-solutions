#include "utils.h"
#include "sort.h"
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
int counttree(struct node* p);
void copynodes(struct node** arrayp, struct node* root);
int countcmp(struct node* a, struct node* b);

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
	// count number of nodes, create an array of nodes 
	int nnodes = counttree(root);
	struct node** nodes = (struct node**)malloc(nnodes * sizeof(struct node*));
	// copy tree to array of nodes (only pointers, dont allocate new memory)
	copynodes(nodes, root);
	//sort array
	sortarray((void**)nodes, 0, nnodes - 1, (int (*)(void*, void*))countcmp);
	//tree still exists, can be printed with:
	//printtree(root);
	// print nodes
	printf("WORD IN DECREASING NUMBERS\n");
	int i;
	for (i = 0; i < nnodes; ++i)
		printf("%10s: %3d\n", nodes[i]->word, nodes[i]->count);
	return 0;
}

int countcmp(struct node* a, struct node* b)
{
	return  b->count - a->count;
}

char* strndup_(char* w, int n)
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
		p->word = strndup_(w, n);
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
		printf("%10s: %3d\n", p->word, p->count);
		printtree(p->right);
	}
}

int counttree(struct node* p)
{
	//base case: return
	//recursive calls:
	if (p == NULL)
		return 0;
	else
		return 1 + counttree(p->left) + counttree(p->right);
}

void copynodes(struct node** arrayp, struct node* root)
{
	//base case: copy nothing
	//recursive calls: (order does not matter)
	if (root != NULL) {
		*arrayp = root;
		copynodes(++arrayp, root->left);
		copynodes(arrayp + counttree(root->left), root->right);
	}
}

