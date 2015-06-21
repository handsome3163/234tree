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
        return x;
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

redBlack* RBL_remove(redBlack *x,int dado){
    redBlack *no = x,*suc,*irmao,*fdir,*fesq,*rm;
    fdir = (redBlack*)calloc(1,sizeof(redBlack));
    fesq = (redBlack*)calloc(1,sizeof(redBlack));

    while(no->dado != dado){
        if(no->dado < dado) no = no->dir;
        else no = no->esq;
    }
    // Caso não esteja na árvore
    if(no == NULL){
        printf("Valor não se encontra na árvore");
        return x;
    }    
    rm = no;
    // Caso tenha dois filhos
    if(no->esq != NULL && no->dir != NULL){        
        suc = no->dir;
        while(suc->esq != NULL) suc = suc->esq;
        no->dado = suc->dado;
        no = suc; //Transforma caso "Dois filhos" em caso "Um filho" ou caso "folha"
    }
    // Caso Folha
    if(!no->esq&&!no->dir){
        if(no->isBlack == 0){   //Se for vermelho, não quebra nenhuma regra
            if(no->pai->dir == no) no->pai->dir = NULL;
            else no->pai->esq = NULL;
            free(no);
        }else{
            while(no->isBlack == 1 && no->pai != NULL){
                if(no->pai->esq == no){
                    irmao = no->pai->dir;
                    if(irmao->isBlack == 0){
                        //CASO 1
                        irmao->isBlack = 1;
                        irmao->pai = 0;
                        RBL_rotacaoEsq(&irmao->pai);
                        irmao = no->pai->dir;
                    }
                    if(irmao->dir) fdir = irmao->dir;
                    else fdir->isBlack = 1;
                    if(irmao->esq) fesq = irmao->esq;
                    else fesq->isBlack = 1;
                    if(fdir->isBlack == 1 && fesq->isBlack == 1){
                        //CASO 2
                        irmao->isBlack = 0;
                        while(no->pai != NULL && no->isBlack == 1){
                            irmao->isBlack = 0;
                            no = no->pai;
                            if(no->pai) irmao = no->pai->dir;
                        }
                        if(no->isBlack == 0){
                            no->isBlack = 1;
                            break;
                        }
                    }else{
                        if(fesq->isBlack == 0){
                            //CASO 3
                            fesq->isBlack = 1;
                            irmao->isBlack = 0;
                            RBL_rotacaoDir(&irmao);
                            irmao = no->pai->dir;
                            if(irmao->dir) fdir = irmao->dir;
                            else fdir->isBlack = 1;
                            if(irmao->esq) fesq = irmao->esq;
                            else fesq->isBlack = 1;
                        }
                        //CASO 4
                        irmao->isBlack = irmao->pai->isBlack;
                        irmao->pai->isBlack = 1;
                        fdir->isBlack = 1;
                        RBL_rotacaoEsq(&no->pai);
                        RBL_rewind(&x);
                        no = x;
                    }
                    
                }else{
                    irmao = no->pai->esq;
                    if(irmao->dir) fdir = irmao->dir;
                    else fdir->isBlack = 1;
                    if(irmao->esq) fesq = irmao->esq;
                    else fesq->isBlack = 1;
                    if(irmao->isBlack == 0){
                        //CASO 1
                        irmao->isBlack = 1;
                        irmao->pai = 0;
                        RBL_rotacaoDir(&irmao->pai);
                        irmao = no->pai->esq;
                    }
                    if(fdir->isBlack == 1 && fesq->isBlack == 1){
                        //CASO 2
                        irmao->isBlack = 0;
                        while(no->pai != NULL && no->isBlack == 1){
                            irmao->isBlack = 0;
                            no = no->pai;
                            if(no->pai) irmao = no->pai->esq;
                        }
                        if(no->isBlack == 0){
                            no->isBlack = 1;
                            break;
                        }
                    }else{
                        if(fdir->isBlack == 0){
                            //CASO 3
                            fdir->isBlack = 1;
                            irmao->isBlack = 0;
                            RBL_rotacaoEsq(&irmao);                            
                            irmao = no->pai->esq;
                            if(irmao->dir) fdir = irmao->dir;
                            else fdir->isBlack = 1;
                            if(irmao->esq) fesq = irmao->esq;
                            else fesq->isBlack = 1;
                        }
                        //CASO 4
                        irmao->isBlack = irmao->pai->isBlack;
                        irmao->pai->isBlack = 1;
                        fesq->isBlack = 1;
                        RBL_rotacaoDir(&no->pai);                        
                        RBL_rewind(&x);
                        no = x;
                    }
                }
            }            
            if(rm->pai->dir == rm) rm->pai->dir = NULL;
            else rm->pai->esq = NULL;
            free(rm);
        }
        x->isBlack = 1;
        return x;
    }
    if(no->esq == NULL ||no->dir == NULL){
        if(no->esq == NULL){            
            if(no->pai->esq == no)no->pai->esq = no->dir;
            else no->pai->dir = no->dir; 
            no->dir->pai = no->pai;
            if(no->dir->isBlack == 0) no->dir->isBlack = 1;
	}else{
            if(no->pai->esq == no) no->pai->esq = no->esq;
            else no->pai->dir = no->esq;
            no->esq->pai = no->pai;
            if(no->esq->isBlack == 0) no->esq->isBlack = 1;
	}        
        free(rm);
    }
    x->isBlack = 1;
    return x;
}


void RBL_ERD(redBlack *x){
    if(!x) return;
    RBL_ERD(x->esq);
    printf("Valor = %d ",x->dado);
    if(x->isBlack==1) printf("Cor = Preta\n");
    else printf("Cor = Vermelha\n");
    RBL_ERD(x->dir);
}
