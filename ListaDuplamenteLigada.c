#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int data;
    struct nodo * prox;
    struct nodo * ant;
}NODO;

NODO * criarNodo(int num){
    NODO * novoNodo;
    novoNodo = (NODO *) malloc(sizeof(NODO));
    novoNodo->prox = NULL;
    novoNodo->ant = NULL;
    novoNodo->data = num;
    return novoNodo;
}

NODO * criarLista(int size){
    NODO * head; head = criarNodo(1);
    int i=1;
    while(i<size){
        i++;
        NODO * aux;
        aux = criarNodo(i);
        head->ant = aux;
        aux->prox = head;
        head = aux;
    }
    return head;
}
void imprimirLista(NODO * head){
    NODO * printarNodo;
    printarNodo = head;
    while(printarNodo != NULL){
        printf("%d:", printarNodo->data);
        printarNodo = printarNodo->prox;
    }
}

int imprimirRecursaoInverso(NODO * head){
    NODO * aux;
    aux = head;
    if(aux==NULL){
        return 0;
    }
    imprimirRecursaoInverso(aux->prox);
    printf("%d:", aux->data);
    return 0;
}

int imprimirRecursao(NODO * head){
    NODO * aux;
    aux = head;
    if(aux==NULL){
        return 0;
    }
    printf("%d:", aux->data);
    imprimirRecursao(aux->prox);
    return 0;
}

void apagarLista(NODO * head){
    NODO * aux;
    aux = head;
    while(head->prox != NULL){
        aux = head->prox;
        head->prox = head->prox->prox;
        free(aux);
    }
    free(head);
}

NODO * busca(NODO * head, int index){
    NODO * buscador;
    buscador = head;
    int i=0;
    while(buscador != NULL){
        if(i == index-1){
            return buscador;
        }else{
        buscador = buscador->prox;
        i++;}
    }
    return buscador;
}

NODO * insereInicio(NODO * head, int cont){
    NODO* novoNodo;
    novoNodo = criarNodo(cont);
    novoNodo->prox = head;
    head->ant = novoNodo;
    head = novoNodo;
    return head;
}

NODO * insereFinal(NODO * head, int conteudo){
    NODO * aux, * nodofim;
    if (head == NULL){
        head = criarNodo(conteudo);
    }else{
        aux = head;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        nodofim = criarNodo(conteudo);
        aux->prox = nodofim;
        nodofim->ant = aux;
    }
    return head;
}

void removerNodo(NODO * head, int conteudo){
    NODO * aux; aux = head;
    if(head == NULL){
        printf("\nLista Vazia");
    }else{
        while(aux-> prox != NULL){
            aux = aux->prox;
            if (aux->data == conteudo && aux->prox != NULL && aux->ant != NULL){
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                printf("\nNodo [%d] removido\n", aux->data);
                free(aux);
                break;
            }else if (aux->data == conteudo && aux->prox  == NULL){
                aux->ant->prox = NULL;
                printf("\Nodo [%d] removido\n", aux->data);
                free(aux);
                break;
            }else if(aux->data == conteudo && aux->ant == NULL){
                aux->prox->ant = NULL;
                printf("\nNodo [%d] removido\n", aux->data);
                free(aux);
            }
        }
        if(aux->prox == NULL){
            printf("\nNao encontrado.\n");
        }
    }
}


int main(){
    NODO * nodoTeste;
    nodoTeste = criarLista(10);
    printf("Imprimindo com while simples:\n");
    imprimirLista(nodoTeste);
    printf("\nImprimindo com recursao \n");
    imprimirRecursao(nodoTeste);
    printf("\nImprimindo com recursao inversa:\n");
    imprimirRecursaoInverso(nodoTeste);

    nodoTeste = insereInicio(nodoTeste, 999);
    printf("\nTeste da insereInicio: \n");
    imprimirLista(nodoTeste);

    nodoTeste = insereFinal(nodoTeste, 111);
    printf("\nTeste inserirFinal: \n");
    imprimirLista(nodoTeste);

    printf("\n\nTeste da removerNodo(lista, 111)\n");
    removerNodo(nodoTeste, 111);
    imprimirLista(nodoTeste);


    printf("\n Teste da removerNodo(lista, 4)\n");
    removerNodo(nodoTeste, 4);
    imprimirLista(nodoTeste);




    printf("\n Teste da removerNodo(lista, 23) invalido\n");
    removerNodo(nodoTeste, 23);
    imprimirLista(nodoTeste);
    apagarLista(nodoTeste);

    return 0;
}

