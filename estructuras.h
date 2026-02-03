#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define MAX 100



struct Cliente {
    int id;
    char nombre[50];
    char telefono[20];
    char correo[50];
    int tipo;
};

struct Linea {
    int idLinea;
    int idCliente;
    char numero[20];
    float costo;
};

struct Factura {
    int idFactura;
    int idCliente;
    float total;
    char fecha[15];
};



extern struct Cliente clientes[MAX];
extern struct Linea lineas[MAX];
extern struct Factura facturas[MAX];

extern int totalClientes;
extern int totalLineas;
extern int totalFacturas;

#endif

