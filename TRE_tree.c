/*
Trabalho de implementação de Árvores B do tipo 2-3-4 e Red Black, e também a conversão de 2-3-4 para Red Black.

Autores:
Erick Thomas - 32068, Flávio Wander – 30198, João Paulo M. O. Silva - 24482
*/
#include <stdio.h>
#include <stdlib.h>
#include "TRE_tree.h"

void TRE_insChave(tree *x, int dado, tree *filho){
	int k, pos;	
	pos= TRE_buscaBinaria(x,dado);
	k = x->numChaves;
	while (k > pos && dado < x->valor[k-1])
	{
		x->valor[k] = x->valor[k-1];
		x->filho[k+1] = x->filho[k];
		k--;
	}
	x->valor[pos] = dado;
	x->filho[pos+1]= filho;
	x->numChaves++;
}

tree *TRE_insBusca(tree *x, int dado, int *tam, int *aux){
	int i , pos, med;
	tree *temp, *filho;	
	if (x == NULL)
	{
		*tam = 1;
		*aux = dado;
		return(NULL);
	}else{
		pos = TRE_buscaBinaria(x,dado);
		if (x->numChaves > pos && x->valor[pos] == dado)
		{
			printf("Erro: Valor ja esta contido.\n");
			*tam = 0;
		}
		else{	
			filho = TRE_insBusca (x->filho[pos],dado, tam,aux);
			if(*tam)
			{
				if (x->numChaves < 3)
				{
					TRE_insChave(x,*aux,filho);
					*tam = 0;
				}else{
					temp = (tree*)malloc(sizeof(tree));
					temp->numChaves = 0;
					for (i=0; i< 3; i++){
						temp->filho[i] = NULL;
					}
					med = x->valor[1];
					temp->filho[0] = x->filho[2];
					for (i= 2; i<3;i++){
						TRE_insChave(temp,x->valor[i],x->filho[i+1]);
					}
					for (i=1;i<3;i++){
						x->valor[i] = 0;
						x->filho[i+1]=NULL;
					}
					x->numChaves = 1;
					if(pos <= 1){
						TRE_insChave(x,*aux,filho);
					}else{
						TRE_insChave(temp,*aux,filho);
					}
					*aux = med;
					return (temp);
				}
			}
		}
	}

	return x;
}

tree *TRE_insere(tree *x,int dado){
	int tam;
	int aux, i;
	tree *filho, *novaRaiz;	
	filho = TRE_insBusca(x,dado,&tam,&aux);
	if (tam){
		novaRaiz = (tree*)malloc(sizeof(tree));
		novaRaiz->numChaves = 1;
		novaRaiz->valor[0] = aux;
		novaRaiz->filho[0] = x;
		novaRaiz->filho[1] = filho;
		for(i=2; i<=3;i++)
		novaRaiz->filho[i] = NULL;
		return(novaRaiz);
	}else{
		return (x);
	}
}

int TRE_buscaBinaria (tree *x, int dado){
	int meio, i, f;
	i= 0;
	f= x->numChaves-1;
	while (i<= f){
		meio = (i+f)/2;
		if (x->valor[meio] == dado)
		return (meio);	//Encontrou a posição que a chave está
		else if (x->valor[meio] > dado)
		f = meio - 1;
		else 
		i = meio + 1;
	}
	return (i);	
}

void TRE_print(tree *raiz){
	int i;
	if (raiz != NULL){
     	for (i = 0; i < raiz->numChaves; i++){
        	TRE_print(raiz->filho[i]);
        	printf("\n%d", raiz->valor[i]);
      	}
		TRE_print(raiz->filho[i]);
    }
}
