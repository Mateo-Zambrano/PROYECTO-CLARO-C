#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"
#include "clientes.h"

void menuClientes() {

    int op;

    do {
        system("cls");
        printf("------ MENU CLIENTES ------\n");
        printf("1. Registrar\n");
        printf("2. Listar\n");
        printf("3. Buscar por ID\n");
        printf("4. Buscar por Nombre\n");
        printf("5. Eliminar\n");
        printf("6. Ordenar por ID\n");
        printf("7. Ordenar por Nombre\n");
        printf("0. Volver\n");
        printf("Seleccione: ");
        scanf("%d", &op);

        switch(op) {
            case 1: registrarCliente(); break;
            case 2: listarClientes(); break;
            case 3: buscarClienteID(); break;
            case 4: buscarClienteNombre(); break;
            case 5: eliminarCliente(); break;
            case 6: ordenarClientesID(); break;
            case 7: ordenarClientesNombre(); break;
        }

    } while(op != 0);
}

void registrarCliente() {

    if(totalClientes >= MAX){
        printf("Limite alcanzado\n");
        system("pause");
        return;
    }

    printf("ID: ");
    scanf("%d",&clientes[totalClientes].id);

    printf("Nombre: ");
    scanf(" %[^\n]",clientes[totalClientes].nombre);

    printf("Telefono: ");
    scanf(" %[^\n]",clientes[totalClientes].telefono);

    printf("Correo: ");
    scanf(" %[^\n]",clientes[totalClientes].correo);

    printf("Tipo (1 Normal - 2 VIP): ");
    scanf("%d",&clientes[totalClientes].tipo);

    totalClientes++;
    printf("Registrado correctamente\n");
    system("pause");
}

void listarClientes() {

    for(int i=0;i<totalClientes;i++){
        printf("ID:%d Nombre:%s Telefono:%s Correo:%s Tipo:%s\n",
               clientes[i].id,
               clientes[i].nombre,
               clientes[i].telefono,
               clientes[i].correo,
               clientes[i].tipo==1?"Normal":"VIP");
    }

    system("pause");
}

void buscarClienteID() {

    int id, encontrado=0;
    printf("Ingrese ID: ");
    scanf("%d",&id);

    for(int i=0;i<totalClientes;i++){
        if(clientes[i].id==id){
            printf("Nombre:%s Telefono:%s Correo:%s Tipo:%s\n",
                   clientes[i].nombre,
                   clientes[i].telefono,
                   clientes[i].correo,
                   clientes[i].tipo==1?"Normal":"VIP");
            encontrado=1;
        }
    }

    if(!encontrado)
        printf("Cliente no encontrado\n");

    system("pause");
}

void buscarClienteNombre() {

    char nombre[50];
    int encontrado=0;

    printf("Ingrese Nombre: ");
    scanf(" %[^\n]",nombre);

    for(int i=0;i<totalClientes;i++){
        if(strcmp(clientes[i].nombre,nombre)==0){
            printf("ID:%d Telefono:%s Correo:%s Tipo:%s\n",
                   clientes[i].id,
                   clientes[i].telefono,
                   clientes[i].correo,
                   clientes[i].tipo==1?"Normal":"VIP");
            encontrado=1;
        }
    }

    if(!encontrado)
        printf("Cliente no encontrado\n");

    system("pause");
}

void eliminarCliente() {

    int id;
    printf("ID eliminar: ");
    scanf("%d",&id);

    for(int i=0;i<totalClientes;i++){
        if(clientes[i].id==id){
            for(int j=i;j<totalClientes-1;j++){
                clientes[j]=clientes[j+1];
            }
            totalClientes--;
            printf("Cliente eliminado\n");
            system("pause");
            return;
        }
    }

    printf("Cliente no encontrado\n");
    system("pause");
}

void ordenarClientesID() {

    struct Cliente temp;

    for(int i=0;i<totalClientes-1;i++){
        for(int j=0;j<totalClientes-1;j++){
            if(clientes[j].id>clientes[j+1].id){
                temp=clientes[j];
                clientes[j]=clientes[j+1];
                clientes[j+1]=temp;
            }
        }
    }

    printf("Ordenado por ID\n");
    system("pause");
}

void ordenarClientesNombre() {

    struct Cliente temp;

    for(int i=0;i<totalClientes-1;i++){
        for(int j=0;j<totalClientes-1;j++){
            if(strcmp(clientes[j].nombre,clientes[j+1].nombre)>0){
                temp=clientes[j];
                clientes[j]=clientes[j+1];
                clientes[j+1]=temp;
            }
        }
    }

    printf("Ordenado por Nombre\n");
    system("pause");
}

