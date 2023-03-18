#include <stdio.h>

int main()
{
	int res_expr;

	while (res_expr = getchar() != EOF){
		printf("%d", res_expr);
	}
}