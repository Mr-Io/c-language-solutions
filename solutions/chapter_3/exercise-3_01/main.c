#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYLEN 1000000
#define SAMPLESIZE 10000

int binsearch(int x, const int v[], int n);
int binsearch1test(int x, const int v[], int n);

int main() 
{
	clock_t tic, toc;
	int i;
	int v[ARRAYLEN]; /* array to search */
	for (i=0 ; i<ARRAYLEN; ++i){
		v[i] = i;
	}
	int t[SAMPLESIZE]; /* random numbers to look for */
	for (i=0 ; i<SAMPLESIZE; ++i){
		v[i] = rand() % (ARRAYLEN + 1);
	}
	
	tic = clock();
	for (i = 0 ; i < SAMPLESIZE ; ++i){
		binsearch(t[i], v, ARRAYLEN);
	}
	toc = clock();
	printf("binsearch:      %6ld clock ticks \n", toc - tic);
	tic = clock();
	for (i = 0 ; i < SAMPLESIZE ; ++i){
		binsearch1test(t[i], v, ARRAYLEN);
	}
	toc = clock();
	printf("binsearch1test: %6ld clock ticks \n", toc - tic);
	return 0;
}

int binsearch(int x, const int v[], int n) 
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]){ 
			high = mid - 1;
		}else if (x > v[mid]){
			low = mid + 1;
		}else{
			return mid;
		}
	}
	return -1;
}

int binsearch1test(int x, const int v[], int n) 
{
	int low, high, mid=0;

	low = 0;
	high = n - 1;
	while (high - low > 1) {
		mid = (low + high) / 2;
		if (x < v[mid]){ 
			high = mid - 1;
		}else{
			low = mid;
		}
	}
	if (v[low] == x){
		return low;
	}else if (v[mid] == x){
		return mid;
	}else if (v[high] == x){
		return high;
	}
	return -1;
}
