//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct nodo{
//    int numero;
//    struct nodo * prox;
//} NODO;
//
//NODO * criarNodo(int conteudo){
//    NODO * temp;
//    temp = (NODO*)malloc(sizeof(NODO));
//    temp->numero = conteudo;
//    temp->prox = NULL;
//
//    return temp;
//}
//
//void inQueue(NODO ** fila, NODO ** fim, int conteudo){
//    NODO * temp;
//    temp = criarNodo(conteudo);
//    if(*fila == NULL){
//        *fila = *fim = temp;
//    }else{
//        (*fim)->prox = temp;
//        *fim = temp;
//    }
//}
//
//int dequeue(NODO ** fila){
//    int conteudo;
//    if(*fila == NULL){
//        printf("\nFila vazia");
//        return 0;
//    }else{
//        NODO * aux;
//        aux = * fila;
//        *fila = (*fila)->prox;
//        conteudo = aux->numero;
//    }
//    return conteudo;
//}
//
//void imprimirFilaWhile(NODO ** fila){
//    NODO * aux; aux = *fila;
//    if(*fila == NULL){
//        printf("\nLista vazia.");
//    }else{
//        while(aux != NULL){
//            printf("%d- ", aux->numero);
//            aux = aux->prox;
//        }
//    }
//}
//
//void ordernarDecrescenteFila(NODO ** fila){
//    NODO * i, *j; int numeroAux;
//    i = j = *fila;
//    while(i != NULL){
//        while(j != NULL){
//            if(i->numero > j->numero){
//                numeroAux = i->numero;
//                i->numero = j->numero;
//                j->numero = numeroAux;
//            }
//            j = j->prox;
//        }
//        j = *fila;
//        i = i->prox;
//    }
//}
//
//
//void ordernarCrescenteFila(NODO ** fila){
//    NODO * i, *j; int numeroAux;
//    i = j = *fila;
//    while(i != NULL){
//        while(j != NULL){
//            if(i->numero < j->numero){
//                numeroAux = i->numero;
//                i->numero = j->numero;
//                j->numero = numeroAux;
//            }
//            j = j->prox;
//        }
//        j = *fila;
//        i = i->prox;
//    }
//}
//
//void limpaFila(NODO ** fila){
//    while(*fila != NULL){
//        dequeue(fila);
//    }
//}
//
//int main(){
//    NODO * fila, * fim;
//    fila = fim = NULL;
//    inQueue(&fila, &fim, 1);
//    inQueue(&fila, &fim, 2);
//    inQueue(&fila, &fim, 3);
//    inQueue(&fila, &fim, 4);
//    inQueue(&fila, &fim, 77);
//    inQueue(&fila, &fim, 75);
//    inQueue(&fila, &fim, 55);
//
//
//    printf("\n Elemento inical da fila = %d", fila->numero);
//
//    printf("\nImprimndo a fila\n");
//    imprimirFilaWhile(&fila);
//
//    printf("\nOrdernar os valores da fila decrescente\n");
//    ordernarDecrescenteFila(&fila);
//    imprimirFilaWhile(&fila);
//
//    printf("\nOrdenem crescente da fila > ");
//    ordernarCrescenteFila(&fila);
//    imprimirFilaWhile(&fila);
//
//    limpaFila(&fila);
//
//    imprimirFilaWhile(&fila);
//    return 0;
//}
