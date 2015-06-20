#include "TRE_tree"
#include "FIO_ESDados.h"
#include <stdlib.h>
#include <stdio.h>

//Lê de arquivo, e  já insere em árvore
tree* FIO_lerArquivo(char nomeArquivo[]){
    int i;
    FILE *file;
    tree *x = NULL;
    if(!(file = fopen(nomeArquivo,"r"))) exit(0);
    while(1){
        fscanf(file, "%d",i);
        if(feof(file))break;
        if (ferror(file)){
            printf("Erro ao ler arquivo de dados");
            exit(0);
        }
        x = TRE_insere(x,i);
    }
    fclose(file);
    return x;
}