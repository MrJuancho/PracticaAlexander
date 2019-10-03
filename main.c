#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    FILE *Fout;
    Evento* lista = NULL;
    int *numeros= NULL, i=1, index, e=0, apex = 0;
    char m,principal;
    char *nombre_out = "Salon.txt";

    do{
        fflush(stdin);
        puts("1 >> Modificar Eventos.\n"
             "2 >> Ordenar Eventos leidos.\n"
             "3 >> Mostrar la lista Final y Guardar Eventos en Archivo.\n"
             "4 >> Eliminar todos los eventos.\n"
             "0 >> Salir.\n");
        scanf(" %c",&principal);
        fflush(stdin);
        switch (principal){
            case '1':
                do{
                    fflush(stdin);
                    puts("Elige una opcion:\n"
                         "1 -- Alta de Eventos.\n"
                         "2 -- Baja de Eventos.\n"
                         "3 -- Ver Eventos actuales\n"
                         "0 -- Salir.");
                    scanf(" %c",&m);
                    fflush(stdin);
                    switch (m) {
                        case ('1'):
                            char m_1;
                            char desc_r[50];
                            do{
                                fflush(stdin);
                                puts("Elige una opcion:\n"
                                     "1 -- Alta de Eventos al Inicio.\n"
                                     "2 -- Alta de datos por ID.\n"
                                     "3 -- Alta de datos al Final.\n"
                                     "0 -- Regresar.");
                                scanf(" %c",&m_1);
                                fflush(stdin);
                                switch (m_1) {
                                    case('1'):
                                        int diai,mesi,yri;
                                        puts("Antes que nada, ingresa la fecha del evento:");
                                        printf("Dia:");
                                        scanf(" %d",&diai);
                                        printf("Mes:");
                                        scanf(" %d",&mesi);
                                        printf("Anio:");
                                        scanf(" %d",&yri);
                                        fflush(stdin);
                                        printf("Ahora ingresa la descripcion del evento:");
                                        scanf(" %[^\n]%*c", desc_r);
                                        lista = Alta_Inicial(e,diai,mesi,yri,desc_r,lista);
                                        if(e == 1){
                                            apex = 1;
                                        }
                                        e++;
                                        break;
                                    case ('2'):
                                        int diaid,mesid,yrid;
                                        puts("Antes que nada, ingresa la fecha del evento:");
                                        printf("Dia:");
                                        scanf(" %d",&diaid);
                                        printf("Mes:");
                                        scanf(" %d",&mesid);
                                        printf("Anio:");
                                        scanf(" %d",&yrid);
                                        char desc_id[50];
                                        fflush(stdin);
                                        printf("Ahora ingresa la descripcion del evento:");
                                        scanf(" %[^\n]%*c", desc_id);
                                        puts("Ingresa el Id para dar de Alta");
                                        int size = Contador(lista);
                                        int id_alta;
                                        scanf(" %d",&id_alta);
                                        if(id_alta==1){
                                            lista=Alta_Inicial(e,diaid,mesid,yrid,desc_id,lista);
                                        }else if(id_alta==size){
                                            lista = Alta_Final(e,diaid,mesid,yrid,desc_id,lista);
                                        }else{
                                            lista = Alta_ID(lista,e,diaid,mesid,yrid,desc_id,id_alta);
                                        }
                                        if(e == 1){
                                            apex = 1;
                                        }
                                        e++;
                                        break;
                                    case ('3'):
                                        int diaf,mesf,yrf;
                                        puts("Antes que nada, ingresa la fecha del evento:");
                                        printf("Dia:");
                                        scanf(" %d",&diaf);
                                        printf("Mes:");
                                        scanf(" %d",&mesf);
                                        printf("Anio:");
                                        scanf(" %d",&yrf);
                                        char desc_f[50];
                                        fflush(stdin);
                                        printf("Ahora ingresa la descripcion del evento:");
                                        scanf(" %[^\n]%*c", desc_f);
                                        fflush(stdin);
                                        lista = Alta_Final(e,diaf,mesf,yrf,desc_f,lista);
                                        if(e == 1){
                                            apex = 1;
                                        }
                                        e++;
                                        break;
                                    case ('0'):
                                        break;
                                    default:
                                        puts("Ingresa una opcion viable");
                                        break;
                                }
                                fflush(stdin);
                            }while(m_1 != '0');
                            break;
                        case ('2'):
                            char m_2;
                            do{
                                fflush(stdin);
                                puts("Elige una opcion:\n"
                                     "1 -- Baja de Eventos al Inicio.\n"
                                     "2 -- Baja de datos por ID.\n"
                                     "3 -- Baja de datos al Final.\n"
                                     "0 -- Regresar.");
                                scanf(" %c",&m_2);
                                fflush(stdin);
                                switch (m_2) {
                                    case('1'):
                                        lista = Baja_Inicial(lista);
                                        if(e == 1){
                                            apex = 1;
                                        }
                                        break;
                                    case ('2'):
                                        puts("Ingresa el Id para dar de Baja");
                                        int size = Contador(lista);
                                        int id_baja;
                                        scanf("%d",&id_baja);
                                        if(id_baja==1){
                                            lista=Baja_Inicial(lista);
                                        }else if(id_baja==size){
                                            lista = Baja_Final(lista);
                                        }else{
                                            lista = Baja_ID(lista,id_baja);
                                        }
                                        if(e == 1){
                                            apex = 1;
                                        }
                                        break;
                                    case ('3'):
                                        lista = Baja_Final(lista);
                                        if(e == 1){
                                            apex = 1;
                                        }
                                        break;
                                    case ('0'):
                                        break;
                                    default:
                                        puts("Ingresa una opcion viable");
                                        break;
                                }
                                fflush(stdin);
                            }while(m_2 != '0');
                            break;
                        case ('3'):
                            Mostrar_Datos(lista);
                        case ('0'):
                            puts("Regresando al menu principal...");
                            break;
                        default:
                            puts("Ingresa una opcion viable");
                            break;
                    }
                    fflush(stdin);
                }while(m != '0');
                break;
            case '2':
                int size = Contador(lista)/sizeof(Evento);
                qsort(lista,size,sizeof *lista,comparar_fechas);
                e = 1;
                puts("Ordenado");
                break;
            case '3':
                Evento *lista_aux = lista;
                if(e > 0){
                    char m_10;
                    do {
                        puts("Como quieres ver tus datos:");
                        puts("1 >> Completos");
                        puts("2 >> Recorrido");
                        puts("3 >> Guardar en Archivo");
                        puts("0 >> Cancelar");
                        scanf(" %c", &m_10);
                        switch (m_10) {
                            case '1':
                                Mostrar_Datos(lista_aux);
                                break;
                            case '2':
                                Mostrar_Datos_OVO(lista_aux);
                                break;
                            case '3':
                                if((Fout = fopen(nombre_out,"wt")) == NULL){
                                    puts("No se pueden abrir los archivos, intenta de nuevo");
                                    return 1;
                                }else{
                                    Fout = fopen(nombre_out,"wt");
                                }
                                while(lista_aux != NULL){
                                    fprintf(Fout,"ID: %d >> Fecha: %d/%d/%d >> Descripcion: %s.\n",lista_aux->id, lista_aux->dia,lista_aux->mes,lista_aux->yr,lista_aux->descripcion);
                                    lista_aux = lista_aux->sig;
                                }
                                m_10='0';
                                break;
                        }
                    } while (m_10 != '0');
                }else{
                    puts("Todavia no tienes la lista ordenada...");
                    break;
                }
                break;
            case '4':
                fflush(stdin);
                puts("Estas a punto de reiniciar el proceso...\n"
                     "Deseas Continuar?(Y/N)\n");
                char desicion;
                scanf(" %c",&desicion);
                if (desicion == 'Y'){
                    lista = NULL;
                    e=0;
                }else{
                    puts("Se cancelo el proceso.");
                    break;
                }
                break;
            case '0':
                puts("Hasta Luego...");
                break;
            default:
                puts("Selecciona una opcion listada");
                break;
        }
    }while(principal!= '0');

    fclose(Fout);
    numeros = NULL;
}