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
	//função de balanceamento da RB
}

void RBL_insere(redBlack *x,int dado)
{	
	//função de balanceamento da RB
}

void RBL_remove(redBlack *x,int dado)
{
    //função de remoção da RB
}