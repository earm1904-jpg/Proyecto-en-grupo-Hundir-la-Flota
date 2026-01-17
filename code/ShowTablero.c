#include <stdio.h>
#include "juego.h"
//#include "UbicarNaves.h"
#include "ShowTablero.h"
#define RED "\x1b[31m"
#define MAGENTA "\x1b[35m"
#define BLUE "\x1b[34m"
#define CIAM "\x1b[36m"
#define RESET "\x1b[0m"

void ShowTablero(tablero tab)
{

    // Encabezado de columnas
    printf("      ");
    for (int j = 0; j < TAM_TABLERO; j++)
    {
        printf("%3d   ", j); //%3d e número 3 indica el ancho de caracteres que debe ocupar el número (d)
    }
    printf("\n");

    for (int i = 0; i < TAM_TABLERO; i++)
    {

        // Línea superior de la fila
        printf("    ");
        for (int j = 0; j < TAM_TABLERO; j++)
            printf("+-----");
        printf("+\n");

        // Coordenada de la fila
        printf("%3d ", i);

        // Imprimir contenido de la matriz
        for (int j = 0; j < TAM_TABLERO; j++)
            printf("|%s  %c  %s", CIAM, tab.espacio[i][j], RESET);
        printf("|\n");
    }

    // Línea inferior final
    printf("    ");
    for (int j = 0; j < TAM_TABLERO; j++)
        printf("+-----");
    printf("+\n");
}


