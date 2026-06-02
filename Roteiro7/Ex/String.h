#ifndef String_h
#define String_h

typedef struct string String;

String *create_string(char *c);

int compare_from_string(String *s, String *t, int d);

int compare(String *s, String *t);

void free_string(String *s);

#endif