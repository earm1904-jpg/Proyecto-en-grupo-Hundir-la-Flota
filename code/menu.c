#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*#include "ShowTablero.h"
#include "UbicarNaves.h"
#include "juego.h"
*/
int main()
{
  char ResMen;

  // menu de opciones
  do
  {
    printf("JUEGO HUNDIR LA FLOTA\n\n");
    printf("\nMenú de Opciones\n");
    printf("J para Jugar\n");
    printf("P para ver las mejores puntuaciones\n");
    printf("S Salir del juego\n");
    printf("Elige una opción: ");
    scanf(" %c", &ResMen);

    switch (tolower(ResMen))
    {
    case 'j':
    
    /*tablero tab;
    IniciarTablero(&tab);

    //Crando las naves y su puntos iniciales para posicinarlas en el tablero

    Naves Portaviones{'P',4};
     printf("Digita el primer punto inicial en la fila, para ubicar tu portaviones\n");
     scanf(" %c", &Portaviones.InicialFilas);
     printf("Digita el primer punto inicial en la columan, para ubicar tu portaviones\n");
     scanf(" %c", &Portaviones.InicialColum);
     printf("Digita la letra 'h' para horizontal y 'v' para vertical \n");
     scanf(" %c", &Portaviones.orientacion);
     printf("Digita 1 para idicar arriba o derecha o 0 para abajo o izquierda \n");
     scanf(" %c", &Portaviones.direction);


    Naves Crucero1{'C'};
    Naves Crucero2{};
    Naves Pratullero1{};
    Naves Pratullero2{};
    Naves Pratullero3{};
    */


    break;

case 's':
  exit(EXIT_SUCCESS);
  break;

case 'p':
  break;
default:
  printf("Opción no válida. Inténtalo de nuevo.\n");
  break;
}
}
while (tolower(ResMen) != 's')
  ;

return 0;
}