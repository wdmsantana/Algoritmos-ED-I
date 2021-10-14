#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    int number;
    struct  nodo * next;
}NODO;

int main(){
    NODO * head, * tail;
    head = malloc(sizeof(NODO));
    tail = head;
    head->next = tail; tail->next = head;
    tail->number = 40;
    int i=39;
    while(i>0){
        NODO * aux;
        aux=(NODO*)malloc(sizeof(NODO));
        aux->next = head;
        aux->number = i;
        head = aux;
        tail->next = head;
        i--;
     }


    //remove nodo
    NODO * pointerRemover, * pointerRemoverAux;
    int contador = 1;
    pointerRemover=head;
    while(pointerRemover->next != pointerRemover){
        if (contador == 2){
            contador=0;
            pointerRemoverAux = pointerRemover->next;
            pointerRemover->next = pointerRemover->next->next;
            printf("\nNODO[%d] removido", pointerRemoverAux->number);
            free(pointerRemoverAux);
        }
        pointerRemover = pointerRemover->next;
        contador++;
    }
    printf("\nJosephus esta em = %d", pointerRemover->number);

    return 0;
}
