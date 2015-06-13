#ifndef TRE_TREE_H
#define	TRE_TREE_H

typedef struct tree{
	int valor[4];
	struct tree *filho[4];
	struct tree *pai;
}tree;

void TRE_print(tree *x);


#endif	/* TRE_TREE_H */