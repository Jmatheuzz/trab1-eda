#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 17

typedef struct empresa{
	int id;
	char razaoSocial [50];
	char endereco [50];
	char responsavel [30];
	int anoCriacao;
	int numeroServicos;

}Tempresa;

typedef struct no{
	Tempresa cliente;
	int fator_b;
	
	struct no* esq;
	struct no* dir;

}Tno;

typedef struct{
	int chave;
	Tno *valor;
} Telemento;
        
typedef struct{
        Telemento elemento[MAX];
        int n;
} Tlista;

Tempresa cria(int id, char razao[] , char endereco[] , char responsavel[] , int ano, int Nservicos);

int hashing(int chave);
void criar(Tlista *);
int tamanho(Tlista);
int elemento(Tlista, int, Telemento *);
void exibir(Tlista );
int inserirTabela(Tlista *, Telemento);
float taxaOcupacao(Tlista);



int altura_AVL(Tno *a);
int calcula_FB(Tno *a);
Tno* rotacao_simples_esquerda(Tno *a);
Tno* rotacao_simples_direita(Tno *a);
Tno* balanceio_direita(Tno *a);
Tno* balanceio_esquerda(Tno *a);
Tno* balanceamento(Tno* a);
Tno* inserirAVL(Tno* a, Tempresa cliente);
void imprime(Tno* a);