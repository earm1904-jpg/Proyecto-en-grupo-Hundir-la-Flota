#include <stdio.h>
#include "juego.h"
#include "Validar_ubicacion_barco.h"

// Rellenando el tablero con la letra '.' vacio
void IniciarTableros(tablero *tab)
{
    for (int i = 0; i < TAM_TABLERO; i++)
{

    for (int j = 0; j < TAM_TABLERO; j++)
    {
       tab->espacio[i][j] = AGUA; // ->Esto indica que es un paso por referencia: la dirección de memoria de la variable original, no una copia.
    }
}

}

void UbicarNavesPlayer(Naves *Nav)
{
    int n,i,j,TotNavs;
    TotNavs=6;// total de naves
    //char nombarco; //guardar el nombre del barco
    
    while(TotNavs!=0){ //Una vez ubique todas las naves se saldrá del bucle
    
    printf("¿Cómo quieres ubicar el barco, desde Proa  o Popa?\n");
    printf("1) Proa\n");
    printf("0) Popa\n");
    scanf(" %c", &Nav->ParteBarco);
    
    printf("¿Cuál barco quieres ubicar?\n");
    printf("P Portaviones\n");
    printf("C Cruceros\n");
    printf("T Patrullero\n");
    scanf(" %c", &Nav->nombarco);

    //----Portaviones-----///
    if (Nav->nombarco=='P'){ 
        Nav->tamNave=4;
        Nav->CantidadNAvs=1;
        if(Nav->CantidadNAvs==1){
            if (Nav->ParteBarco==1|| Nav->ParteBarco==0 )//PROA 1 / 0 POPA
            {
                 printf("¿En qué horientación vas a ubicar el barco?\n");
                 printf("H Horizontal\n");
                 printf("V Vertical\n");
                 scanf(" %c", &Nav->orientacion);
                 if(Nav->orientacion=='H'){

                 }

            }
            
        }
        else{
            printf("Ya no tienes más Portaviones\n");

        }
    
        }
        //----Cruceros-----///
        if(nombarco=='C'){

        }


        //----Pratrulleros-----///
        if(nombarco=='T'){

        }
        printf("\nElige una opción valida");

    }


    printf("Digita el primer punto inicial en la fila, para ubicar tu portaviones\n");
     scanf(" %c", &Portaviones.InicialFilas);    

    printf("Digita el primer punto inicial en la fila, para ubicar tu portaviones\n");
     scanf(" %c", &Portaviones.InicialFilas);
     printf("Digita el primer punto inicial en la columan, para ubicar tu portaviones\n");
     scanf(" %c", &Portaviones.InicialColum);
     printf("Digita la letra 'h' para horizontal y 'v' para vertical \n");
     scanf(" %c", &Portaviones.orientacion);
     printf("Digita 1 para indicar arriba o derecha o 0 para abajo o izquierda \n");
     scanf(" %c", &Portaviones.direction);


    if(n>=0||n<TAM_TABLERO){
    if(Nav.orientacion=='v'){ //  Vertical
        if (Nav.direction==1) //indica UP
        {
            for(){
            
                }
        }
        
    }
    return 1;
 }

}

/*Naves navs = {







    

    // Inicializando los vectores que corresponden a cada nave para identificarlos en el tablero
    // inicializando el Portaviones
  /  for (int i = 0; i < 4; i++) // para el vector de portaviones será una 'P'
    {
        .portaviones[i] = 'P';
}
// inicializando los cruceros

for (int i = 0; i < 3; i++) // para los vectores de crucero será una 'C'
{
    .crucero1.crucero[i] = 'C';
    .crucero2.crucero[i] = 'C';
}

// inicializando los Patrulleros

for (int i = 0; i < 4; i++) // para los vectores de patrulleros será una 'T'
{
    .patrullero1.patrullero[i] = 'T';
    .patrullero2.patrullero[i] = 'T';
    .patrullero3.patrullero[i] = 'T';
}

// Incialización de las coordenadas inicilaes para cada nave

// Portaviones
.InicialPorta[0] = 2;
.InicialPorta[1] = 4;

// Crucero 1 y 2
.crucero1.IncialCrucero[0] = 0;
.crucero1.IncialCrucero[1] = 0;
.crucero2.IncialCrucero[0] = 8;
.crucero2.IncialCrucero[1] = 3;

// Patrulleros 1, 2 y 3

.patrullero1.IncialPatru[0] = 1;
.patrullero1.IncialPatru[1] = 8;
.patrullero2.IncialPatru[0] = 4;
.patrullero2.IncialPatru[1] = 10;
.patrullero3.IncialPatru[0] = 6;
.patrullero3.IncialPatru[1] = 6;

}*/
//}
