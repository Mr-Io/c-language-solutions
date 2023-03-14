#include <stdio.h>

int main()
{
	int res_expr;
	while ((res_expr = (getchar() != EOF)) != 0)
		printf("%d\n", res_expr);
	printf("%d\n", res_expr);
}