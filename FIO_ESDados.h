/*
Trabalho de implementação de Árvores B do tipo 2-3-4 e Red Black, e também a conversão de 2-3-4 para Red Black.

Autores:
Erick Thomas - 32068, Flávio Wander – 30198, João Paulo M. O. Silva - 24482
*/
#ifndef FIO_ESDADOS_H
#define	FIO_ESDADOS_H

#include "TRE_tree.h"

/* Le um arquivo de texto para popular a arvore 2-3-4

Cada numero a ser inserido deve ficar em uma linha. Exemplo:

5
10
30
150
*/
tree* FIO_lerArquivo(char nomeArquivo[]);

#endif	/* FIO_ESDADOS_H */
