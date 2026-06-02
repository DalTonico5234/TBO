#include "String.h"
#include <string.h>
#include <stdlib.h>

struct string
{
    char *c;
    int len;
    int alocated_size;
};

String *create_string(char *c)
{
    String *s = (String *)malloc(sizeof(String));

    s->c = strdup(c);
    s->len = s->alocated_size = strlen(c);

    return s;
}

String *create_empty_string()
{
    String *s = (String *)malloc(sizeof(String));

    s->c = (char *) calloc (ALOC_SIZE, sizeof(char));
    s->alocated_size = ALOC_SIZE;
    s->c[0] = '\0';
    s->len = 0;

    return s;
}

String *create_empty_string_by_size(int size)
{
        String *s = (String *)malloc(sizeof(String));

    s->c = (char *) calloc (size+1, sizeof(char));
    s->alocated_size = size+1;
    s->c[0] = '\0';
    s->len = 0;

    return s;
}

void append_to_string(String *s, char *c)
{
    if (s->len + strlen(c) > s->alocated_size)
    {
        s->alocated_size += ALOC_SIZE;
        s->c = (char *) realloc (s->c, s->alocated_size*sizeof(char));
        append_to_string(s, c);
        return;
    }

    strcat(s->c, c);
    s->len = strlen(s->c);
}

void append_char_to_string(String *s, char c)
{
    s->c[s->len++] = c;
    s->c[s->len] = '\0';
}

int compare_from_string(String *s, String *t, int d)
{
    int min = s->len < t->len ? s->len : t->len;
    for (int i = d; i < min; i++)
    {
        if (s->c[i] < t->c[i])
        {
            return -1;
        }
        if (s->c[i] > t->c[i])
        {
            return 1;
        }
    }
    return s->len - t->len;
}

int compare(String *s, String *t)
{
    return compare_from(s, t, 0);
}

char get_char(String *s, int idx)
{
    if (s->len < idx) return '\0';

    return s->c[idx];
}

void free_string(String *s)
{
    free(s->c);
    free(s);
}
