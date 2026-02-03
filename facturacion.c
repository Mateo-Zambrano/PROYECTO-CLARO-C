#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "facturacion.h"

void menuFacturacion() {

    int op;

    do {
        system("cls");
        printf("------ MENU FACTURACION ------\n");
        printf("1. Generar Factura\n");
        printf("2. Listar Facturas\n");
        printf("3. Reporte Mensual\n");
        printf("0. Volver\n");
        printf("Seleccione: ");
        scanf("%d", &op);

        switch(op) {
            case 1: generarFactura(); break;
            case 2: listarFacturas(); break;
            case 3: reporteMensual(); break;
        }

    } while(op != 0);
}

void generarFactura() {

    if(totalFacturas >= MAX){
        printf("Limite de facturas alcanzado\n");
        system("pause");
        return;
    }

    int id;
    float total = 0;

    printf("ID Cliente: ");
    scanf("%d",&id);

    for(int i=0;i<totalLineas;i++){
        if(lineas[i].idCliente == id){
            total += lineas[i].costo;
        }
    }

    facturas[totalFacturas].idFactura = totalFacturas + 1;
    facturas[totalFacturas].idCliente = id;
    facturas[totalFacturas].total = total;

    printf("Fecha (dd/mm): ");
    scanf("%s",facturas[totalFacturas].fecha);

    totalFacturas++;

    printf("Total a pagar: %.2f\n",total);
    system("pause");
}

void listarFacturas() {

    for(int i=0;i<totalFacturas;i++){
        printf("Factura:%d Cliente:%d Total:%.2f Fecha:%s\n",
               facturas[i].idFactura,
               facturas[i].idCliente,
               facturas[i].total,
               facturas[i].fecha);
    }

    system("pause");
}

void reporteMensual() {

    float totalGeneral = 0;

    for(int i=0;i<totalFacturas;i++){
        totalGeneral += facturas[i].total;
    }

    printf("Total facturado general: %.2f\n", totalGeneral);

    system("pause");
}

