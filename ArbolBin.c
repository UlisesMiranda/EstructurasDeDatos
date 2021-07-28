#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void MostrarMenu();
void MostrarArbol();
void MostrarArbolInorden ();
void MostrarArbolPreorden ();
void MostrarArbolPostorden ();
void AgregarNodoArbol ();
void InsertarNodoArbol (int numero);
void BuscarNodoArbol();
void CrearArbolDefault();
void RemoverNodo ();
void BuscadorNodo (int numero, bool remover);


struct ARBOLBIN {
    int numero;
    struct ARBOLBIN *Left;
    struct ARBOLBIN *Right;
};

struct ARBOLBIN *tree = NULL;

int main () {
    MostrarMenu ();
    printf ("ADIOS");
    return 0;
}

void MostrarMenu()
{
    int opc;
    do
    {
        printf("\n------------CONTROL DE ARBOL---------\n");
        printf("\n1. Mostrar Arbol\n");
        printf("2. Agregar nodo\n");
        printf("3. Buscar Nodo\n");
        printf("4. Crear Arbol Default\n");
        printf("5. Remover Nodo\n");
        printf("6. SALIR\n");       
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    } while (opc < 1 || opc > 6);

    switch (opc)
    {
    case 1:
        MostrarArbol();
        break;
    case 2:
        AgregarNodoArbol();
        break;
    case 3:
        BuscarNodoArbol();
        break;
    case 4:
        CrearArbolDefault();
        break;
    case 5:
        RemoverNodo ();
    default:
        break;
    }
}

void AgregarNodoArbol () {
    
    int num;

    printf ("Escriba su numero: ");
    scanf ("%d", &num);

    InsertarNodoArbol (num);

    MostrarMenu();
}

void InsertarNodoArbol (int num) {

    struct ARBOLBIN *Nodo = malloc (1 * sizeof (struct ARBOLBIN));

    Nodo->numero = num;
    Nodo->Left = NULL;
    Nodo->Right = NULL;

    if (tree == NULL) 
        tree = Nodo;
    else {
        struct ARBOLBIN *aux = tree;
        struct ARBOLBIN *prev;

        while (aux)
        {
            prev = aux;

            if (num < aux->numero) 
                aux = aux->Left;
            else 
                aux= aux->Right;
        }

        if (num < prev->numero)
            prev->Left = Nodo;
        else 
            prev->Right = Nodo;
        
    }
}

void CrearArbolDefault () {
    InsertarNodoArbol (5);
    InsertarNodoArbol (4);
    InsertarNodoArbol (9);
    InsertarNodoArbol (-2);
    InsertarNodoArbol (8);
    InsertarNodoArbol (0);
    InsertarNodoArbol (3);
    InsertarNodoArbol (6);

    MostrarMenu();
}

void MostrarArbol () {
    int opc;
    
    do {
        printf("\n------------Muestreo Arbol---------\n");
        printf("\n1. InOrden\n");
        printf("2. PreOrden\n");
        printf("3. PostOrden\n");
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    } while (opc < 1 || opc > 3);

    switch (opc)
    {
    case 1:
        MostrarArbolInorden(tree);
        MostrarMenu();
        break;
    case 2:
        MostrarArbolPreorden (tree);
        MostrarMenu();
        break;
    case 3:
        MostrarArbolPostorden (tree);
        MostrarMenu();
        break;
    
    default:
        break;
    }
}

void MostrarArbolInorden (struct ARBOLBIN *aux) {
    
    if (aux) {
        MostrarArbolInorden (aux->Left);
        printf ("%d\t", aux->numero);
        MostrarArbolInorden (aux->Right);
    }
    
}
void MostrarArbolPreorden (struct ARBOLBIN *aux) {

    if (aux) {
        printf ("%d\t", aux->numero);
        MostrarArbolPreorden (aux->Left);
        MostrarArbolPreorden (aux->Right);
    }

}
void MostrarArbolPostorden (struct ARBOLBIN *aux){
    if (aux) {
        MostrarArbolPostorden (aux->Left);
        MostrarArbolPostorden (aux->Right);
        printf ("%d\t", aux->numero);
    }

}

void BuscarNodoArbol () {

    int numero; 
    printf ("\nQue numero desea buscar?: ");
    scanf("%d", &numero);

    BuscadorNodo(numero, false);
}

void RemoverNodo () {

    int numero;
    printf ("\nQue numero desea remover del arbol?: ");
    scanf("%d", &numero);

    BuscadorNodo(numero, true);
}

void BuscadorNodo (int numero, bool remover) {

    int contador;

    struct ARBOLBIN *busqueda = tree;
    struct ARBOLBIN *previo = NULL;

    for ( contador = 1; busqueda; contador++)
    {
        if (numero == busqueda->numero)
            break;
        else 
            previo = busqueda;

        if (numero < busqueda->numero ) 
            busqueda = busqueda->Left;
        
        else 
            busqueda = busqueda->Right;
        
    }

    if (busqueda == NULL)
        printf ("\nEl Nodo no fue encontrado");
    
    else if (!remover)
        printf ("\nEl Nodo fue encontrado tras %d movimientos", contador);
    
    else if (remover)
        EliminarNodo(busqueda, previo);
    
    MostrarMenu(); 
    
}

void EliminarNodo (struct ARBOLBIN *aux, struct ARBOLBIN *previo) {
    
    
    if (aux) { 
        EliminarNodo (aux->Left, aux);
        EliminarNodo (aux->Right, aux);
        
        printf ("Nodo eliminado: %d", aux->numero);
        
        if (previo) {
            if (aux->numero < previo)
                previo->Left = NULL;
            else
                previo->Right = NULL;
        }

        if (aux == tree)
            tree = NULL;

        free (aux);
    }
}