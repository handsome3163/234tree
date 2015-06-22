/*
Trabalho de implementação de Árvores B do tipo 2-3-4 e Red Black, e também a conversão de 2-3-4 para Red Black.

Autores:
Erick Thomas - 32068, Flávio Wander – 30198, João Paulo M. O. Silva - 24482
*/

#include "RBL_redBlack.h"
#include "TRE_tree.h"
#include "CNV_conversao.h"
#include <stdio.h>


redBlack *converter(tree *tree234, redBlack *pai);


redBlack *converterNo2(tree *tree234, redBlack* pai)
{
    redBlack *novoNoPreto = RBL_criaNo(tree234->valor[0]);

    novoNoPreto->pai = pai;
    novoNoPreto->isBlack = 1;
    novoNoPreto->esq = converter(tree234->filho[0], novoNoPreto);
    novoNoPreto->dir = converter(tree234->filho[1], novoNoPreto);
    
    return novoNoPreto;
}


redBlack *converterNo3(tree *tree234, redBlack *pai)
{
    /* Sempre joga o primeiro elemento do no para baixo, a esquerda, como vermelho */
    redBlack *novoNoPreto = RBL_criaNo(tree234->valor[1]);
    novoNoPreto->pai = pai;
    novoNoPreto->isBlack = 1;
    
    novoNoPreto->dir = converter(tree234->filho[2], novoNoPreto);
    novoNoPreto->esq = RBL_criaNo(tree234->valor[0]);
    
    novoNoPreto->esq->pai = novoNoPreto;
    novoNoPreto->esq->esq = converter(tree234->filho[0], novoNoPreto->esq);
    novoNoPreto->esq->dir = converter(tree234->filho[1], novoNoPreto->esq);

    return novoNoPreto;
}

redBlack *converterNo4(tree *tree234, redBlack *pai)
{
    /* o elemento do meio do no vira preto, o primeiro e o ultimo viram sub nos vermelhos */
    redBlack *novoNoPreto = RBL_criaNo(tree234->valor[1]);
    novoNoPreto->pai = pai;
    novoNoPreto->isBlack = 1;

    novoNoPreto->esq = RBL_criaNo(tree234->valor[0]);
    novoNoPreto->esq->pai = novoNoPreto;
    novoNoPreto->esq->esq = converter(tree234->filho[0], novoNoPreto->esq);
    novoNoPreto->esq->dir = converter(tree234->filho[1], novoNoPreto->esq);

    novoNoPreto->dir = RBL_criaNo(tree234->valor[2]);
    novoNoPreto->dir->pai = novoNoPreto;
    novoNoPreto->dir->esq = converter(tree234->filho[2], novoNoPreto->dir);
    novoNoPreto->dir->dir = converter(tree234->filho[3], novoNoPreto->dir);

    return novoNoPreto;
}


redBlack *converter(tree *tree234, redBlack *pai)
{
    if(!tree234 || tree234->numChaves==0)
        return NULL;


    if(tree234->numChaves==1)
        return converterNo2(tree234, pai);


    if(tree234->numChaves==2)
        return converterNo3(tree234, pai);
    

    if(tree234->numChaves==3)
        return converterNo4(tree234, pai);

    printf("Erro. O no a ser convertido contem mais de 3 chaves");
    printf("No: %d %d %d", tree234->valor[0], tree234->valor[1], tree234->valor[2]);
    return NULL;
}


/* Funcao exposta no modulo */
redBlack *CNV_converter(tree *tree234)
{
    return converter(tree234, NULL);
}
