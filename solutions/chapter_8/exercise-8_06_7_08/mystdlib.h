#define NALLOC 1024
#define MAXALLOC 1048576

void *malloc(long unsigned int nbytes);
void free(void *p);

void *calloc(long unsigned int n, long unsigned int size);

void bfree(void *p, long int);

