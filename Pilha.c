#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int numero;
    struct nodo * prox;
}NODO;

NODO * criarNodo(int conteudo){
    NODO*novoNodo;
    novoNodo = (NODO*)malloc(sizeof(NODO));
    novoNodo->numero = conteudo;
    novoNodo->prox=NULL;

    return novoNodo;
}

void push(NODO ** pilha, NODO * no){
    if (*pilha == NULL){
        *pilha = no;
    }else{
        no->prox = *pilha;
        *pilha = no;
    }
}
int pop(NODO ** pilha){
    int eliminado;
    NODO * aux;
    if(*pilha == NULL){
        printf("\nPilha vazia.");
    }else{
        aux = *pilha;
        *pilha = (*pilha)->prox;
        eliminado = aux->numero;
    }
    return eliminado;
}

int vazia(NODO ** pilha){
    if(*pilha==NULL){
        return 1;
    }else{
        return 0;
    }
}

void imprimePilha(NODO ** pilha){
    NODO * aux;
    aux = *pilha;
    if(*pilha == NULL){
        printf("\nPilha Vazia");
    }else{
        while(aux != NULL){
            printf("%d :", aux->numero);
            aux = aux->prox;
        }
    }
}



void imprimePilhaReal(NODO ** pilha){
    NODO * pilha2=NULL; int aux;//pilha2 devolve a  pilha 1
    while(*pilha!=NULL){
        printf("%d-", (*pilha)->numero);
        aux = pop(pilha);
        push(&pilha2, criarNodo(aux));
    }
    while(pilha2!= NULL){
        aux = pop(&pilha2);
        push(pilha, criarNodo(aux));
    }
}

int main (){
    NODO * pilhaTeste = NULL;
    push(&pilhaTeste, criarNodo(1));
    push(&pilhaTeste, criarNodo(2));
    push(&pilhaTeste, criarNodo(3));


    printf("\nTeste de imprime pilha: \n");
    imprimePilha(&pilhaTeste);
    printf("\n");

    printf("\nTeste de imprime pilha real: \n");
    imprimePilhaReal(&pilhaTeste);
    printf("\n");

    free(pilhaTeste);


    return 0;
}
