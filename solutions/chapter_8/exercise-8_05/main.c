#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <linux/limits.h>


int fsize(char *name);
int _fsize_dir(char* name);

char *_sftype(int st_mode);

/* fsize: recursive directory listing */
int main (int argc, char *argv[])
{

    printf("%-50.50s %-12s %-18s\n", "filepath", "size[bytes]", "type");
    printf("%-50.50s %-12s %-18s\n", "--------", "-----------", "----");

    if (argc == 1){
        fsize(".");
    }

    int i;
    for (i = 1; i < argc; ++i){
        fsize(argv[i]);
    }
}


int fsize(char *name)
{
    struct stat statbuf;
    if(stat(name, &statbuf) == -1){
        fprintf(stderr, "error getting metadata from file %s\n", name);
        return EOF;
    };

    /* if the file is a regular file */
    printf("%-50.50s %-12ld %-18s\n", name, statbuf.st_size, _sftype(statbuf.st_mode));
    
    /* if the file is a directory call fsize on each file of the directory */
    if (S_ISDIR(statbuf.st_mode)) {
        _fsize_dir(name);
    }

    /* ignore other types of files */
    return 0;
}

int _fsize_dir(char* name)
{
    DIR *dp;
    struct dirent *dentp;
    char buffer[PATH_MAX];

    if((dp = opendir(name)) == NULL){
        fprintf(stderr, "error opening directory %s\n", name);
        return EOF;
    }

    while(dentp = readdir(dp)){
        if (strcmp(dentp->d_name, ".")  == 0 ||
            strcmp(dentp->d_name, "..") == 0){
                continue;
            }
        sprintf(buffer, "%s/%s", name, dentp->d_name);
        fsize(buffer);
    }

    if(closedir(dp) == -1){
        fprintf(stderr, "error closing directory %s\n", name);
        return EOF;
    }

}

char *_sftype(int st_mode)
{
    if (S_ISREG(st_mode)){
        return "regular file";
    }
    if (S_ISDIR(st_mode)){
        return "directory";
    }
    if (S_ISCHR(st_mode)){
        return "character device";
    }
    if (S_ISBLK(st_mode)){
        return "block device";
    }
    if (S_ISFIFO(st_mode)){
        return "(FIFO) named pipe";
    }
    if (S_ISLNK(st_mode)){
        return "symbolic link";
    }
    if (S_ISSOCK(st_mode)){
        return "socket";
    }
    return NULL; 
}