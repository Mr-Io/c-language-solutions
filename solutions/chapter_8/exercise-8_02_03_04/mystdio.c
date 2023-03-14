#include "mystdio.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


FILE _stdin = {"", NULL, 0, 0, {1, 0, 0, 0}};
FILE _stdout = {"", NULL, 0, 1, {0, 1, 0, 0}};
FILE _stderr = {"", NULL, 0, 2, {0, 1, 0, 0}};

/* stadin,stdout,stderr file descriptors must be closed just before exiting */
void __attribute__ ((destructor))  dtor() 
{ 
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
}

int feof(FILE *stream){ return stream->flags.eof; }
int ferror(FILE *stream){ return stream->flags.err; }
int fileno(FILE *stream) { return stream->fd; }

FILE *fopen(char *name, char *mode)
{
    int fd;
    switch (*mode){
        case 'r':
            fd = open(name, O_RDONLY, 0); 
        break;
        case 'w':
            fd = creat(name, 0755); 
        break;
        case 'a':
            if((fd = open(name, O_WRONLY, 0)) == -1){
                fd = creat(name, 0755); 
            } 
            lseek(fd, 0, SEEK_END);
        break;
        default:
            return NULL;
    };

    if (fd == -1){
        return NULL;
    }

    FILE *stream; 
    if ((stream = (FILE *) calloc(1, sizeof(FILE))) == NULL){
        return NULL;
    }
    stream->fd = fd;
    switch (*mode){
        case 'r': 
            stream->flags.read = 1;   
            break;
        case 'w': case 'a': 
            stream->flags.write = 1;  
            break;
    }
    
    return stream;
}


int _fillbuff(FILE *stream)
{
    /* checkings */
    if (stream->cnt > 0 || !stream->flags.read || 
        stream->flags.write || stream->flags.err || 
        stream->flags.eof){
        return EOF;
    }

    /* fill stream buff */
    stream->buffp = stream->buff;  
    stream->cnt = read(stream->fd, stream->buff, BLOCKSIZE);
    if (stream->cnt == -1){
        stream->cnt = 0;
        stream->flags.err = 1;
        return EOF;
    }else if (stream->cnt == 0){
        stream->flags.eof = 1;
        return EOF;
    }

    return 0;
}


int _flushbuff(FILE *stream)
{
    int n;

    /* checkings */
    if (!stream->flags.write || stream->flags.read ||
        stream->flags.err){
        return EOF;
    }

    /* write buff data to file */
    if (stream->buffp == NULL){
        stream->buffp = stream->buff;
    }
    n = stream->buffp + stream->cnt - stream->buff; /* n can be 0 for regular files */
    if (write(stream->fd, stream->buff, n) != n) {
        stream->flags.err = 1;
        return EOF;
    }
    /* reset buffer */
    stream->buffp = stream->buff;
    stream->buff[0] = '\0';
    return n;
}


int fclose(FILE *stream)
{
    /* flush the buffer if write mode */
    if(stream->flags.write && _flushbuff(stream) == -1){
        return EOF;
    }
    if(close(stream->fd) == -1){
        return EOF;
    }
    if (stream->fd > 2){
        free(stream);
    }
    return 0;
}

int fgetc(FILE *stream)
{
    if (stream->cnt == 0 && _fillbuff(stream) == -1){
        return EOF;
    }
    --stream->cnt;
    return *stream->buffp++;
}

int fputc(int c, FILE *stream)
{
    if (stream->buffp == NULL || 
        stream->buffp == stream->buff + BLOCKSIZE){
        if(_flushbuff(stream) == EOF){
            return EOF;
        };
    }
    *stream->buffp++ = c;
    return c;
}

int fflush(FILE *stream)
{
    /* checkings */
    if (stream->flags.err){
        return EOF;
    }

    /* files on writing mode */
    if (stream->flags.write){
        if (_flushbuff(stream) == -1){
            return EOF;
        }
    }

    /* files on reading mode */
    if (stream->flags.read && stream->cnt > 0){
        /* reset file position */
        if((lseek(stream->fd, -stream->cnt, SEEK_CUR)) == -1){
            stream->flags.err = 1;
            return EOF;
        };
        /* discard buffered data*/
        stream->buffp = stream->buff;
        stream->buff[0] = '\0';
        stream->cnt = 0;
    }

    return 0; 
}


int fseek(FILE *stream, long offset, int origin)
{
    /* synchronize position of files */
    if (fflush(stream) == -1){
        return EOF;
    }

    /* move position */
    if (lseek(stream->fd, offset, origin) == -1){
        return -1;
    }

    return 0;
}


