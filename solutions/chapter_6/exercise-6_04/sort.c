#include "sort.h"
#include "utils.h"
#include <stdio.h>

static void swap(void** x, void** y);

void sortarray(void** arrayp, int start, int end, int (*comp)(void*, void*))
{
	// simple sort O(n^2)
	int i, j;
	for (i = start; i <= end; ++i) {
		for (j = start; j < end-i; ++j) {
			if ((*comp)(arrayp[j], arrayp[j + 1]) > 0)
				swap(&arrayp[j], &arrayp[j + 1]);
		}
	}
	return;
}

//auxiliar internal function
static void swap(void** x, void** y)
{
	void* tmp = *x;
	*x = *y;
	*y = tmp;
}
