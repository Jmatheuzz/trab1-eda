#include "lib.h"
#include <string.h>

Tempresa cria(int id, char razao[] , char endereco[] , char responsavel[] , int ano, int Nservicos){
    Tempresa *cliente = (Tempresa*) malloc(sizeof(Tempresa));
    cliente->id = id;
    strcpy(cliente->razaoSocial, razao);
    strcpy(cliente->endereco, endereco);
    strcpy(cliente->responsavel, responsavel);
    cliente->anoCriacao = ano;
    cliente->numeroServicos = Nservicos;

    return *cliente;
}

void criar(Tlista *L){	
    memset(L->elemento, 0, sizeof(L->elemento));
    L->n = 0;
}
    
int tamanho(Tlista L){
    return L.n;
}

int elemento(Tlista L, int pos, Telemento *valor){
    if(pos<0 || pos>MAX) return 0;

    *valor = L.elemento[pos];
    return 1;
}

void exibir(Tlista L){
    for(int i = 0 ; i<MAX ; i++){
        if(L.elemento[i].chave){
            printf("Indice: %d - Chave: %d\n", i, L.elemento[i].chave);
            imprime(L.elemento[i].valor);
        }
    }
}  

int hashing(int chave){
    return chave % MAX;
}

int inserirTabela(Tlista *L, Telemento dado){
    int hash = hashing(dado.chave);
    L->elemento[hash] = dado;
    L->n+=1;
    return hash;
}
//-----------TRATAMENTO PARA COLIS�ES --------------//
float taxaOcupacao(Tlista L){
	return (float) (L.n / MAX);
}










int altura_AVL(Tno *a){
	int altEsq = 0, altDir = 0;
    if(a == NULL) {
        return 0;
    } else {
        altEsq = altura_AVL(a->esq);
        altDir = altura_AVL(a->dir);
        if(altEsq > altDir) {
            return 1 + altEsq;
        }else{
            return 1 + altDir;
        }
    }

}

int calcula_FB(Tno *a){
	return (altura_AVL(a->esq) - altura_AVL(a->dir));
}

Tno* rotacao_simples_esquerda(Tno *a){
	Tno *aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    a = aux;
    return a;
}
Tno* rotacao_simples_direita(Tno *a){
	Tno *aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    a = aux;
    return a;
}
Tno* balanceamento(Tno* a){
	int fator = calcula_FB(a);
    if(fator>1){
        return balanceio_esquerda(a);
    }else {
        if(fator<-1){
            return balanceio_direita(a);
        }
    }
    return a;
}

Tno* balanceio_direita(Tno *a){
    int fator = calcula_FB(a->dir);
    if(fator<0){
        return rotacao_simples_esquerda(a);
    }else{
        if(fator>0){
            
            a->dir = rotacao_simples_direita(a->dir);
            a = rotacao_simples_esquerda(a);
            return a;
        }
    }
    return a;
}

Tno* balanceio_esquerda(Tno *a){
    int fator = calcula_FB(a->esq);
    if(fator>0){
        return rotacao_simples_direita(a);
    }else{
        if(fator<0){
            a->esq = rotacao_simples_esquerda(a->esq);
            a = rotacao_simples_direita(a);
            return a;
        }
    }
    return a;
}

Tno* inserirAVL(Tno* a, Tempresa cliente){
	if(a == NULL){
        a = (Tno*) malloc(sizeof(Tno));
        a->cliente = cliente;
        a->esq = NULL;
        a->dir = NULL;
    }else {
        if(a->cliente.id > cliente.id){
            a->esq = inserirAVL(a->esq, cliente);
            a = balanceamento(a);
        }else{
                a->dir = inserirAVL(a->dir, cliente);
                a = balanceamento(a);
        }
    }
    return a;
}
void imprime(Tno* a){
	if (a == NULL){
		return;
	}
    printf("%d- %s ",a->cliente.id, a->cliente.responsavel);
 
    if(a->esq != NULL)
        printf("(E: %d)", a->esq->cliente.id);
    if(a->dir != NULL)
        printf("(D: %d)\n", a->dir->cliente.id);
    printf("\n");
 
    imprime(a->esq);
    imprime(a->dir);
}
