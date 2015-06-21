#include <stdlib.h>
#include <stdio.h>
#include "CNV_conversao.h"
#include "DEL_remocao.h"
#include "FIO_ESDados.h"
#include "RBL_redBlack.h"
#include "TRE_tree.h"

int main(int argc, char** argv){
    int flag,flag2, elm;
    char arq[30];
    redBlack *rb = NULL;
    tree *x = NULL;
    printf("Nome do arquivo a ser lido: ");
    scanf(" %s", arq);
    x = FIO_lerArquivo(arq);
    while(1){
        printf("1. Inserir novo elemento na árvore 2-3-4\n");
        printf("2. Remover elemento da árvore 2-3-4\n");
        printf("3. Imprimir árvore 2-3-4\n");
        printf("4. Converter em uma árvore rubro-negra\n");
        printf("5. Sair\n");
        scanf("%d",&flag);
        switch(flag){
            case 1:
                printf("Elemento a ser inserido: ");
                scanf("%d",&elm);
                x = TRE_insere(x,elm);
                system("clear");
                break;
            case 2:
                printf("Elemento a ser removido: ");
                scanf("%d",&elm);
                x = DEL_remocao(x,elm);
                system("clear");
                break;
            case 3:
                TRE_print(x);
                break;
            case 4:
                CNV_converte();
                RBL_ERD(rb);
                printf("Pressione qualquer tecla para continuar...");
                getchar();
                while(1){
                    printf("1. Inserir novo elemento na árvore Rubro-Negra\n");
                    printf("2. Remover elemento da árvore Rubro-Negra\n");
                    printf("3. Imprimir árvore Rubro-Negra\n");
                    printf("4. Sair\n");
                    scanf("%d",&flag2);
                    switch(flag){
                        case 1:
                            printf("Elemento a ser inserido: ");
                            scanf("%d",&elm);
                            rb = RBL_insere(rb,elm);
                            system("clear");
                            break;
                        case 2:
                            printf("Elemento a ser removido: ");
                            scanf("%d",&elm);
                            rb = RBL_remove(rb,elm);
                            system("clear");
                            break;
                        case 3:
                            RBL_ERD(rb);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Comando não reconhecido.");
                            break;
                    }
                    if(flag2==4)break;
                }
                system("clear");
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Comando não reconhecido.");
                break;
        }
    }
}
