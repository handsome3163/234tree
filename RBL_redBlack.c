#include <stdio.h>
#include <stdlib.h>
#include "RBL_redBlack.h"

redBlack* RBL_criaNo(int dado){
	redBlack *novoNo;
	novoNo = (redBlack*)calloc(1,sizeof(redBlack));
	novoNo->dir = NULL;
	novoNo->esq = NULL;
	novoNo->pai = NULL;
	novoNo->isBlack = 0;
	novoNo->dado = dado;
	return novoNo;
}

void RBL_rotacaoDir (redBlack **x){
    redBlack *y,*z,*xPai;
    xPai = (*x)->pai;
    y = (*x)->esq;
    z = y->dir;
    if(z){
        (*x)->esq = z;
        z->pai = *x;
    }else{
        (*x)->esq = NULL;
    }
    y->dir = *x;
    (*x)->pai = y;
    y->pai = xPai;
    if(xPai != NULL){
        if(y->pai->dado <= y->dado) y->pai->dir = y;
        else y->pai->esq = y;
    }
}

void RBL_rotacaoEsq (redBlack **x){
    redBlack *y,*z,*xPai;
    xPai = (*x)->pai;
    y = (*x)->dir;  
    z = y->esq;    
    if(z){
        (*x)->dir = z;
        z->pai = *x;
    }else{
        (*x)->dir = NULL;
    }
    y->esq = (*x);
    (*x)->pai = y;
    y->pai = xPai;    
    if(xPai != NULL){
        if(xPai->dado <= y->dado) xPai->dir = y;
        else xPai->esq = y;
    }
}

void RBL_rewind(redBlack **x){
    while(1){
        if((*x)->pai == NULL) break;
        else *x = (*x)->pai;
    }
}

redBlack* RBL_insere(redBlack *x,int dado){	
    redBlack *aux = x,*auxPai, *no,*tio =(redBlack*)malloc(sizeof(redBlack));
    no = RBL_criaNo(dado);
    if(x == NULL){
        x = no;
        x->isBlack = 1;
        return;
    }
    while(aux){
        auxPai = aux;
        if(aux->dado <= dado) aux = aux->dir;
        else aux = aux->esq;
    }
    if(auxPai->dado <= dado) auxPai->dir = no;
    else auxPai->esq = no;
    no->pai = auxPai;
    while(no->pai != NULL && no->isBlack == 0){
        if(no->pai->isBlack == 1) break;
        if(no->pai->pai != NULL){
            if(no->pai == no->pai->pai->esq){ //se for neto à esquerda
                if(!no->pai->pai->dir) tio->isBlack = 1;
                else tio = no->pai->pai->dir;
                if(tio->isBlack == 0){
                    no->pai->isBlack = 1;
                    tio->isBlack = 1;
                    no->pai->pai->isBlack = 0;
                    no = no->pai->pai;
                }else{
                    if(no == no->pai->dir){
                        no = no->pai;
                        RBL_rotacaoEsq(&no);
                    }
                    no->pai->isBlack = 1;
                    no->pai->pai->isBlack = 0;
                    RBL_rotacaoDir(&no->pai->pai);
                }
            }else{  //se for neto à direita
                if(!no->pai->pai->esq) tio->isBlack = 1;
                else tio = no->pai->pai->esq;
                if(tio->isBlack == 0){
                    no->pai->isBlack = 1;
                    tio->isBlack = 1;
                    no->pai->pai->isBlack = 0;
                    no = no->pai->pai;
                }else{
                    if(no == no->pai->esq){
                        no = no->pai;
                        RBL_rotacaoDir(&no);
                    }
                    no->pai->isBlack = 1;
                    no->pai->pai->isBlack = 0;
                    RBL_rotacaoEsq(&no->pai->pai);
                }
            }
        }else{
            no = no->pai;
        }
        RBL_rewind(&x);
        x->isBlack = 1;
    }
    RBL_rewind(&x);
    return x;
}

/*
void RBL_remove(redBlack *x,int dado)
{
    RBL_removeFix();
}
*/
void RBL_ERD(redBlack *x){
    if(!x) return;
    RBL_ERD(x->esq);
    printf("Valor = %d ",x->dado);
    if(x->isBlack==1) printf("Cor = Preta\n");
    else printf("Cor = Vermelha\n");
    RBL_ERD(x->dir);
}

//void RBL_removeFix(redBlack *x, redBlack *no){
//}