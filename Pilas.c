#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MostrarMenu();
void MostrarPila (); 
void AgregarElementosPila ();
void RemoverElementoPila();

struct PILA
{
    int noserie;
    struct PILA *next; 
};

struct PILA *producto = NULL;


int main () {

    MostrarMenu();

    return 0;
}

void MostrarMenu()
{
    int opc;
    do
    {
        printf("\n------------CONTROL DE STOCK---------\n");
        printf("\n1. Mostrar STOCK\n");
        printf("2. Agregar unidades\n");
        printf("3. Remover unidad\n");
        printf("4. Salir");
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    } while (opc < 1 || opc > 4);

    switch (opc)
    {
    case 1:
        MostrarPila();
        break;
    case 2:
        AgregarElementosPila();
        break;
    case 3:
        RemoverElementoPila();
        break;

    default:
        break;
    }
}

void AgregarElementosPila () {

    srand(time(NULL));
    
    int cantidad;

    printf ("\nCuantos elementos desea: ");
    scanf ("%d", &cantidad);

    for (size_t i = 0; i < cantidad; i++)
    {
        struct PILA *unidad = malloc (1 * sizeof(struct PILA));

        int num =  (rand() % (1000 - 1 + 1)) + 1; //(max - min +1) + min
        unidad->noserie = num;

        if (producto == NULL) {
            producto = unidad;
            unidad->next = NULL;
        }
        else {
            unidad->next = producto;
            producto = unidad;
        }

        unidad = NULL;
        free (unidad);

    }  
 
    MostrarMenu ();
}

void MostrarPila () {

    printf ("\nProductos en STOCK\n\n");

    struct PILA *aux;

    aux = producto;

    if (aux == NULL) {
        printf ("No hay stock\n");
        MostrarMenu();
    }

    int cantidad = 1;
    while (aux) {
        printf ("%d. Numero de serie: %d\n", cantidad, aux->noserie);
        aux = aux->next;
        cantidad++;
    }
    MostrarMenu();
}

void RemoverElementoPila() {

    int cantidad;

    printf ("\nCuantos prodcutos deseas remover de STOCK ?: ");
    scanf ("%d", &cantidad);

    struct PILA *aux = producto;

    for (size_t i = 0; i < cantidad; i++)
    {
        if (aux = NULL) {
            printf ("\nEl stock esta vacio\n");
            MostrarMenu ();
        }
        else {
            producto = producto->next;
            free (aux);
            aux = producto;
        }
    }
    MostrarMenu ();
}

