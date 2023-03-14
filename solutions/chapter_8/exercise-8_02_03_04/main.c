#include "mystdio.h"
#include <stdlib.h>



int main(int argc, char * argv[])
{
    FILE *fin, *fout ;
    int c;
    fin = fopen("myio.c", "r");
    fout = fopen("test_copy_myio.c", "a");
    if (fin == NULL || fout == NULL){
        exit(1);
    }


    int n = 0;
    while((c = fgetc(fin)) != EOF){
        if(fputc(c, stdout) == EOF){
            exit(1);
        };
        if(fputc(c, fout) == EOF){
            exit(1);
        };
    }
    
    if(fclose(fin) == -1 || fclose(fout) == -1){
        exit(1);
    };


}
