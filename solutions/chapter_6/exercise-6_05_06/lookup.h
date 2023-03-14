#ifndef LOOKUP_FILE
#define LOOKUP_FILE

struct keypair {
    char* key;
    char* value;
    struct keypair* next;
};

struct keypair* install(char* s, char* t);
struct keypair* lookup(char* s);
void undef(char* s);
void printtable(void);

#endif 