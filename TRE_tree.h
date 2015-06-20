#ifndef TRE_TREE_H
#define	TRE_TREE_H

typedef struct tree{
	int valor[3];
	int numChaves;
	struct tree *filho[4];
	struct tree *pai;
}tree;

tree *TRE_insere(tree *x,int dado);
void TRE_insChave(tree *x, int dado, tree *filho);
tree *TRE_insBusca(tree *x, int dado, int *tam, int *aux);
int TRE_buscaBinaria (tree *x, int dado);
void TRE_print(tree *raiz);

#endif	/* TRE_TREE_H */
