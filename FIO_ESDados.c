#include "TRE_tree"
#include "FIO_ESDados.h"
#include <stdlib.h>
#include <stdio.h>


//Lê de arquivo, e  já insere em árvore
void FIO_lerArquivo(char nomeArquivo[],tree *x)
{
    int i;
    FILE *file;
    if(!(file = fopen(nomeArquivo,"r"))) exit(0);
    fscanf(file, "%d",tamanho);
    while(1)
    {
        fscanf(file, "%d",i);
        if(feof(file))break;
        if (ferror(file)){
            printf("Erro ao ler arquivo de dados");
            exit(0);
        }
        INS_insert(x,i);
    }
    fclose(file);
}
