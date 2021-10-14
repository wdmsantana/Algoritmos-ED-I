NODO * resultadoQuestao(NODO **lista){
    NODO * i, *j, *listaPares, *listaImpares, * listaAux; int numeroAux;
    listaAux = criarNodo((*lista)->data ) ;
    i = (*lista)->prox;
    //Uma copia da lista original
    while(i != NULL){
        NODO * novoNodo = criarNodo(i->data);
        novoNodo->prox = listaAux;
        listaAux = novoNodo;
        i = i->prox;
    }

    i = listaAux; listaPares=NULL; listaImpares=NULL;
   //popular lista de pares//
   while(i != NULL){
        if(i->data %2 == 0){
            NODO * aux2;
            aux2 = criarNodo(i->data);
            aux2->prox = listaPares;
            listaPares = aux2;
        }
        i= i->prox;
    }
    i = j = listaPares;
    //Organizar em ordem decrescente para facilitar;
    while(i != NULL){
        while(j != NULL){
            if(i->data > j->data){
                numeroAux = i->data;
                i->data = j->data;
                j->data = numeroAux;
            }
            j = j->prox;
        }
        j = listaPares;
        i = i->prox;
    }
    //Popular a lista de impares maiores que o maior par;
    i = listaAux;
    while(i != NULL){
        if((i->data %2) != 0 && (i->data > listaPares->data)){
            NODO * aux;
            aux = criarNodo(i->data);
            aux->prox = listaImpares;
            listaImpares = aux;
        }
        i= i->prox;
    }
    i = j = listaImpares;
    //Organizar em ordem decrescente para facilitar;
    while(i != NULL){
        while(j != NULL){
            if(i->data > j->data){
                numeroAux = i->data;
                i->data = j->data;
                j->data = numeroAux;
            }
            j = j->prox;
        }
        j = listaImpares;
        i = i->prox;
    }
    //apaga a lista copia (listaAux)
    apagarLista(listaAux);
    //concatena  ultimo nodo da listaPares com o listImpares
    i = listaPares;
    while(i->prox != 0){
            i = i->prox;
    }
    i->prox = listaImpares;

    return listaPares;
}
