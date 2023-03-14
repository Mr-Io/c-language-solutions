#define EOF (-1)
#define NULL 0

#define BLOCKSIZE 1024


int printf(char*f, ...);

struct Flags{
    int read   :1; /* file open for reading */
    int write  :1; /* file open for writing */
    int eof    :1; /* EOF has occurred on this file */
    int err    :1; /* error has occurred on this file */
};

typedef struct {
    char buff[BLOCKSIZE];   /* buffer */
    char *buffp;            /* current position of buffer */
    int cnt;                /* number of characters left for read */
    int fd;                 /* file descriptor */
    struct Flags flags;     /* open mode, EOF and error info */
} FILE;

extern FILE _stdin; 
extern FILE _stdout; 
extern FILE _stderr;
void _closeio(void);

#define stdin (&_stdin)
#define stdout (&_stdout)
#define stderr (&_stderr)

int feof(FILE *stream);
int ferror(FILE *stream);
int fileno(FILE *stream);

FILE *fopen(char *name, char *mode);

int _fillbuff(FILE *stream);
int _flushbuff(FILE *stream);

int fclose(FILE *stream);

int fgetc(FILE *stream);
int fputc(int c, FILE *stream);

int fflush(FILE *stream);
int fseek(FILE *fp, long offset, int origin);

