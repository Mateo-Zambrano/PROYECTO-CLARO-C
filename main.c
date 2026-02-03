#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "clientes.h"
#include "lineas.h"
#include "facturacion.h"
#include "archivos.h"


struct Cliente clientes[MAX];
struct Linea lineas[MAX];
struct Factura facturas[MAX];

int totalClientes = 0;
int totalLineas = 0;
int totalFacturas = 0;


void menuPrincipal();


int main() {

    
    cargarClientes();
    cargarLineas();
    cargarFacturas();

    menuPrincipal();

    
    guardarClientes();
    guardarLineas();
    guardarFacturas();

    printf("\nDatos guardados correctamente.\n");
    system("pause");
    return 0;
}


void menuPrincipal() {
    int opcion;

    do {
        system("cls");
        printf("CLARO\n\n");
        printf("1. Gestion de Clientes\n");
        printf("2. Gestion de Lineas\n");
        printf("3. Facturacion\n");
        printf("0. Salir\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuLineas();
                break;
            case 3:
                menuFacturacion();
                break;
            case 0:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida\n");
                system("pause");
        }

    } while(opcion != 0);
}

