all: compile

compile:
	gcc *.c -o trab2

# Configurações de pastas e arquivos
DIR_IN = ./exemplo/exemplo
EXEC = ./trab2

# Parâmetros do gcc
GCC_FLAGS = -g -Wall -Wextra -Werror

debug_compile:
	gcc *.c $(GCC_FLAGS) -o trab2

# Comandos completos de execução
CMD =$(EXEC) $(DIR_IN)/
VALGRIND_CMD = valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes

run:
	$(CMD)

debug_run:
	$(VALGRIND_CMD) $(CMD)

tar:
	tar -czvf 2024101208,2024101213,2024102896.tar.gz *.c *.h Makefile
