
void concatenarListaFila(NODO ** lista, NODO **comecoFila, NODO ** fimFila){
    NODO * fimLista;
    fimLista = *lista;
    while(fimLista->prox != NULL){
        fimLista = fimLista->prox;
    }
    fimLista->prox = *comecoFila;
}

