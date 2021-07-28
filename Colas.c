#include <stdio.h>
#include <stdlib.h>

void MostrarMenu ();
void MostrarCola();
void AgregarElementoCola();
void RemoverElementoCola();

struct COLA
{
    char nombre[50];
    struct COLA *prev;
};

struct COLA *CuentaCobro = NULL;

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
        printf("\n------------CONTROL DE COLA---------\n");
        printf("\n1. Mostrar Cola\n");
        printf("2. Agregar cliente a la cola\n");
        printf("3. Remover cliente atendido\n");
        printf("4. Salir");
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    } while (opc < 1 || opc > 4);

    switch (opc)
    {
    case 1:
        MostrarCola();
        break;
    case 2:
        AgregarElementoCola();
        break;
    case 3:
        RemoverElementoCola();
        break;

    default:
        break;
    }
}

void MostrarCola()
{

    printf("\nCLIENTES EN LA COLA:\n\n");

    struct COLA *aux = CuentaCobro;

    for (int i = 1; aux; i++)
    {
        printf("Posicion: %d\t Nombre: %s\n", i, aux->nombre);
        aux = aux->prev;
    }

    MostrarMenu();
}

void AgregarElementoCola()
{

    struct COLA cliente;

    printf("Escriba el nombre del nuevo cliente: ");
    scanf("%s", &cliente.nombre);
    cliente.prev = NULL;

    if (CuentaCobro == NULL)
        CuentaCobro = &cliente;
    else
    {
        struct COLA *aux = CuentaCobro;

        while (aux->prev != NULL)
            aux = aux->prev;

        aux->prev = &cliente;
    }

    MostrarMenu();
}

void RemoverElementoCola()
{
    if (CuentaCobro)
    {
        printf("El cliente %s ha sido atendido", CuentaCobro->nombre);

        struct COLA *aux = malloc(1 * sizeof(struct COLA));
        aux = CuentaCobro;

        CuentaCobro = CuentaCobro->prev;

        aux->prev = NULL;
        aux = NULL;

        free(aux);
    }

    MostrarMenu();
}
