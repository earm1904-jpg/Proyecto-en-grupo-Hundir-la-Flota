#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Validar_ubicacion_barco.h"
#include "ShowTablero.h"
#include "juego.h"
#include "turno.h"

int main()
{
  srand(time(NULL));
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
    tablero TabDisparosPC; // Se crea el tablero de disparos del PC

    //Inicialziación de los tablero con la letra "A" Agua
    IniciarTableros(&TabPlayer); 
    IniciarTableros(&TabContr);
    IniciarTableros(&TabDisparosPlayer); 
    IniciarTableros(&TabDisparosPC); 

      printf("----------INICIEMOS EL JUEGO------------ \n\n");
    printf("Debes ubicar 6 anves:\nUn Portaviones de cuatro posiciones,\nDos Cruceros de tres posiciones cada uno\ny Tres Patrulleros de dos posiciones cada uno.\nEl tablero cuenta con numeros que van del 0 al 11.\nCon estos numeros te puedes guiar para dar la ubicacion de tus naves\n\n");
    printf("Recuerda que los barcos tiene cuatro direcciones principales:\n LA PROA (Delante)\n LA POPA (Atrás)\n BABOR (Izquierda)\n ESTRIBOR (Derecha) \n\n");
    ShowTablero(TabPlayer);
    //Creando las naves Player y asignado nombarco y tamNave;
    Naves Portaviones={'P',4};
    Naves Crucero1={'C',3};
    Naves Crucero2={'C',3};
    Naves Pratullero1={'T',2};
    Naves Pratullero2={'T',2};
    Naves Pratullero3={'T',2};

    //Creando las naves PC y asignado nombarco y tamNave;
    Naves PortavionesPC={'P',4};
    Naves Crucero1PC={'C',3};
    Naves Crucero2PC={'C',3};
    Naves Pratullero1PC={'T',2};
    Naves Pratullero2PC={'T',2};
    Naves Pratullero3PC={'T',2};

    //Ubicando cada nave del Player en el tablero TabPlayer
    UbicarNavesPlayer(&TabPlayer,&Portaviones);
    UbicarNavesPlayer(&TabPlayer,&Crucero1);
    UbicarNavesPlayer(&TabPlayer,&Crucero2);
    UbicarNavesPlayer(&TabPlayer,&Pratullero1);
    UbicarNavesPlayer(&TabPlayer,&Pratullero2);
    UbicarNavesPlayer(&TabPlayer,&Pratullero3);

    //Ubicando cada nave del PC en el tablero  TabContr
    UbicarNavesPC(&TabContr, &PortavionesPC);
    UbicarNavesPC(&TabContr, &Crucero1PC);
    UbicarNavesPC(&TabContr, &Crucero2PC);
    UbicarNavesPC(&TabContr, &Pratullero1PC);
    UbicarNavesPC(&TabContr, &Pratullero2PC);
    UbicarNavesPC(&TabContr, &Pratullero3PC);
    
    
    
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
