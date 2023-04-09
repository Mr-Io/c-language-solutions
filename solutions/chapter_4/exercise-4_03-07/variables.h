/* always call before using the module*/
void initvar(void);

/* get the value of variable var or NAN if it has not been used yet */
double getvar(char var);

/* set the value of variable var to x */
void setvar(char var, double x);

/* return 1 if the variable var has value or 0 if it has not been used yet */
int hasvalue(char var);

void printvar(void);