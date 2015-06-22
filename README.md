# 234tree
Trabalho de implementação de Árvores B do tipo 2-3-4 e Red Black, e também a conversão de 2-3-4 para Red Black.

Autores:
Erick Thomas - 32068, Flávio Wander – 30198, João Paulo M. O. Silva - 24482



# Compilação e Execução
Existe um shell script para auxiliar a compilação pelo gcc

para executa-lo em Unix use
$ sh compilar.sh

Para rodar o executavel
./out

Em Windows o comando pode não funcionar.
Os parametros para o compilador são:

gcc -Wall DEL_remocao.c RBL_redBlack.c TRE_tree.c FIO_ESDados.c CNV_conversao.c main.c -o out

O programa foi testado em Ubuntu 14.04 e MacOSX

## Execução
O programa pergunta qual arquivo usar para popular a arvore. Existe um arquivo de exemplo:
popular.txt



#Descrição dos modulos

##Funções de funcionamento básico da árvore 2-3-4
-Funções necessárias para o funcionamento da árvore 2-3-4, e seus módulos

##Função de inserção
-**INS_insert**: Função de inserção na árvore 234

##Função de remoção
NAO IMPLEMENTADO
-**DEL_remocao**: Função de remoção de um dado da árvore 234

##Funções Red-Black
-**RBL_bal**: Função de balanceamento da RB

-**RBL_insere**: Função de balanceamento da RB

-**RBL_remove**: Função de remoção da RB

##Função de conversão
-**CNV_converte**: Função de conversão de árvore 234 para Red Black
