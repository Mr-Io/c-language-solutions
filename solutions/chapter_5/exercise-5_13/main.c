#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 10
#define MAXLINES 100

int main(int argc, char **argv)
{
	int i;

	if (argc > 2){
		fprintf(stderr, "Usage: ./tail -n\n");
		return -1;
	}

	int n = DEFAULT;
	if (argc == 2){
		if (**++argv != '-'){
		fprintf(stderr, "Usage: ./tail -n\n");
		return -1;
		}else{
			n = atoi(*argv + 1);
		}
	}
	if (n > MAXLINES){
		n = MAXLINES;
	}else if (n <= 0){
		return 0;
	}

	// allocate and initilize memory for n lines
	char *lines_ptrs[n];
	size_t lines_n[n];
	for (i = 0; i < n; ++i){
		lines_ptrs[i] = NULL;
		lines_n[i] = 0;
	}

	// get lines
	i = 0;
	while (getline(&lines_ptrs[i], &lines_n[i], stdin) > 0){
		if (++i >= n){ // loop around
			i = 0;
		}
	}

	// print lines in order
	int j = i;
	do{
		if (lines_ptrs[j] != NULL){
			printf("%s", lines_ptrs[j]);
			free(lines_ptrs[j]);
		}
		if (++j >= n){ // loop around
			j = 0;
		}
	}while(j != i);
}