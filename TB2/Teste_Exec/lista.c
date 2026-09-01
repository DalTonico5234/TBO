#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include "lista.h" 

 struct celula {
    void *item; 
    Celula *ant; 
    Celula *prox; 
};

struct lista{
    Celula *prim; 
    Celula *ult; 
};

Celula *getPrimLista(Lista *l){ 
    return l->prim; 
}

Celula *getProxCel(Celula *p){ 
    return p->prox; 
}

void *getItemCelula(Celula *p){ 
    return p->item; 
}

Lista* inicializaLista(){ 
    
    Lista *l = (Lista *) malloc (sizeof(Lista)); 

    l->prim = NULL; 
    l->ult = NULL; 

    return l; 
}

Lista* insereFinalLista(void *item, Lista *l){ 

    Celula *c = (Celula *) malloc (sizeof(Celula)); 

    c->item = item; 
    c->ant = NULL; 
    c->prox = NULL; 
    if(l->prim == NULL && l->ult == NULL){ 
        l->prim = c; 
        l->ult = c; 
    } 
    else{ 
        c->ant = l->ult; 
        l->ult->prox = c; 
        l->ult = c; 
    }
    return l; 
}

void imprimeLista(Lista *l, ImprimeItem fImpressao) { 

    Celula *current; 

    current = l->prim; 

    while(1){ 
        if(current == NULL){ 
            break; 
        }
        fImpressao(current->item);
        current = current->prox; 
    }
    
}

void liberaLista(void *list){
    Lista *l = (Lista *) list;

    Celula *current = l->prim; 
    Celula *next; 
    while (current != NULL) { 
        next = current->prox; 
        free(current);      // Libera a Célula
        current = next;     
    }
    free(l);
}

void liberaCelulas(Lista *l){

    if (l == NULL) return; 
    Celula *current = l->prim; 
    Celula *next; 

    while (current != NULL) { 
        next = current->prox; 
        free(current);
        current = next; 
    }

    // Após liberar todas as células, garanta que a lista esteja vazia.
    l->prim = NULL; 
    l->ult = NULL; 
}

void *removeInicioLista(Lista *l) {

    if(l == NULL || l->prim == NULL){ 
        return NULL; 
    }

    Celula *primeiraCelula = l->prim; 
    void *itemRemovido = primeiraCelula->item; 

    l->prim = primeiraCelula->prox;

    if(l->prim != NULL){ 
        l->prim->ant = NULL; 
    } 
    else{
        l->ult = NULL; 
    }
 
    free(primeiraCelula);

    return itemRemovido; 
}

int getTamLista(Lista *l){

    int tam = 0;
    Celula *p = l->prim;

    while(p != NULL){
        tam++;
        p = p->prox;
    }
    return tam;
}

int estaNaLista(Lista *l, void *item){

    Celula *p = l->prim;

    while(p != NULL){
        if(getItemCelula(p) == item){
            return 1;
        }
        p = p->prox;
    }
    return 0;
}
