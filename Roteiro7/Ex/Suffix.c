#include "Suffix.h"
#include <stdlib.h>

struct suffix
{
    String *s;
    int index;
};

Suffix *create_suffix(String *s, int index)
{
    Suffix *suf = (Suffix *) malloc (sizeof(Suffix));

    suf->s = s;
    suf->index = index;

    return suf;
}

int compare_from_suffix(Suffix *s, Suffix *t, int d)
{
    return compare_from_string(s->s, t->s, d);
}

void free_suffix(Suffix *suf)
{
    free_string(suf->s);
    free(suf);
}
