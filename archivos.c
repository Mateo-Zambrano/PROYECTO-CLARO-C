#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"



void guardarClientes() {
    FILE *f = fopen("clientes.dat", "wb");
    if (f == NULL) {
        printf("Error al guardar clientes\n");
        return;
    }

    fwrite(&totalClientes, sizeof(int), 1, f);
    fwrite(clientes, sizeof(struct Cliente), totalClientes, f);

    fclose(f);
}



void cargarClientes() {
    FILE *f = fopen("clientes.dat", "rb");
    if (f == NULL) return;

    fread(&totalClientes, sizeof(int), 1, f);
    fread(clientes, sizeof(struct Cliente), totalClientes, f);

    fclose(f);
}



void guardarLineas() {
    FILE *f = fopen("lineas.dat", "wb");
    if (f == NULL) {
        printf("Error al guardar lineas\n");
        return;
    }

    fwrite(&totalLineas, sizeof(int), 1, f);
    fwrite(lineas, sizeof(struct Linea), totalLineas, f);

    fclose(f);
}



void cargarLineas() {
    FILE *f = fopen("lineas.dat", "rb");
    if (f == NULL) return;

    fread(&totalLineas, sizeof(int), 1, f);
    fread(lineas, sizeof(struct Linea), totalLineas, f);

    fclose(f);
}



void guardarFacturas() {
    FILE *f = fopen("facturas.dat", "wb");
    if (f == NULL) {
        printf("Error al guardar facturas\n");
        return;
    }

    fwrite(&totalFacturas, sizeof(int), 1, f);
    fwrite(facturas, sizeof(struct Factura), totalFacturas, f);

    fclose(f);
}



void cargarFacturas() {
    FILE *f = fopen("facturas.dat", "rb");
    if (f == NULL) return;

    fread(&totalFacturas, sizeof(int), 1, f);
    fread(facturas, sizeof(struct Factura), totalFacturas, f);

    fclose(f);
}

