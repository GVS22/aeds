#include "disco.h"

void TamanhoDisco(char*Arquivo, int *linhas, int*colunas){

    FILE *pfile = fopen(Arquivo, "r");

    if(pfile == NULL){
        perror("Nao foi carregado");
        exit(1);
    }

    int numeroLinhas = 1;
    char ponteiro[1024];
    const char delimitador[] = ", A";
    int auxiliar = 0;
    int numeroColunas = 0;

    fgets(ponteiro, 1024, pfile);

    while(!feof(pfile)){

        char *ponteiroToken = strtok(ponteiro, delimitador);
        auxiliar++;

        while(ponteiroToken != NULL){

            ponteiroToken = strtok(NULL, delimitador);
            auxiliar++;
        }

        if(auxiliar > numeroColunas){

            numeroColunas = auxiliar;
            
        }

        auxiliar = 0;
        fgets(ponteiro, 1024, pfile);
        numeroLinhas++;
    }

    fclose(pfile);

    *linhas = numeroLinhas;
    *colunas = numeroColunas-1;
    
}

void PrencherDisco(char *Arquivo, const int numeroLinhas, const int numeroColunas, int matriz[numeroLinhas][numeroColunas])
{
    FILE *pfile= fopen(Arquivo, "r");
    if(pfile == NULL)
    {
        perror("nao foi carregado");
        exit(2);
    }
    char ponteiro[1024];
    const char delimitador[] = ", A";
    int contadorLinhas = 0;
    int contadorColunas = 0;

    for(int i = 0; i < numeroLinhas; i++)
    {
        for(int j = 0; j < numeroColunas; j++)
        {
            matriz[i][j] = 0;
        }
    }

    while(!feof(pfile))
    {
        fgets(ponteiro, 1024, pfile);
        char *ponteiroToken = strtok(ponteiro, delimitador);

        while(ponteiroToken != NULL)
        {
            matriz[contadorLinhas][contadorColunas] = atoi(ponteiroToken);
            ponteiroToken = strtok(NULL, delimitador);
            contadorColunas++;
        }
        contadorLinhas++;
        contadorColunas = 0;
    }
    fclose(pfile);
}