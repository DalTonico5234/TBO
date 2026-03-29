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
    Pilha *operadores = criaPilha();
    Pilha *operandos = criaPilha();

    double operando = 0;
    double resultado = 0;
    char sResultado[6];

    for (int i = 1; i < argc; i++)
    {
        if ('0' <= argv[i][0] <= '9')
        {
            empilha(operandos, argv[i]);
        }
        else if (argv[i][0] == '+' || argv[i][0] == '-' || argv[i][0] == '*' || argv[i][0] == '/')
        {
            empilha(operadores, argv[i]);
        }
        else if (argv[i][0] == '(')
        {
            continue;
        }
        else if (argv[i][0] == ')')
        {
            double op1 =  atof((char *)desempilha(operandos));
            double op2 =  atof((char *)desempilha(operandos));
            char *operacao = desempilha(operadores);
            resultado = calculo(op1, op2, *operacao);
            sprintf(sResultado, "%f", resultado);
            empilha(operandos, sResultado);
        }
        else
        {
            printf("DEU PAU: Operacao Invalidaaaa!!!\n\n");
        }
    }
}