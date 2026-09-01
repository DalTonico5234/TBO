all: compile

# Configurações de pastas e arquivos
DIR_IN = ./in-exemplos
DIR_OUT = ./out-exemplos
EXEC = ./trab1

# Lista de índices (1 a 8)
IDS = 1 2 3 4 5 6 7 8

# K específico para cada caso
K_1 = 2
K_2 = 4
K_3 = 5
K_4 = 5
K_5 = 10
K_6 = 20
K_7 = 40
K_8 = 80


# Parâmetros do gcc
GCC_FLAGS = -g -Wall -Wextra -Werror

compile:
	gcc *.c -o trab1

debug_compile:
	gcc *.c $(GCC_FLAGS) -o trab1

# Comandos completos de execução
CMD = $(1) $(EXEC) $(DIR_IN)/$(2).txt $(K_$(2)) $(DIR_OUT)/$(2).txt
VALGRIND_CMD = valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes

run:
	@mkdir -p $(DIR_OUT)
	@$(foreach i, $(IDS),\
		$(call CMD,,$(i)); \
		)

debug_run:
	@mkdir -p $(DIR_OUT)
	@$(foreach i, $(IDS),\
		$(call CMD,$(VALGRIND_CMD),$(i)); \
		)
	
test:
	$(VALGRIND_CMD) $(EXEC) entrada.txt 2 saida.txt

real_test:
	tar -xzvf 2024101206,2024101213,2024101209.tar.gz
	make
	./trab1 in5.txt 10 out5.txt

tar:
	tar -czvf 2024101206,2024101213,2024101209.tar.gz *.c *.h 2024101206,2024101213,2024101209.pdf Makefile
