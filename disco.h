#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef DISCO_H
#define DISCO_H

void TamanhoDisco(char * Arquivo, int *linhas, int *colunas);

void PrencherDisco(char *Arquivo, const int numeroLinhas, const int numeroColunas, int matriz[numeroLinhas][numeroColunas]);

#endif