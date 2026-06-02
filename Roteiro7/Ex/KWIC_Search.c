#include "KWIC_Search.h"
#include "String.h"

struct kwic
{
    String *big_string;
    int big_string_size;
    int context;
};


KWIC *create_KWIC(int context, FILE *input)
{
    KWIC *system =  (KWIC *) malloc (sizeof(KWIC));

    system->context = context;
    system->context = context;

    fscanf(input, "%d\n", &system->big_string_size);

    system->big_string = create_empty_string_by_size(system->big_string_size);

    return system;
}

static void search(KWIC *system);

void read(KWIC *system, FILE *input)
{
    char c;
    for (int i=0; i < system->big_string_size; i++)
    {
        fscanf(input, "%c", &c);
        // Lógica de processamento deve entrar aqui
        append_char_to_string(system->big_string, c);
    }
}

void create_suffix_array(KWIC *system);

void suffix_array_sort(KWIC *system);

void run(KWIC *system);

void free_KWIC(KWIC *system)
{
    free_string(system->big_string);
    free(system);
}