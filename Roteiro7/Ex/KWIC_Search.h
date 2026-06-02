#ifndef KWIC_Search_h
#define KWIC_Search_h

typedef struct kwic KWIC;

#include <stdio.h>

KWIC *create_KWIC(FILE *input, int context);

void read(KWIC *system);

void create_suffix_array(KWIC *system);

void suffix_array_sort(KWIC *system);

void run(KWIC *system);

void free_KWIC(KWIC *system);

#endif