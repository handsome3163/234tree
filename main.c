#include "CNV_conversao.h"
#include "DEL_remocao.h"
#include "FIO_ESDados.h"
#include "INS_insercao.h"
#include "RBL_redBlack.h"
#include "TRE_tree.h"

#include <stdio.h>

int main(){
	int flag;
	char arq[30];
	redBlack *rb;
	tree *x;
	printf("Nome do arquivo a ser lido: ");
	scanf(" %s", arq);
	FIO_lerArquivo(arq,x);
	while(1){
		printf("1. Inserir novo elemento na árvore 2-3-4\n");
		printf("2. Remover elemento da árvore 2-3-4\n");
		printf("3. Imprimir árvore 2-3-4\n");
		printf("4. Converter em uma árvore rubro-negra\n");
		printf("5. Sair\n");
		scanf("%d",&flag);
		switch(flag){
			case 1:
				printf("Elemento a ser inserido: ");
				scanf("%d",&elm);
				INS_insercao(x,elm);
				system("clear");
				break;
			case 2:
				printf("Elemento a ser removido: ");
				scanf("%d",&elm);
				DEL_remocao(x,elm);
				system("clear");
				break;
			case 3:
				TRE_print(x);
				break;
			case 4:
				CNV_conversao(x,rb);
				RBL_ERD(rb);
				system("clear");
				break;
			case 5:
				return 0;
				break;
			default:
				printf("Comando não reconhecido.");
				break;
		}
	}
}