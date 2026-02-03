#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "lineas.h"

void menuLineas() {

    int op;

    do {
        system("cls");
        printf("------ MENU LINEAS ------\n");
        printf("1. Registrar\n");
        printf("2. Listar\n");
        printf("3. Buscar por Numero\n");
        printf("4. Ordenar por Costo\n");
        printf("0. Volver\n");
        printf("Seleccione: ");
        scanf("%d", &op);

        switch(op) {
            case 1: registrarLinea(); break;
            case 2: listarLineas(); break;
            case 3: buscarLineaNumero(); break;
            case 4: ordenarLineasCosto(); break;
        }

    } while(op != 0);
}

void registrarLinea() {

    if(totalLineas >= MAX){
        printf("Limite alcanzado\n");
        system("pause");
        return;
    }

    printf("ID Linea: ");
    scanf("%d",&lineas[totalLineas].idLinea);

    printf("ID Cliente: ");
    scanf("%d",&lineas[totalLineas].idCliente);

    printf("Numero: ");
    scanf(" %[^\n]",lineas[totalLineas].numero);

    printf("Costo: ");
    scanf("%f",&lineas[totalLineas].costo);

    totalLineas++;

    printf("Linea registrada correctamente\n");
    system("pause");
}

void listarLineas() {

    for(int i=0;i<totalLineas;i++){
        printf("ID:%d Cliente:%d Numero:%s Costo:%.2f\n",
               lineas[i].idLinea,
               lineas[i].idCliente,
               lineas[i].numero,
               lineas[i].costo);
    }

    system("pause");
}

void buscarLineaNumero() {

    char num[20];
    int encontrado = 0;

    printf("Numero: ");
    scanf(" %[^\n]",num);

    for(int i=0;i<totalLineas;i++){
        if(strcmp(lineas[i].numero,num)==0){
            printf("ID Linea:%d Cliente:%d Costo:%.2f\n",
                   lineas[i].idLinea,
                   lineas[i].idCliente,
                   lineas[i].costo);
            encontrado = 1;
        }
    }

    if(!encontrado)
        printf("No encontrada\n");

    system("pause");
}

void ordenarLineasCosto() {

    struct Linea temp;

    for(int i=0;i<totalLineas-1;i++){
        for(int j=0;j<totalLineas-1;j++){
            if(lineas[j].costo > lineas[j+1].costo){
                temp = lineas[j];
                lineas[j] = lineas[j+1];
                lineas[j+1] = temp;
            }
        }
    }

    printf("Ordenado por costo\n");
    system("pause");
}

