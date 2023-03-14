#include <stdio.h>
#include "mystdlib.h"

#include <string.h>

int main(int argc, char *argv[])
{
    char *darray;
    darray = (char *)calloc(45,sizeof(char));
    strcpy(darray, "Hello there\n");
    printf("%s", darray);
    free(darray);

}
