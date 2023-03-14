#include "tab.h"

int main(int argc, char* argv[])
{
	if (settab(argc, argv))
		entab();
	else
		printf("Error in setting the tab.\n");
	return 0;
}
