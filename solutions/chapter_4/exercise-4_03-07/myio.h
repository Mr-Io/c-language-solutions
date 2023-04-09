int getch(void);

/* return 0 on success and -1 on error */
int ungetch(int c);

/* push s string into the input, return 0 on success and -1 on error */
int ungets(char s[]);