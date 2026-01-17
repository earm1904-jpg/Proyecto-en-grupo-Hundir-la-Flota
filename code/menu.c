#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "Validar_ubicacion_barco.h"
#include "ShowTablero.h"
//#include "UbicarNaves.h"
#include "juego.h"

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
    printf("\nElige una opción:");
    scanf(" %c", &ResMen);

    switch (tolower(ResMen))
    {
    case 'j':
    tablero TabPlayer; //Se crea el tablero del jugador
    tablero TabDisparosPlayer;// Es el tablero de visualización de los disparo hechos por el jugador
    tablero TabContr; // Se crea el tablero del contrincante

    //Inicialziación de los tablero con la letra "A" Agua
    IniciarTableros(&TabPlayer); 
    IniciarTableros(&TabContr);
    IniciarTableros(&TabDisparosPlayer); 
      printf("----------INICIEMOS EL JUEGO------------ \n\n");
    printf("Debes ubicar 6 anves:\nUn Portaviones de cuatro posiciones,\nDos Cruceros de tres posiciones cada uno\ny Tres Patrulleros de dos posiciones cada uno.\nEl tablero cuenta con numeros que van del 0 al 11.\nCon estos numeros te puedes guiar para dar la ubicacion de tus naves\n\n");
    printf("Recuerda que los barcos tiene cuatro direcciones principales:\n LA PROA (Delante)\n LA POPA (Atrás)\n BABOR (Izquierda)\n ESTRIBOR (Derecha) \n\n");
    ShowTablero(TabPlayer);
    //Crando las naves y su puntos iniciales para posicinarlas en el tablero

    Naves Portaviones{'P',4};
     /*printf("Digita el primer punto inicial en la fila, para ubicar tu portaviones\n");
     scanf(" %c", &Portaviones.InicialFilas);
     printf("Digita el primer punto inicial en la columan, para ubicar tu portaviones\n");
     scanf(" %c", &Portaviones.InicialColum);
     printf("Digita la letra 'h' para horizontal y 'v' para vertical \n");
     scanf(" %c", &Portaviones.orientacion);
     printf("Digita 1 para indicar arriba o derecha o 0 para abajo o izquierda \n");
     scanf(" %c", &Portaviones.direction);
    */

    Naves Crucero1{'C',3};
    Naves Crucero2{'C',3};
    Naves Pratullero1{'T',2};
    Naves Pratullero2{'T',2};
    Naves Pratullero3{'T',2};
    
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