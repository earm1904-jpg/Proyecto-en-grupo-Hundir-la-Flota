#include <stdio.h>
#include "juego.h"
#include "Validar_ubicacion_barco.h"
//hola
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

void UbicarNavesPlayer(tablero *tab, Naves *Nav)
{
    int n,i,j;
    //TotNavs=6 Variable global total de naves
    
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

            while(Nav->CantidadNAvs!=0){

                printf("Digita las coordenas para ubicar tu barco, recueda que son números enter cero y once\n");
                printf("Digita la coordenada de las filas\n");
                scanf(" %c", &Nav->InicialFilas);
                printf("Digita la coordenada de las columnas\n");
                scanf(" %c", &Nav->InicialColum);

            if (Nav->ParteBarco==1|| Nav->ParteBarco==0 )//PROA 1 / 0 POPA
            {
                 printf("¿En qué horientación vas a ubicar el barco?\n");
                 printf("H Horizontal\n");
                 printf("V Vertical\n");
                 scanf(" %c", &Nav->orientacion);
                 if(Nav->orientacion=='H'||Nav->orientacion=='V'){
                    if(FueradelMapa(Nav)==0){

                        if(BarcoAdyacente(tab, Nav)==0){
                            UbicarBarco(tab, Nav);
                             Nav->CantidadNAvs=Nav->CantidadNAvs-1;
                             TotNavs=TotNavs-1;
                        }
                        
                    }
                    

                 }

            }
            
        }
        
        //printf("Ya no tienes más Portaviones\n");

        }
        //----Cruceros-----///
        if(Nav->nombarco=='C'){
            Nav->tamNave=3;
            Nav->CantidadNAvs=2;

            while(Nav->CantidadNAvs!=0){

                printf("Digita las coordenas para ubicar tu barco, recueda que son números enter cero y once\n");
                printf("Digita la coordenada de las filas\n");
                scanf(" %c", &Nav->InicialFilas);
                printf("Digita la coordenada de las columnas\n");
                scanf(" %c", &Nav->InicialColum);

                if (Nav->ParteBarco==1|| Nav->ParteBarco==0 )//PROA 1 / 0 POPA
                {
                 printf("¿En qué horientación vas a ubicar el barco?\n");
                 printf("H Horizontal\n");
                 printf("V Vertical\n");
                 scanf(" %c", &Nav->orientacion);
                 if(Nav->orientacion=='H'||Nav->orientacion=='V'){
                    if(FueradelMapa(Nav)==0){

                        if(BarcoAdyacente(tab, Nav)==0){
                            UbicarBarco(tab, Nav);
                            Nav->CantidadNAvs=Nav->CantidadNAvs-1;
                             TotNavs=TotNavs-1;
                        }
                        
                    }
                    

                 }

            }


            }

        }


        //----Pratrulleros-----///
        if(Nav->nombarco=='T'){

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


