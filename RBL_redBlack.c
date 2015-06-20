#include <stdio.h>
#include <stdlib.h>
#include "RBK_redBlack.h"

redBlack* RBL_criaNo(int dado)
{
	redBlack *novoNo;
	novoNo = (redBlack*)calloc(1,sizeof(redBlack));
	novoNo->dir = NULL;
	novoNo->esq = NULL;
	novoNo->pai = NULL;
	novoNo->isBlack = 0;
	novoNo->raiz = dado;
	return novoNo;
}

void RBL_rotacaoDir (redBlack *x)
{
    redBlack *y,*z;
    y = x->esq;
    z = y->dir;
    y->dir = x;
    y->pai = x->pai;
    x->pai = y;
    if(z){
        x->esq = z;
        z->pai = x;
    }else{
        x->esq = NULL;
    }
    if(y->pai->raiz <= y->raiz) y->pai->dir = y;
    else y->pai->esq = y;
}

void RBL_rotacaoEsq (redBlack *x)
{
    redBlack *y,*z,*xPai;
    y = x->dir;  
    z = y->esq;
    xPai = x->pai;
    y->esq = x;
    y->pai = xPai;
    x->pai = y;
    if(z){
        x->dir = z;
        z->pai = x;
    }else{
        x->dir = NULL;
    }
    if(xPai->raiz <= y->raiz) xPai->dir = y;
    else xPai->esq = y;
}

void RBL_bal(redBlack *x, redBlack *no)
{
	redBlack *avo;
    redBlack *tio = (*redBlack)malloc(sizeof(redBlack));
    redBlack *pai = no->pai;
    while(!pai->isBlack){
        avo = pai->pai;
        if(no->raiz < avo->raiz){
            if(!avo->dir) tio->isBlack = 1;
            else{
                tio = avo->dir;
                if(!tio->isBlack){
                    pai->isBlack = 1;
                    tio->isBlack = 1;
                    avo->isBlack = 0;
                    no = avo;
                    pai = no->pai;
                }else{
                    if(no == pai->dir){
                        RBL_rotacaoEsq(pai);
                        no = pai;
                        pai = no->pai;
                    }
                    pai->isBlack = 1;
                    avo->isBlack = 0;
                    RBL_rotacaoDir(avo);
                }
            }
        }else{
            if(no->raiz < avo->raiz){
                if(!avo->esq) tio->isBlack = 1;
                else{
                    tio = avo->direita;
                    if(!tio->isBlack){
                        pai->isBlack = 1;
                        tio->isBlack = 1;
                        avo->isBlack = 0;
                        no = avo;
                        pai = no->pai;
                    }else{
                        if(no == pai->esq){
                            RBL_rotacaoEsq(pai);
                            no = pai;
                            pai = no->pai;
                        }
                        pai->isBlack = 1;
                        avo->isBlack = 0;
                        RBL_rotacaoEsq(avo);
                    }
                }
            }
        }
    x->isBlack = 1;
    }
}

void RBL_insere(redBlack *x,int dado)
{	
	redBlack *aux = x,*auxPai, *novoNo;
    novoNo = RBL_criaNo(dado);
    if(!x->dir){
        x->dir = novoNo;
        novoNo->pai = x;
        return;
    }
    while(aux){
        auxPai = aux;
        if(aux->raiz <= dado) aux = aux->dir;
        else aux = aux->esq;
    }
    if(auxPai->raiz <= dado) auxPai->dir = novoNo;
    else auxPai->esq = novoNo;
    novoNo->pai = auxPai;
    RBL_bal(auxPai,dado);
}

void RBL_remove(redBlack *x,int dado)
{
    //função de remoção da RB
}

