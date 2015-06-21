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
