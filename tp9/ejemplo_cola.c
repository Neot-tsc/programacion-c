/*Ejemplo: Cargar una COLA con asignación dinámica de memoria
Funcionalidades:
a) Crear nodos dinámicamente con malloc
b) Validar que malloc no retorne NULL
c) Insertar elementos al final (enqueue)
d) Mostrar la cola
e) Liberar toda la memoria
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
} tnodo;

typedef tnodo *tptr;

/* Prototipos */
tptr crear_nodo(int);
void enqueue(tptr *, tptr *, tptr);
tptr dequeue(tptr *, tptr *);
void mostrar_cola(tptr);
void liberar_cola(tptr *);
void cargar_cola_dinamica(tptr *, tptr *);

int main(void)
{
    tptr inicio = NULL;
    tptr fin = NULL;

    printf("=== EJEMPLO: COLA CON ASIGNACION DINAMICA ===\n\n");

    /* Cargar la cola de forma interactiva */
    cargar_cola_dinamica(&inicio, &fin);

    /* Mostrar la cola */
    printf("\n--- Cola cargada ---\n");
    mostrar_cola(inicio);

    /* Demostración de dequeue */
    printf("\n--- Extrayendo elementos ---\n");
    tptr extraido;
    while ((extraido = dequeue(&inicio, &fin)) != NULL)
    {
        printf("extraidodo: %d\n", extraido->dato);
        free(extraido);
        extraido = NULL;
    }

    printf("\nCola despus de extraer todo:\n");
    mostrar_cola(inicio);

    /* Liberar memoria (debería estar vacía, pero lo hacemos por seguridad) */
    liberar_cola(&inicio);

    printf("\nMemoria liberada correctamente.\n");

    return 0;
}

/* Crear un nodo dinámico */
tptr crear_nodo(int valor)
{
    tptr nuevo;
    nuevo = (tptr)malloc(sizeof(tnodo));
    
    if (nuevo == NULL)
    {
        printf("Error: no se pudo asignar memoria para el nodo\n");
        exit(1);
    }

    nuevo->dato = valor;
    nuevo->sig = NULL;
    return nuevo;
}

/* Agregar elemento al final de la cola (FIFO) */
void enqueue(tptr *inicio, tptr *fin, tptr nuevo)
{
    if (nuevo == NULL)
    {
        printf("Error: intento de encolar un nodo NULL\n");
        return;
    }

    if (*inicio == NULL)
    {
        /* Cola vacía: el nuevo es inicio y fin */
        *inicio = nuevo;
        *fin = nuevo;
    }
    else
    {
        /* Agregar al final */
        (*fin)->sig = nuevo;
        *fin = nuevo;
    }
}

/* Extraer elemento del inicio de la cola */
tptr dequeue(tptr *inicio, tptr *fin)
{
    if (*inicio == NULL)
    {
        printf("Cola vaca, no hay elemento para extraer\n");
        return NULL;
    }

    tptr extraido = *inicio;
    *inicio = (*inicio)->sig;

    /* Si la cola quedó vacía, actualizar fin también */
    if (*inicio == NULL)
    {
        *fin = NULL;
    }

    extraido->sig = NULL;  /* Desconectar el nodo */
    return extraido;
}

/* Mostrar todos los elementos de la cola */
void mostrar_cola(tptr inicio)
{
    if (inicio == NULL)
    {
        printf("Cola vac\n");
        return;
    }

    printf("Cola: ");
    while (inicio != NULL)
    {
        printf("%d", inicio->dato);
        if (inicio->sig != NULL)
            printf(" -> ");
        inicio = inicio->sig;
    }
    printf("\n");
}

/* Liberar toda la memoria de la cola */
void liberar_cola(tptr *inicio)
{
    tptr aux;
    while (*inicio != NULL)
    {
        aux = *inicio;
        *inicio = (*inicio)->sig;
        free(aux);
        aux = NULL;
    }
}

/* Cargar cola de forma interactiva con asignación dinámica */
void cargar_cola_dinamica(tptr *inicio, tptr *fin)
{
    tptr nuevo;
    int valor;

    printf("Cargar elementos en la cola:\n");
    printf("(Ingresa 0 para terminar)\n\n");

    do
    {
        printf("Ingresa un nmero: ");
        
        /* Validar entrada */
        if (scanf("%d", &valor) != 1)
        {
            printf("Entrada invlida. Intenta de nuevo.\n");
            while (getchar() != '\n');  /* Limpiar buffer */
            continue;
        }

        if (valor != 0)
        {
            /* Crear nodo dinámicamente */
            nuevo = crear_nodo(valor);
            
            /* Encolarlo */
            enqueue(inicio, fin, nuevo);
            printf(" Agregado a la cola: %d\n", valor);
        }
    } while (valor != 0);

    printf("\nCarga terminada.\n");
}
