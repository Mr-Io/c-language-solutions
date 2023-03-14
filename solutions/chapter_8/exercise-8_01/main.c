#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int filecopy (int fin, int fout);

/* cat: concatenate files, unbuffered version */
int main (int argc, char *argv[])
{

    if (argc == 1){
        filecopy(0, 1);
    }
    int i;
    int fin;
    for (i = 1; i < argc; i++){
        if((fin = open(argv[i], O_RDONLY, 0)) == -1){
            fprintf(stderr, "error opening file %s", argv[i]);
            exit(1);
        }
        if(filecopy(fin, 1) == EOF){
            fprintf(stderr, "error writing to stdout");
            exit(1);
        }
        if(close(fin) == -1){
            fprintf(stderr, "error closing file %s", argv[i]);
            exit(1);
        }
    }
    return 0;
}


/* copy stream from one file descriptor to the other */
int filecopy (int fin, int fout)
{
    int c;
    
    while(read(fin, &c, 1) == 1) {
        if (write(fout, &c, 1) != 1){
            return EOF; 
        }
    }
    return 0;

}
