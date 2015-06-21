#ifndef RBL_REDBLACK_H
#define	RBL_REDBLACK_H

typedef struct redBlack{
	int dado;
	struct redBlack *esq;
	struct redBlack *dir;
	struct redBlack *pai;
	int isBlack; //isBlack 0 se for vermelho, 1 se for preto;
}redBlack;

redBlack* RBL_criaNo(int dado);

void RBL_rotacaoDir (redBlack **x);

void RBL_rotacaoEsq (redBlack **x);

void RBL_bal(redBlack **x, redBlack *no);

redBlack* RBL_insere(redBlack *x,int dado);

redBlack* RBL_remove(redBlack *x,int dado);

void RBL_ERD(redBlack *x);

void RBL_rewind(redBlack **x);

#endif	/* RBL_REDBLACK_H */