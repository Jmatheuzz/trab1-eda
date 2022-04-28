#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){

    Tlista lista;
    criar(&lista);

    Tempresa cliente1 = cria(1, "LAISSA EH MELHOR LTDA", "Reriutaba", "Laissa", 2001, 4);
    Tempresa cliente2 = cria(2, "JM PRODUCOES LTDA", "Santa Clara", "JM", 2001, 52);
    Tempresa cliente3 = cria(3, "SABRISE LTDA", "TABULEIRO", "SABRINA", 2002, 10);

    Tno *arvore1 = NULL;
    arvore1 = inserirAVL(arvore1, cliente1);
    arvore1 = inserirAVL(arvore1, cliente2);
    arvore1 = inserirAVL(arvore1, cliente3);

    Telemento elemento;
    elemento.chave = 120;
    elemento.valor = arvore1;

    inserirTabela(&lista, elemento);

    exibir(lista);

    return 0;
}