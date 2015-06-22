/*
Trabalho de implementação de Árvores B do tipo 2-3-4 e Red Black, e também a conversão de 2-3-4 para Red Black.

Autores:
Erick Thomas - 32068, Flávio Wander – 30198, João Paulo M. O. Silva - 24482
*/
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
