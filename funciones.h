#ifndef PRACTICAALEXANDER_FUNCIONES_H
#define PRACTICAALEXANDER_FUNCIONES_H

#include <assert.h>
#include <string.h>

typedef struct _Nodo{
    int id;
    int dia;
    int mes;
    int yr;
    char descripcion[50];
    struct _Nodo *sig;
    struct _Nodo *ant;
}Evento;

int Contador(Evento* a){
    int i = 0;
    if(a != NULL) {
        while (a->sig != NULL) {
            a = a->sig;
            i++;
        }
    }
    return i;
}

void Mostrar_Datos(Evento *lista){
    if(lista != NULL){
        int i = 0;
        while (lista != NULL){
            printf("Id: %d ; Fecha: %d/%d/%d\n"
                   "Descripcion: %s\n",lista->id,lista->dia,lista->mes,lista->yr,lista->descripcion);
            lista = lista -> sig;
            i++;
        }
        printf("La lista tiene %d datos\n", i);
    }else{
        puts("Tu Lista esta vacia\n");
    }
}

void Mostrar_Datos_OVO(Evento *lista){
    int j = Contador(lista);
    int a = 1;
    char mov;
    puts("Ahorita estas en:");
    printf("Id: %d ; Fecha: %d/%d/%d\n"
           "Descripcion: %s\n",lista->id,lista->dia,lista->mes,lista->yr,lista->descripcion);
    printf("Size: %d\n",j);
    do{
        if (a <= 0 || a > j){
            puts("Se te Acabo el Array");
            break;
        }
        puts("Presiona '>' o '<' para moverte a traves de la lista.Puedes presionar 0 para regresar");
        scanf(" %c",&mov);
        switch (mov){
            case '>':
                a++;
                lista = lista->sig;
                printf("Id: %d ; Fecha: %d/%d/%d\n"
                       "Descripcion: %s\n",lista->id,lista->dia,lista->mes,lista->yr,lista->descripcion);
                break;
            case '<':
                a--;
                if(a <= 0) break;
                lista = lista ->ant;
                printf("Id: %d ; Fecha: %d/%d/%d\n"
                       "Descripcion: %s\n",lista->id,lista->dia,lista->mes,lista->yr,lista->descripcion);
                break;
            case '0':
                puts("Regresando...");
                break;
            default:
                puts("no me quieras tracalear...");
                break;
        }
    }while(mov != '0');
}

Evento* allocateMem(int id, int dia,int mes,int yr,char descripcion[50]){
    Evento* dummy;
    dummy = (Evento*)malloc(sizeof(Evento));
    dummy -> id = id;
    dummy -> dia = dia;
    dummy -> mes = mes;
    dummy -> yr = yr;
    strcpy(dummy->descripcion, descripcion);
    dummy -> sig = NULL;
    dummy -> ant = NULL;
    return dummy;
}

Evento* Alta_Final(int id, int dia,int mes,int yr, char descripcion[50], Evento* frente){
    Evento *box,*aux;
    box = allocateMem(id,dia,mes,yr,descripcion);
    if(frente == NULL){
        return box;
    }else{
        aux = frente;
        while(aux -> sig!=NULL){
            aux = aux -> sig;
        }
        aux -> sig = box;
        box -> ant = aux;
    }
    return frente;
}

Evento* Alta_Inicial(int id, int dia, int mes, int yr,char descripcion[50], Evento* cima){
    Evento* box;
    box = allocateMem(id,dia,mes,yr,descripcion);
    if(cima != NULL){
        box -> sig = cima;
        cima -> ant = box;
    }
    cima = box;
    if(cima != NULL) {
        puts("=====Agregado=====");
    }
    return cima;
}

Evento* Alta_ID(Evento *fila, int id,int dia,int mes,int yr,char *descripcion, int pos){
    Evento *aux, *nuevo;
    int size,i;
    nuevo = allocateMem(id,dia,mes,yr,descripcion);
    if (fila == NULL){
        return nuevo;
    }else{
        aux = fila;
        size = Contador(fila);
        if (pos < 0 || pos > size) {
            puts("Error en el numero de la posicion introducida");

            return nuevo;
        }
        for (i = 0; i < pos ; i++) {
            aux = aux -> sig;
        }
        nuevo -> sig = aux -> sig;
        nuevo -> ant = aux;
        aux -> sig = nuevo;
        nuevo -> sig -> ant = nuevo;
    }
    return fila;
}

Evento *Baja_Inicial(Evento* cima){
    Evento* aux;
    int size = Contador(cima);
    if(cima == NULL){
        puts("Tu Lista no tiene datos");
    }else if(size <= 1){
        free(cima);
        return NULL;
    }
    if(cima != NULL){
        aux = cima;
        cima = aux -> sig;
        cima -> ant = NULL;
        free(aux);
    }
    return cima;
}

Evento *Baja_Final(Evento *cima){
    int size = Contador(cima);
    Evento *aux;
    if(cima == NULL){
        return cima;
    }else{
        aux=cima;
        if(size != 1){
            aux = cima;
            int j;
            for (j = 0; j < (size-1) ; ++j) {
                aux = aux->sig;
            }
            free(aux->sig);
            aux->sig = NULL;
        }else{
            free(cima);
        }
    }
    return cima;
}

Evento *Baja_ID(Evento *fila, int pos){
    Evento *aux, *borrar;
    int size;
    size = Contador(fila);
    if (fila == NULL){
        puts("No hay datos en tu fila, intenta de nuevo");
    }else{
        if(pos>size||pos<0)
        {
            puts("Error en el numero de la posicion introducida");
            return aux;
        }
        aux = fila;
        for (int i = 0; i < pos ; ++i) {
            aux = aux -> sig;
        }
        borrar = aux->sig;
        aux->sig = borrar->sig;
        borrar -> sig -> ant = aux;
        free(borrar);
    }
    return fila;
}


static int comparar_fechas(const void *p, const void *q) {
    Evento *x = (Evento *)p, *y = (Evento *)q;
    assert(p && q);
    if(x->yr > y->yr) return 1;
    if(x->yr < y->yr) return -1;
    if(x->mes  > y->mes)  return 1;
    if(x->mes  < y->mes)  return -1;
    if(x->dia  > y->dia)  return 1;
    if(x->dia  < y->dia)  return -1;
    return 0;
}

static const char *print_date(Evento * date) {
    static char print[128]; /* Should be 11 if -999 <= year < 9999. */
    assert(date);
    sprintf(print, "%d-%d-%d", date->yr, date->mes, date->dia);
    return print;
}



#endif //PRACTICAALEXANDER_FUNCIONES_H
