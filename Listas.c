#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void MostrarMenu();
void MostrarLista(bool Bandera);
void AgregarElemento();
void RemoverElemento();
void CrearListaDefault();
void InsertarElemento(char producto[15], int cantidad);

struct LIST
{
    char producto[15];
    int cantidad;
    struct LIST *next;
};

struct LIST *ListaCompras = NULL;

int main()
{

    MostrarMenu();

    return 0;
}

void MostrarMenu()
{

    int opc;

    do
    {
        printf("\n------------MENU LISTA DE COMPRAS---------\n");
        printf("\n1. Mostrar Lista de compras\n");
        printf("2. Agregar articulo\n");
        printf("3. Remover articulo\n");
        printf("4. Crear Lista de compras default\n");
        printf("5. Salir");
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    } while (opc < 1 || opc > 5);

    switch (opc)
    {
    case 1:
        MostrarLista(true);
        break;
    case 2:
        AgregarElemento();
        break;
    case 3:
        RemoverElemento();
        break;
    case 4:
        CrearListaDefault();
        break;

    default: 
        break;
    }
}

void MostrarLista(bool Bandera)
{

    struct LIST *item = ListaCompras;

    printf("\n--------------LISTA DE COMPRAS-----------------\n\n");

    for (int i = 1; item != NULL; i++)
    {

        printf("Articulo %d: %s \t Cantidad: %d\n", i, item->producto, item->cantidad);
        item = item->next;
    }

    if (Bandera)
        MostrarMenu();
}

void CrearListaDefault()
{

    char producto[15];

    strcpy(producto, "Shampoo");
    InsertarElemento(producto, 2);

    strcpy(producto, "Gelatina");
    InsertarElemento(producto, 4);

    strcpy(producto, "Jugo");
    InsertarElemento(producto, 3);

    printf("\n------------ARTICULOS DEFAULT ANADIDOS A LA LISTA-------------\n\n");

    MostrarMenu();
}

void AgregarElemento()
{

    char producto[15];
    int cantidad;

    printf("\nEscriba el nombre de su producto: ");
    scanf("%s", producto);
    printf("\nEscriba la cantidad: ");
    scanf("%d", &cantidad);

    InsertarElemento(producto, cantidad);

    MostrarMenu();
}

void InsertarElemento(char producto[15], int cantidad)
{

    struct LIST *articulo = malloc(1 * sizeof(struct LIST));

    strcpy(articulo->producto, producto);
    articulo->cantidad = cantidad;
    articulo->next = NULL;

    struct LIST *item = malloc(1 * sizeof(struct LIST));

    if (ListaCompras == NULL)
        ListaCompras = articulo;
    else
    {
        item = ListaCompras;
        bool agregado = false;

        while (agregado == false)
        {
            if (item->next == NULL)
            {
                item->next = articulo;
                agregado = true;
            }
            else
                item = item->next;
        }
    }

    printf("\n------------ARTICULO ANADIDO CON EXITO!-----------");

    articulo = NULL;
    free(articulo);
    item = NULL;
    free(item);
}

void RemoverElemento()
{

    MostrarLista(false);

    int opcion;
    printf("Escriba el numero del articulo que desea remover: ");
    scanf("%d", &opcion);

    if (opcion == 1 && ListaCompras != NULL)
        ListaCompras = ListaCompras->next;

    else
    {

        struct LIST *item = malloc(1 * sizeof(struct LIST));

        item = ListaCompras;

        for (int i = 1; item; i++)
        {

            if (i == opcion - 1)
            {
                if (item->next->next == NULL)
                    item->next == NULL;
                else
                    item->next = item->next->next;

                item = NULL;
                free(item);
            }

            if (item)
                item = item->next;
        }
    }

    printf("\n----------ARTICULO REMOVIDO CON EXITO!-------\n\n");
    MostrarMenu();
}