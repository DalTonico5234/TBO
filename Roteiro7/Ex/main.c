#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "ERROR: must be used as ./main <in_file.txt> context\n");
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "ERROR: file %s not found!\n", argv[1]);
        exit(1);
    }

    int context = atoi(argv[2]);
    if (context <= 0)
    {
        fprintf(stderr, "ERROR: context %s must be an integer greater than 0!\n", argv[2]);
        exit(1);
    }

    fclose(input);

    return 0;
}