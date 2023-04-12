#include <stdio.h>

#define swap(t, x, y)	{	t temp = x; \
							x = y;		\
							y = temp;	\
						}
int main()
{
	int x;
	int y;

	while(scanf("%d %d", &x, &y)){
		swap(int, x, y);
		printf("%d %d\n", x, y);

	}

	return 0;
}
