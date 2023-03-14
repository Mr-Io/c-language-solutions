#include <stdio.h>
#include <time.h>

int binsearch(int x, const int v[], int n);
int binsearch1test(int x, const int v[], int n);

int main() 
{
	int i, j;
	int v[10] = {0, 2, 4, 6 , 8, 10, 12, 14, 16, 18};
	int res=0;
	clock_t start, end;
	
	res = 0;
	start = clock();
	for (i=1;i<10000;++i){
		for (j = 0; j < 10000; ++j) {
			res += binsearch(9, v, 10);
		}
	}
	end = clock();
	printf("%d\n", end-start);

	start = clock();
	for (i=1;i<10000;++i){
		for (j = 0; j < 10000; ++j) {
			res -= binsearch1test(9, v, 10);
		}
	}
	end = clock();
	printf("%d\n", end-start);

	if (res)
		printf("the functions reported different values!!");

	return 0;
}

int binsearch(int x, const int v[], int n) 
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) 
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else 
			return mid;
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
		if (x < v[mid]) 
			high = mid - 1;
		else 
			low = mid;
	}
	if (v[low] == x)
		return low;
	else if (v[mid] == x)
		return mid;
	else if (v[high] == x)
		return high;
	else
		return -1;
}