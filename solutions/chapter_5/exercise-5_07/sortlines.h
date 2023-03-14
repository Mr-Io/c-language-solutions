#ifndef SORT_LINES
#define SORT_LINES

int readlines(char** lineptr, int nlines);
void writelines(char** lineptr, int nlines);
void sortlines(char** lineptr, int start, int end);

int readlines2(char** lineptr, int nlines, char* s, int maxs);

#endif
