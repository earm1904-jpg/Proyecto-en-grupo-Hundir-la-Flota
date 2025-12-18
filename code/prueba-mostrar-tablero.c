#include <stdio.h>
//**se utiliza para formatear el texto con colores */
#define RED "\x1b[31m" 
#define MAGENTA "\x1b[35m"
#define BLUE "\x1b[34m"
#define CIAM "\x1b[36m"
#define RESET "\x1b[0m"

int main()
{
  int filas = 12;
    int columnas = 12;
    char tab[12][12];
 
    //**Se inicializa el tablero con '.' que indican el agua */
    for(int i = 0; i < filas; i++){

        for(int j = 0; j < columnas; j++)
        {
        tab[i][j]='.';
        }
    }



 // Imprimir tablero y naves
    // Encabezado de columnas
    printf("      ");
    for (int j = 0; j < columnas; j++)
    {
        printf("%3d   ", j); //%3d e número 3 indica el ancho de caracteres que debe ocupar el número (d)
    }
    printf("\n");

    for (int i = 0; i < filas; i++)
    {

        // Línea superior de la fila
        printf("    ");
        for (int j = 0; j < columnas; j++)
            printf("+-----");
        printf("+\n");

        // Coordenada de la fila
        printf("%3d ", i);

        // Imprimir contenido de la matriz
        for (int j = 0; j < columnas; j++)

        /*Acá se le pone el formato de color al contenido del tablero*/
            printf("|%s  %c  %s", CIAM, tab[i][j], RESET); 
        printf("|\n");
    }

    // Línea inferior final
    printf("    ");
    for (int j = 0; j < columnas; j++)
        printf("+-----");
    printf("+\n");
}