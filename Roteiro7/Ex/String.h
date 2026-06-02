#ifndef String_h
#define String_h

typedef struct string String;

// 1 MiB
#define ALOC_SIZE 1048576 

String *create_string(char *c);

String *create_empty_string();

String *create_empty_string_by_size(int size);

void append_to_string(String *s, char *c);

void append_char_to_string(String *s, char c);

int compare_from_string(String *s, String *t, int d);

int compare(String *s, String *t);

void free_string(String *s);

#endif