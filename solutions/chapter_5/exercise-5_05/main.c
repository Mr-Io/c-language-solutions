#include <stdio.h>

/* 
* Copies the string pointed to by t, including the terminating 
* null byte ('\0'), to the buffer pointed to by s.  
* The strings may not overlap. 
* At most n bytes of src are copied.  
* Warning: If there is no null byte among the first n bytes of src, 
* the string placed in dest will not be null-terminated.
* It returns a pointer to the destination string s.
*/
char* strncpy(char* s, const char* t, long unsigned n) 
{
	char* save_s = s;
	
	while (n-- > 0 && (*s++ = *t++));

	return save_s;
}

/*
* The  function appends the t string to the s string, 
* overwriting the terminating null byte ('\0') at the end of s, 
* and then adds a terminating null byte.
* The strings may not overlap. 
* The function will use at most n bytes from t and
* t does not need to be null-terminated if it contains n or more bytes.
* The resulting string in dest is always null-terminated.
* The function return a pointer to the resulting string s.
*/
char* strncat(char* s, const char* t, long unsigned n) 
{
	char* save_s = s;

	while (*s++ != '\0');
	s--;

	while(n-- > 0 && (*s++ = *t++));
	*(--s) = '\0';

	return save_s;
}

/*
* The  strcmp() function compares the compares 
* the first (at most) n bytes of s1 and s2.
* It returns an integer indicating the result of the comparison: 
* It returns 0 if they are equal.
* It returns a negative value if s is less t.
* It returns a positive value if s is greater t.
*/
int strncmp(const char* s, const char* t, long unsigned n) 
{
	while(*s++ == *t++ && *s != '\0');

	return *(s) - *(t);
}


int main()
{
	char *s, *t;
	long unsigned ns, nt;
	int ls, lt;

	s = t = NULL;
	ns = nt = 0;
	while ((ls = getline(&s, &ns, stdin)) > 0){
		if ((lt = getline(&t, &nt, stdin)) <= 0){
			return 0;
		}
		s[ls-1] = '\0'; /* remove trailing '\n' from string s */
		t[lt-1] = '\0'; /* remove trailing '\n' from string t */
		printf("Comparison result: %d\n", strncmp(s, t, ls));
		strncat(s, t, ns - ls);
		printf("Concatenation result: %s\n", s);
		strncpy(s, t, ns - ls);
		printf("Copy results: %s\n", s);
	}

	return 0;
}
