#ifndef Suffix_h
#define Suffix_h

#include "String.h"

typedef struct suffix Suffix;

Suffix *create_suffix(String *s, int index);

int compare_from_suffix(Suffix *s, Suffix *t, int d);

String *get_string(Suffix *s);

void free_suffix(Suffix *suf);

#endif