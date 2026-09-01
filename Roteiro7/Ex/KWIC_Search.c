#include "KWIC_Search.h"
#include "String.h"
#include "Suffix.h"
#include <stdlib.h>

struct kwic
{
    String *big_string;
    Suffix **suf_array;
    int big_string_size;
    int context;
};


KWIC *create_KWIC(int context, FILE *input)
{
    KWIC *system =  (KWIC *) malloc (sizeof(KWIC));

    system->context = context;
    system->suf_array = NULL;

    fscanf(input, "%d\n", &system->big_string_size);

    system->big_string = create_empty_string_by_size(system->big_string_size);

    return system;
}

// static void search(KWIC *system);

void read(KWIC *system, FILE *input)
{
    char c;
    for (int i=0; i < system->big_string_size; i++)
    {
        fscanf(input, "%c", &c);
        if ((c == ' ' && 
            get_last_char(system->big_string) == ' ')
            || c == '\n')
            continue;

        append_char_to_string(system->big_string, c);
    }

    system->big_string = create_string(system->big_string);
    system->big_string_size = get_len(system->big_string);
}

void create_suffix_array(KWIC *system)
{
    system->suf_array = (Suffix **) calloc (system->big_string_size, sizeof(Suffix *));

    for (int i=0; i < system->big_string_size; i++)
    {
        system->suf_array[i] = create_suffix(system->big_string, i);
    }    
}

void suffix_array_sort(KWIC *system);

void run(KWIC *system)
{
    print_string(system->big_string);
}

void free_KWIC(KWIC *system)
{
    free_string(system->big_string);
    free(system);
}