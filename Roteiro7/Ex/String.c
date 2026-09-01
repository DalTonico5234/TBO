#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct string
{
    char *c;
    int len;
    int alocated_size;
};

String *create_string(String *c)
{
    String *s = (String *)malloc(sizeof(String));

    s->c = strdup(c->c);
    s->len = s->alocated_size = strlen(s->c);
    free_string(c);

    return s;
}

String *create_empty_string()
{
    String *s = (String *)malloc(sizeof(String));

    s->c = (char *)calloc(ALOC_SIZE, sizeof(char));
    s->alocated_size = ALOC_SIZE;
    s->c[0] = '\0';
    s->len = 0;

    return s;
}

String *create_empty_string_by_size(int size)
{
    String *s = (String *)malloc(sizeof(String));

    s->c = (char *)calloc(size + 1, sizeof(char));
    s->alocated_size = size + 1;
    s->c[0] = '\0';
    s->len = 0;

    return s;
}

void append_to_string(String *s, char *c)
{
    if (s->len + (int)strlen(c) > s->alocated_size)
    {
        s->alocated_size += ALOC_SIZE;
        s->c = (char *)realloc(s->c, s->alocated_size * sizeof(char));
        append_to_string(s, c);
        return;
    }

    strcat(s->c, c);
    s->len = strlen(s->c);
}

void append_char_to_string(String *s, char c)
{
    char c1[2];
    c1[0] = c;
    c1[1] = '\0';
    strcat(s->c, c1);
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
    return compare_from_string(s, t, 0);
}

char get_char(String *s, int idx)
{
    if (s->len < idx)
        return '\0';

    return s->c[idx];
}

char get_last_char(String *s)
{
    return s->c[(int)strlen(s->c) - 1];
}

int get_len(String *s)
{
    return s->len;
}

char *get_real_string(String *s)
{
    return s->c;
}

void print_string(String *s)
{
    printf("%s\n", s->c);
}

void free_string(String *s)
{
    free(s->c);
    free(s);
}