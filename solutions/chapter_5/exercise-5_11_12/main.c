#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 128
#define TABLEN 8

int settab(int argc, const char *const *argv, char *tabs, int n);
int extendtab(int start, int tabsize, char *tabs, int n);
int istabstop(int pos, const char *tabs, int n);

int entab(int argc, const char *const *argv, const char *tabs, int n);
int detab(int argc, const char *const *argv, const char *tabs, int n);

int main(int argc, const char *const *argv)
{
    // set tabs
    char tabs[MAXLINE];
    if (settab(argc, argv, tabs, MAXLINE) != 0){
        fprintf(stderr, "error settab: wrong command-line arguments\n");
        return -1;
    };

    // run program depending on the executable file name
    if (strstr(*argv, "entab")){
        return entab(argc, argv, tabs, MAXLINE);
    }
    if (strstr(*argv, "detab")){
        return detab(argc, argv, tabs, MAXLINE);
    }

    fprintf(stderr, "unrecognized program name: %s\n", *argv);
    return -1;
}

int entab(int argc, const char *const *argv, const char *tabs, int n)
{
    int c;

	int nb = 0;
	int pos = 0;
	while ((c = getchar()) != EOF){
        // reset blank spaces if current position is a tabstop
        if (istabstop(pos, tabs, n) && nb > 0){
            nb = 0;
            putchar('\t');
        }
        // handle character and update position
        if (c == ' '){
            ++nb;
            ++pos;
        }else if (c == '\t'){
            putchar('\t');
            nb = 0;
            do{
                ++pos;
            }while(!istabstop(pos, tabs, n));
        }else{
            while(nb > 0){
                putchar(' ');
                --nb;
            }
            putchar(c);
            ++pos;
        }
        // reset position if newline
        if (c == '\n'){
            pos = 0;
        }
    }

	return 0;
}

int detab(int argc, const char *const *argv, const char *tabs, int n)
{
    int c;
    int pos = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            do{
                putchar(' ');
                ++pos;
            }while (!istabstop(pos, tabs, MAXLINE));
        }else{
            putchar(c);
            ++pos;
        }
        if (c == '\n') {
            pos = 0;
        }
    }
    return 0;
}

/* 
* return 1 if 'pos' is a tabstop and 0 if not.
*/
int istabstop(int pos, const char *tabs, int n)
{
    if (pos < 0 || pos >= n){
        return 1;
    }
    return tabs[pos];
}

/* 
* settab() uses a list of command-line arguments 'argc' and 'argv' 
* wich integer strings that indicate stops to fill
* the buffer 'tabs' with has length of at least 'size'.  
* 'tabs' is filled with 0s in every position but the ones indicates
* in 'argv', which are filled with 1s. 
* return 0 on success and -1 on error 
*/
int settab(int argc, const char *const *argv, char *tabs, int size)
{
    // prepopulate tabs with 0s
    int i;
    for (i = 0; i < size; ++i){
        tabs[i] = 0;
    }

    // get -m +n command-line arguments 
    int m, n; 
    m = 0; n = TABLEN; // default behaviour
    for (i = 0; i < 2 && --argc > 0; ++i){
        ++argv;
        if(**argv == '-'){
            m = atoi(*argv + 1);
        }else if (**argv == '+'){
            n = atoi(*argv + 1);
        }else{
            --argv;
            ++argc;
            break;
        }
    }

    // use -m +n command-line argument to update stops in tabs
    if (extendtab(m, n, tabs, size) == -1){
        return -1;
    }

    // use rest of command-line argument to update stops in tabs
    int pos;
    int maxpos = 0;
    while (--argc > 0){
        pos = atoi(*++argv);
        if (pos <= 0){
            return -1;
        }
        if (pos < size){
            tabs[pos] = 1;
        }
        if (pos > maxpos){
            maxpos = pos;
        }
    }

    return 0;
}

/* 
* extendtab() add tab stops to 'tabs' 
* every 'tabsize' columns, starting at column 'start'.
* return 0 on success and -1 on error 
*/
int extendtab(int start, int tabsize, char *tabs, int n)
{
    int i;

    if (tabsize <= 0){
        return -1;
    }

    i = start;
    while( i < n){
        tabs[i] = 1;
        i += tabsize;
    }

    return 0;
}