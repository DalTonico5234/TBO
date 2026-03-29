#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

double calculo(double op1, double op2, char operacao)
{
    if (operacao == '+')
    {
        return op1 + op2;
    }
    else if (operacao == '-')
    {
        return op1 - op2;
    }
    else if (operacao == '*')
    {
        return op1 * op2;
    }
    else if (operacao == '/')
    {
        if (op2 == 0)
        {
            printf("NUNCA DIVIDIRAS POR 0\n\n");
            return 0;
        }
        return op1/op2;
    }
    else
    {
        printf("DEU PAU ALI: Operacao Invalidaaaa!!!\n\n");
    }
}

int main(int argc, char *argv[])
{
    Pilha *operadores = criaPilha(sizeof(char));
    Pilha *operandos = criaPilha(sizeof(double));

    double operando = 0;
    char operador = 0;
    double resultado = 0;

    for (int i = 1; i < argc; i++)
    {
        if ('0' <= argv[i][0] && argv[i][0]<= '9')
        {
            operando = atof(argv[i]);
            empilha(operandos, &operando);
        }
        else if (argv[i][0] == '+' || argv[i][0] == '-' || argv[i][0] == '*' || argv[i][0] == '/')
        {
            operador = argv[i][0];
            empilha(operadores, &operador);
        }
        else if (argv[i][0] == '(')
        {
            continue;
        }
        else if (argv[i][0] == ')')
        {
            double op2;
            desempilha(operandos, &op2);
            double op1;
            desempilha(operandos, &op1);
            desempilha(operadores, &operador);
            resultado = calculo(op1, op2, operador);
            empilha(operandos, &resultado);
        }
        else
        {
            printf("DEU PAU: Operacao Invalidaaaa!!!\n\n");
        }
    }
    printf("%.2f\n", resultado);

    destroiPilha(operadores);
    destroiPilha(operandos);
}